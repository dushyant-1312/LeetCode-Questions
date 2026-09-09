// class Solution {
// public:
//     long long countCommas(long long n) {
//         if(n < 1000) return 0;

//         if(n == 1e15) return 5 + (1e15-1  - 1e12 + 1) * 4 + (1e12- 1e9 + 1) *3 +  (1e9- 1e6 + 1) * 2 +  (1e9- 1e3 + 1);  
//         else if(n >= 1e12) {
//             return  (n - 1e12 + 1) * 4 + (1e12- 1e9 + 1) *3 +  (1e9- 1e6 + 1) * 2 +  (1e9- 1e3 + 1);  
//         }
//         else if(n >= 1e9){
//             return (n- 1e9 + 1) *3 +  (1e9- 1e6 + 1) * 2 +  (1e9- 1e3 + 1);  
//         }
//         else if(n >= 1e6){
//             return (n - 1e6 + 1) * 2 +  (1e9- 1e3 + 1);  
//         }
//         else {
//             return (n- 1e3 + 1);  
//         }
//         return -1;
//     }
// };
class Solution {
public:
    long long countCommas(long long n) {
        if(n < 1000) return 0;

        if(n == 1e15)
            return 5 + (1e15 - 1 - 1e12 + 1) * 4
                     + (1e12 - 1e9) * 3
                     + (1e9 - 1e6) * 2
                     + (1e6 - 1e3);

        else if(n >= 1e12) {
            return (n - 1e12 + 1) * 4
                 + (1e12 - 1e9) * 3
                 + (1e9 - 1e6) * 2
                 + (1e6 - 1e3);
        }

        else if(n >= 1e9) {
            return (n - 1e9 + 1) * 3
                 + (1e9 - 1e6) * 2
                 + (1e6 - 1e3);
        }

        else if(n >= 1e6) {
            return (n - 1e6 + 1) * 2
                 + (1e6 - 1e3);
        }

        else {
            return (n - 1e3 + 1);
        }

        return -1;
    }
};