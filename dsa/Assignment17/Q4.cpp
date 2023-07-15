#include <iostream>
#include <queue>

class RecentCounter {
private:
    std::queue<int> requests;

public:
    RecentCounter() {
    }

    int ping(int t) {
        requests.push(t);

        while (!requests.empty() && requests.front() < t - 3000) {
            requests.pop();
        }

        return requests.size();
    }
};

int main() {
    RecentCounter recentCounter;

    std::cout << recentCounter.ping(1) << std::endl;     // Output: 1
    std::cout << recentCounter.ping(100) << std::endl;   // Output: 2
    std::cout << recentCounter.ping(3001) << std::endl;  // Output: 3
    std::cout << recentCounter.ping(3002) << std::endl;  // Output: 3

    return 0;
}

