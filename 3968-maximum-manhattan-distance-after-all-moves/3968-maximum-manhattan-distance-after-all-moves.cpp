class Solution {
public:
    int maxDistance(string moves) {
        int l = 0; int r = 0; int u = 0; int d = 0;
        int count = 0;
        for(auto it : moves){
            if(it == 'L') l++;
            else if(it == 'R') r++;
            else if(it == 'U') u++;
            else if(it == 'D') d++;
            else count++;
        }
        return abs(l - r) + abs(u - d) + count;
    }
};