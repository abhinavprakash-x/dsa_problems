/*
Run Time: 3ms
Beats: 34.04 %ile
Time Complexity: O(max(m,n))

Memory Usage: 77.34MB
Beats: 13.42 %ile
Space Complexity: O(max(m,n))
*/
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode result(0);
        ListNode* ptr3 = &result;
        int carry = 0;

        while (l1 || l2 || carry) {
            int x = (l1 ? l1->val : 0);
            int y = (l2 ? l2->val : 0);
            int sum = x + y + carry;
            carry = sum / 10;

            ptr3->next = new ListNode(sum % 10);
            ptr3 = ptr3->next;

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        return result.next;
    }
};

void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

ListNode* createList(int arr[], int n) {
    ListNode* dummy = new ListNode(0);
    ListNode* curr = dummy;
    for (int i = 0; i < n; i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return dummy->next;
}

int main() {
    // Example: (2 -> 4 -> 3) + (5 -> 6 -> 4) = 7 -> 0 -> 8
    int arr1[] = {2, 4, 3};
    int arr2[] = {5, 6, 4};

    ListNode* l1 = createList(arr1, 3);
    ListNode* l2 = createList(arr2, 3);

    Solution sol;
    ListNode* result = sol.addTwoNumbers(l1, l2);

    cout << "Result: ";
    printList(result);

    return 0;
}