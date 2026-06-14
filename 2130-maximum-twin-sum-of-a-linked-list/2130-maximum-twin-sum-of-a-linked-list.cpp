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
    int pairSum(ListNode* head) {
        vector<int> nums;
        ListNode* temp = head;
        while(temp != NULL){
            nums.push_back(temp->val);
            temp=temp->next;
        }
        int sum = 0;
        int n = nums.size();
        for(int i=0;i<n/2;i++){
            sum = max(sum,nums[i]+nums[n-i-1]);
        }
        return sum;
    }
};
