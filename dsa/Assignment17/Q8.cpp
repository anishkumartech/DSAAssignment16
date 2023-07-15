#include <iostream>
#include <queue>

class DataStream {
private:
    std::queue<int> stream;
    int value;
    int k;

public:
    DataStream(int value, int k) : value(value), k(k) {}

    bool consec(int num) {
        stream.push(num);
        if (stream.size() < k) {
            return false;
        } else if (stream.size() == k) {
            bool allEqual = true;
            int first = stream.front();
            for (int i = 1; i < k; i++) {
                int current = stream.front();
                stream.pop();
                if (current != value) {
                    allEqual = false;
                }
                stream.push(current);
            }
            return allEqual;
        } else {
            stream.pop();
            return false;
        }
    }
};

int main() {
    DataStream dataStream(4, 3);
    std::cout << std::boolalpha << dataStream.consec(4) << std::endl;
    std::cout << std::boolalpha << dataStream.consec(4) << std::endl;
    std::cout << std::boolalpha << dataStream.consec(4) << std::endl;
    std::cout << std::boolalpha << dataStream.consec(3) << std::endl;

    return 0;
}
