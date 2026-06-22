class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int count = 0;
        for(int i=0; i<nums.size(); i++){
            long long sum = 0;
            for(int j=i; j<nums.size(); j++){
                sum += nums[j];
                long long nsum = sum;
                int last = sum%10;
                int first = 0;
                while(nsum != 0){ first = nsum%10; nsum = nsum/10;} 
                if(first== x && last == x) count++;
            }
        }
        return count;
    }
};

// class Solution {
// public:
//     int countValidSubarrays(vector<int>& nums, int x) {
//         int count = 0;
//         string xx = to_string(x);
//         for(int i=0; i<nums.size(); i++){
//             long long sum = 0;
//             for(int j=i; j<nums.size(); j++){
//                 sum += nums[j];
//                 int last = sum%10;
//                 cout<<last<<endl;
//                 string s = to_string(sum);
//                 if(s[0] == x+'0'  && last == x) count++;
//             }
//         }
//         return count;
//     }
// };