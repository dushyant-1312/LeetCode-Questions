class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        priority_queue<int, vector<int>, greater<int>> s;
        for(int i=1; i<=9; i++){
            int check = i;
            for(int j=i+1; j<=9; j++){
                check = check*10 + j;
                if(check >= low &&  check <= high) s.push(check);
            }
        }
        vector<int> ans;
        while(!s.empty()){ ans.push_back(s.top()); s.pop();}
        return ans;
    }
};