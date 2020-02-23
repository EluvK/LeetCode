class Solution {
public:
    vector<int> getClosestFactor(int n)
    {
        int i;
        int integral_part=(int)sqrt(n);
        if(n%integral_part==0)
            return vector<int>{integral_part, n/integral_part};
        else
        {
            int flag;
            int low=pow(integral_part, 2);
            int high=pow(integral_part + 1, 2);
            if((n-low)>=(high-n))
                flag=integral_part+1;
            else
                flag=integral_part;
            for(i=flag-1;i>0;i--)
            {
                if(n%i==0)
                    break;
            }
            return vector<int>{i,n/i};
        }
    }
    vector<int> closestDivisors(int num) {
        vector<int> b=getClosestFactor(num+1);
        vector<int> c=getClosestFactor(num+2);
        int calb=abs(b[0]-b[1]),calc=abs(c[0]-c[1]);
        if(calb<=calc) return b;
        else return c;
    }
};
