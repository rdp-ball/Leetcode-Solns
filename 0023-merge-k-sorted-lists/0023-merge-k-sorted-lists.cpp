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
 struct heapnode{
    int val;
    ListNode * node;

    bool operator>(const heapnode & other) const{
       return  val > other.val;
    }
 };
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<heapnode, vector<heapnode>, greater<heapnode>> pq;
        for (auto l : lists){
            if(l){
                pq.push(heapnode(l->val,l));
            }
        }

        ListNode newlist;
        ListNode* curr=&newlist;
        while (!pq.empty()){
            heapnode temp=pq.top();
            pq.pop();

            curr->next=temp.node;
            curr=curr->next;
            if (temp.node->next) {
                pq.push(heapnode{temp.node->next->val, temp.node->next});
            }

        }
        return newlist.next;

        
    }
};