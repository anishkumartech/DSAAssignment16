#include <iostream>
#include <stack>
#include <string>
#include <sstream>

int countWordsLeft(const std::string& sequence) {
    std::stack<std::string> stack;
    std::stringstream ss(sequence);
    std::string word;
    int count = 0;

    while (ss >> word) {
        if (!stack.empty() && stack.top() == word) {
            stack.pop();
        } else {
            stack.push(word);
        }
    }

    return stack.size();
}

int main() {
    std::string sequence1 = "ab aa aa bcd ab";
    int wordsLeft1 = countWordsLeft(sequence1);
    std::cout << "Number of words left: " << wordsLeft1 << std::endl;

    std::string sequence2 = "tom jerry jerry tom";
    int wordsLeft2 = countWordsLeft(sequence2);
    std::cout << "Number of words left: " << wordsLeft2 << std::endl;

    return 0;
}

