class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0; 
        int number = n;
        while(number >= 5){
            number = number / 5;
            count= count + number;
        }
        return count;
    }
};
