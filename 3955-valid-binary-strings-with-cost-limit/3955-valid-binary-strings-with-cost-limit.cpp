class Solution {
public:
    bool check(string& s){
        for(int i=1; i<s.size(); i++){
            if(s[i-1] == '1' && s[i] == '1') return false;
        }
        return true;
    }
    void dpcheck(int n, int k, int i,int sum, string temp, vector<string> &ans){
        if(temp.size() == n){
            if(sum <= k){
                if(check(temp)) ans.push_back(temp);
            }
            return;
        }
        temp.push_back('1');
        dpcheck(n, k, i+1, sum + i, temp, ans);
        temp.pop_back();

        temp.push_back('0');
        dpcheck(n, k, i+1, sum, temp, ans);
        temp.pop_back();

    }
    vector<string> generateValidStrings(int n, int k) {
        vector<string> ans;
        string temp = "";
        dpcheck(n, k, 0, 0, "", ans);
        return ans;
    }
};