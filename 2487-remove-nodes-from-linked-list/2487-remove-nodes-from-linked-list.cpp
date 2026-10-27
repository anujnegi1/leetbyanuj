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
    ListNode* removeNodes(ListNode* head) {
        ListNode* cur=head;
        stack<ListNode*>st;
        while(cur!=nullptr)
        {
            while(!st.empty() && st.top()->val<cur->val)
            {
                st.pop();
            }
            st.push(cur);
            cur=cur->next;
        }
        ListNode* p=nullptr;
        while(!st.empty())
        {
            cur=st.top();
            st.pop();
            cur->next=p;
            p=cur;
        }
        return cur;
    }
};