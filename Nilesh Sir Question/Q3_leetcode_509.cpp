class Solution {
public:
    int fib(int n) {
       return meme(n);
    }
    int meme(int num){
        if(num == 0 ){
            return 0;
        }
        if(num == 1){
            return 1;
        }
        else{
            return meme(num-2) + meme(num-1);
        }
    }
};