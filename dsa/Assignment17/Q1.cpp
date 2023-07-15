#include <iostream>
#include <unordered_map>

int firstNonRepeatingCharacter(const std::string& s) {
    std::unordered_map<char, int> charFreq;

    // Step 1: Count the frequency of each character
    for (char c : s) {
        charFreq[c]++;
    }

    // Step 2: Find the first non-repeating character
    for (int i = 0; i < s.length(); i++) {
        if (charFreq[s[i]] == 1) {
            return i;
        }
    }

    return -1;
}

int main() {
    std::string s1 = "loveleetcode";
    int index1 = firstNonRepeatingCharacter(s1);
    std::cout << "First non-repeating character index: " << index1 << std::endl;

    std::string s2 = "aabb";
    int index2 = firstNonRepeatingCharacter(s2);
    std::cout << "First non-repeating character index: " << index2 << std::endl;

    return 0;
}

