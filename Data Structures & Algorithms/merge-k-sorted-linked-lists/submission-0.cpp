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
          vector<int> vals;

for (auto head : lists) {
    while (head) {
        vals.push_back(head->val);
        head = head->next;
    }
}

sort(vals.begin(), vals.end());
ListNode temp(0);
ListNode* tail=&temp;
for(auto val: vals){
    tail->next=new ListNode(val);
    tail= tail->next;
}
return temp.next;
    }
};
