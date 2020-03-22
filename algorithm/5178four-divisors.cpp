class Solution {
public:
    bool isprime(int n){
        if(n==1) return false;
        if(n==2) return true;
        for(int i=2;i*i<=n;++i){
            if(n%i==0) return false;
        }
        return true;
    }
    int work(int n){
        int a,b;
        for(a=2;a*a<=n;++a){
            if(n%a==0){
                b=n/a;
                if(a!=b&&isprime(a)&&isprime(b)) return a+b+1+n;
                else if(b==a*a) return a+b+1+n;
                else return 0;
            }
        }
        return 0;
    }

    int sumFourDivisors(vector<int>& nums) {
        int ans=0;
        for(auto c:nums) ans+=work(c);
        return ans;
    }
};
