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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto comp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;  // if true so the lower will win and push in the minheap
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> minheap;
        for (auto head : lists) {
            if (head) {
                minheap.push(head);
            }
        }
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while (!minheap.empty()) {
            ListNode* node = minheap.top();
            minheap.pop();
            tail->next=node;
            tail=node;
            if(node->next ){
                minheap.push(node->next);
            }
        }
        return dummy.next;
        //           vector<int> vals;

        // for (auto head : lists) {
        //     while (head) {
        //         vals.push_back(head->val);
        //         head = head->next;
        //     }
        // }

        // sort(vals.begin(), vals.end());
        // ListNode temp(0);
        // ListNode* tail=&temp;
        // for(auto val: vals){
        //     tail->next=new ListNode(val);
        //     tail= tail->next;
        // }
        // return temp.next;
    }
};
