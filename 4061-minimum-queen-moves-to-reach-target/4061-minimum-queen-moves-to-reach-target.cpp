class Solution {
public:
    int minQueenMoves(vector<int>& source, vector<int>& target) {
        if(abs(source[0] - target[0]) == 0 &&  abs(source[1] - target[1]) == 0) return 0;
        if(abs(source[0] - target[0]) == abs(source[1] - target[1])) return 1;
        if(source[0] == target[0] || source[1] == target[1]) return 1;
        return 2;
    }
};