#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

int findTheWinner(int n, int k) {
    ListNode* head = new ListNode(1);
    ListNode* current = head;

    // Create the circular linked list
    for (int i = 2; i <= n; i++) {
        current->next = new ListNode(i);
        current = current->next;
    }
    current->next = head; // Connect the last friend to the first friend

    // Simulate the game
    while (current->next != current) {
        for (int i = 1; i < k; i++) {
            current = current->next;
        }
        // Remove the kth friend
        ListNode* temp = current->next;
        current->next = temp->next;
        delete temp;
    }

    int winner = current->val;
    delete current;
    return winner;
}

int main() {
    int n1 = 5;
    int k1 = 2;
    int winner1 = findTheWinner(n1, k1);
    std::cout << "Winner: " << winner1 << std::endl;

    int n2 = 6;
    int k2 = 5;
    int winner2 = findTheWinner(n2, k2);
    std::cout << "Winner: " << winner2 << std::endl;

    return 0;
}

