class Solution {
public:
    string smallestPalindrome(string s) {

        vector<int> fre(26,0);
        for(auto it : s) fre[it-'a']++;
        string ans = "";
        int ni; bool mark = 0;
        for(int i=0; i<26; i++){
            int y = fre[i];
            if(y){
                int ny = y/2;
                while(ny > 0){
                    ans += i + 'a';
                    ny--;
                    fre[i] = fre[i]-2;
                }
            }
            if(fre[i] == 1){mark = true; ni = i; }
        }
        if(mark) ans += ni + 'a';
        for(int i=s.size()-ans.size() -1; i >= 0; i--){
            ans += ans[i];
        }
        return ans;
    }
};