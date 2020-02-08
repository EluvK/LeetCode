class Solution {
public:
    int numberOfSteps (int num) {
        int step=0;
        while(num){
            step++;
            if(num%2) num--;
            else num/=2;
        }
        return step;
    }
};
