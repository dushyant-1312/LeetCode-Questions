class Solution {
public:
    double angleClock(int hour, int minutes) {
        double ans = abs(30*hour - 5.5*minutes);
        double nans = 360 - ans;
        return min(ans, nans);
    }
};