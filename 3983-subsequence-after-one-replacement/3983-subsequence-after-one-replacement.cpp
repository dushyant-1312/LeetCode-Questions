class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        // int i=0; int j = 0;
        // if(s.size() > t.size()) return false;

        // while(i < s.size() && j < t.size()){
        //     if(s[i] == t[j]){
        //         i++; j++;
        //     }
        //     else{
        //         j++;
        //     }
        //     if(i == s.size() - 1 && j != t.size()) return true;
        // }
        // if(i == s.size()) return true;
        // if(i == s.size() - 1 && j != t.size()) return true;
        
        // int k = s.size()-1; int l = t.size()-1;
        // while(k > 0 && l >  0){
        //     if(s[k] == t[l]){
        //         k--; l--;
        //     }
        //     else{
        //         l--;
        //     }
        //     // if(k == 1 && l != 0) return true;
        // }
        // if(k == 0) return true;
        // if(k == 1 && l != 0) return true;

        // return false; 

        int i=0,j=0, m=s.size();
        for(auto c:t){
            if(s[i]==c) i++;
            i=max(i,j+1);
            if(s[j]==c)  j++;
            if(i==m || j==m ) return true;
        }
        return false;
        
    }
};