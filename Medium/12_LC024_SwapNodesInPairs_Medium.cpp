
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

        if (head == NULL || head->next == NULL)
            return head;

        ListNode* first = head;
        ListNode* second = head->next;

        ListNode* newHead = second;

        while (first != NULL && second != NULL) {

            first->next = second->next;
            second->next = first;

            if (first->next == NULL || first->next->next == NULL)
                break;

            ListNode* temp = first->next;

            first->next = temp->next;
            first = temp;
            second = first->next;
        }

        return newHead;
    }
};
