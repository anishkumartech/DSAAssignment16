#include <iostream>
#include <vector>
#include <queue>

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) {}
};

struct Compare {
    bool operator()(const ListNode* a, const ListNode* b) const {
        return a->val > b->val;
    }
};

ListNode* mergeKLists(std::vector<ListNode*>& lists) {
    // Create a min-heap with custom comparator
    std::priority_queue<ListNode*, std::vector<ListNode*>, Compare> minHeap;

    // Push the head of each linked list into the min-heap
    for (ListNode* head : lists) {
        if (head) {
            minHeap.push(head);
        }
    }

    // Create a dummy node to build the merged list
    ListNode dummy(0);
    ListNode* tail = &dummy;

    // Merge the linked lists
    while (!minHeap.empty()) {
        ListNode* curr = minHeap.top();
        minHeap.pop();

        tail->next = curr;
        tail = tail->next;

        if (curr->next) {
            minHeap.push(curr->next);
        }
    }

    return dummy.next;
}

// Helper function to create a linked list from a vector
ListNode* createLinkedList(const std::vector<int>& values) {
    ListNode dummy(0);
    ListNode* tail = &dummy;

    for (int val : values) {
        tail->next = new ListNode(val);
        tail = tail->next;
    }

    return dummy.next;
}

// Helper function to print a linked list
void printLinkedList(ListNode* head) {
    while (head) {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main() {
    // Example usage
    std::vector<ListNode*> lists;
    lists.push_back(createLinkedList({1, 4, 5}));
    lists.push_back(createLinkedList({1, 3, 4}));
    lists.push_back(createLinkedList({2, 6}));

    ListNode* mergedList = mergeKLists(lists);
    printLinkedList(mergedList);

    // Clean up the memory
    while (mergedList) {
        ListNode* temp = mergedList;
        mergedList = mergedList->next;
        delete temp;
    }

    return 0;
}
