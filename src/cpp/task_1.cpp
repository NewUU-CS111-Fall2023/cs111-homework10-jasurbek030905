#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};
ListNode* mergeNodes(ListNode* start, ListNode* end) {
    int sum = 0;
    ListNode* current = start;
    while (current != end) {
        sum += current->val;
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }
    return new ListNode(sum);
}
ListNode* mergeLinkedList(ListNode* head) {
    ListNode dummy(0); 
    dummy.next = head;
    ListNode* current = &dummy;
    while (current->next) {
        if (current->next->val == 0) {
            ListNode* start = current->next;
            ListNode* end = start->next;
            while (end && end->val != 0) {
                end = end->next;
            }
            current->next = mergeNodes(start, end);
            current->next->next = end;
        }
        current = current->next;
    }
    return dummy.next;
}
void printLinkedList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
int task_1 () {
    ListNode* head = new ListNode(0);
    head->next = new ListNode(3);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(0);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next->next->next = new ListNode(0);
    cout << "Original Linked List: ";
    printLinkedList(head);
    ListNode* modifiedList = mergeLinkedList(head);
    cout << "Modified Linked List: ";
    printLinkedList(modifiedList);
    while (modifiedList) {
        ListNode* temp = modifiedList;
        modifiedList = modifiedList->next;
        delete temp;
    }
    return 0;
}
