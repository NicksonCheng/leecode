#include <math.h>

#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef struct ListNode {
    /* data */
    int val;
    ListNode* next;
} ListNode;
class Solution {
   public:
    void append(ListNode** head, int data) {
        ListNode* last = *head;
        ListNode* new_node = new ListNode();
        new_node->val = data;
        new_node->next = NULL;
        if (*head == NULL) {
            *head = new_node;
            return;
        }
        while (last->next != NULL) last = last->next;
        last->next = new_node;
        return;
    }
    void printNode(ListNode* node) {
        while (node != NULL) {
            cout << node->val << " ";
            node = node->next;
        }
        cout << endl;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res_node = NULL;
        vector<int> node;
        int carry = 0;
        while (l1 != NULL || l2 != NULL) {
            /* code */
            int v1 = 0, v2 = 0;
            if (l1 != NULL) {
                v1 = l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                v2 = l2->val;
                l2 = l2->next;
            }
            int sum = v1 + v2 + carry;
            carry = 0;
            node.push_back(sum % 10);
            if (sum >= 10) {
                carry = sum / 10;
            }
        }
        // last carry
        if (carry > 0) node.push_back(carry);
        for (int i = 0; i < node.size(); ++i) append(&res_node, node[i]);
        printNode(res_node);
        return res_node;
    }
};

int main(int argc, char const* argv[]) {
    /* code */
    Solution solution;
    ListNode* list1 = NULL;
    ListNode* list2 = NULL;
    string str1, str2;
    cin >> str1 >> str2;
    for (int i = str1.length() - 1; i >= 0; --i) {
        solution.append(&list1, str1[i] - '0');
    }

    for (int i = str2.length() - 1; i >= 0; --i) solution.append(&list2, str2[i] - '0');
    // solution.printNode(list1);
    solution.addTwoNumbers(list1, list2);
}
