#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

std::vector<int> revealCardsInIncreasingOrder(std::vector<int>& deck) {
    std::sort(deck.begin(), deck.end(), std::greater<int>());

    std::queue<int> cardQueue;
    for (int card : deck) {
        cardQueue.push(card);
    }

    std::vector<int> result;
    while (!cardQueue.empty()) {
        result.push_back(cardQueue.front());
        cardQueue.pop();
        if (!cardQueue.empty()) {
            cardQueue.push(cardQueue.front());
            cardQueue.pop();
        }
    }

    return result;
}

int main() {
    std::vector<int> deck1 = {17, 13, 11, 2, 3, 5, 7};
    std::vector<int> result1 = revealCardsInIncreasingOrder(deck1);
    std::cout << "Revealed Cards: ";
    for (int card : result1) {
        std::cout << card << " ";
    }
    std::cout << std::endl;

    std::vector<int> deck2 = {1, 1000};
    std::vector<int> result2 = revealCardsInIncreasingOrder(deck2);
    std::cout << "Revealed Cards: ";
    for (int card : result2) {
        std::cout << card << " ";
    }
    std::cout << std::endl;

    return 0;
}

