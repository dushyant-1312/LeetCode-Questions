class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> mapp;
        for(auto it : text){
            if(it == 'b' || it == 'a' || it == 'l' || it == 'o' || it == 'n') mapp[it]++;
        }
        int ans = INT_MAX;
        for(auto it : mapp){
            if(it.first == 'l' || it.first == 'o') it.second = it.second/2;
            ans = min(ans, it.second);
        }
        return (mapp.size() == 5) ? ans : 0;
    }
};