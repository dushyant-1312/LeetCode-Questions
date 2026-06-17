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
// class Solution {
// public:
//     ListNode* deleteMiddle(ListNode* head) {
//         if(head==NULL) return head;
//         ListNode* temp=head;
//         vector<int> v;
//         while(temp!=NULL){
//             v.push_back(temp->val);
//             temp=temp->next;
//         } 
//         int n=v.size();
//         if(n%2 == 0){
//             v.erase(v.begin()+(n+1)/2);
//         }
//         else {v.erase(v.begin()+n/2);}
//         ListNode* ans= new ListNode(v[0]);
//         head=ans;
//         for(auto it:v){
//             ListNode* i=new ListNode(it);
//             ans->next=i;
//             ans=ans->next;
//         }
//         return head->next;
//     }
// };

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL) return head;
        ListNode* temp=head;
        vector<int> v;
        int count = 0;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        } 
        if(count == 1) return NULL;
        int ncount = 0;
        temp = head; ListNode* ntemp = head;
        while(ncount != (count/2) - 1){
            ncount++;
            temp = temp->next;
        }
        ntemp = temp->next;
        temp->next = ntemp->next;
        return head;
    }
};