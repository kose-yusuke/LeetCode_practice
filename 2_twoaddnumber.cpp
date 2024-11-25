/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* root = new ListNode(0);
        //returnのためにnodeの先頭 : rootを持っておくため
        ListNode* ans = root;
        // carry : 繰り上がり. 0か1
        int carry = 0;
        while (l1 != NULL || l2 != NULL)
        {
            int n = 0;
            if (l1 != NULL && l2 != NULL){
                // 1の位
                n = (l1->val + l2->val + carry) % 10;
                // 繰り上がりがあるかどうか
                carry = (l1->val + l2->val + carry) / 10;
                l1 = l1->next;
                l2 = l2->next;
            } else if (l1 != NULL){
                n = (l1->val + carry) % 10;
                carry = (l1->val + carry) / 10;
                l1 = l1->next;
            } else if (l2 != NULL){
                n = (l2->val + carry) % 10;
                carry = (l2->val + carry) / 10;
                l2 = l2->next;
            } else{

            }
            ans->val = n;
            // l1, l2の次のnodeがあるかどうか
            if (l1 != NULL || l2 != NULL){
                ans->next = new ListNode(0);
                ans = ans->next;
            }
        }
        if (carry == 1){
            ans->next = new ListNode(1);
        }
        return root;
    }
};