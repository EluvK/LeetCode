class Solution {
public:
    int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
    bool canMeasureWater(int x, int y, int z) {
        if(x+y<z) return false;
        if(x==0&y==0) return z==0;
        int g=gcd(x,y);
        if(z%g) return false;
        return true;
    }
};
