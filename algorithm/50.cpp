class Solution {
public:
    double myPow(double x, long n) {
        if(n==0) return 1;
        if(n<0) return 1/myPow(x,-n);
        double mid=myPow(x,n/2);
        if(n%2) return mid*mid*x;
        else return mid*mid;
    }
};
