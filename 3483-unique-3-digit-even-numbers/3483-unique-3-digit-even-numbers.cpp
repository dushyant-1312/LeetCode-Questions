class Solution {
public:
    int totalNumbers(vector<int>& nums) {
        set<int> ans;
        int n = nums.size();

        for(int i=0; i<n-2; i++){
            for(int j=i+1; j<n-1; j++){
                for(int k=j+1; k<n; k++){
                    if(nums[k]%2 == 0){
                        ans.insert((nums[i]*100 + nums[j] * 10 + nums[k]));
                        ans.insert((nums[j]*100 + nums[i] * 10 + nums[k]));
                    }
                    if(nums[j]%2 == 0){
                        ans.insert((nums[k]*100 + nums[i] * 10 + nums[j]));
                        ans.insert((nums[i]*100 + nums[k] * 10 + nums[j]));
                    }
                    if(nums[i]%2 == 0){
                        ans.insert((nums[j]*100 + nums[k] * 10 + nums[i]));
                        ans.insert((nums[k]*100 + nums[j] * 10 + nums[i]));
                    }
                }
            }
        }
        int count = 0;
        for(auto it : ans){ if(it > 99) count++;}
        return count;
    }
};