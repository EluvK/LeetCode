class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int mx=0,mxi=0,num=0,ans=0;
        for(int i=0;i<X;i++){
            if(grumpy[i]) num+=customers[i];
        }
        mx=num;
        for(int i=1;i<=customers.size()-X;i++){
            num=num+(grumpy[i+X-1]?customers[i+X-1]:0)-(grumpy[i-1]?customers[i-1]:0);
            if(num>mx){
                mx=num;
                mxi=i;
            }
        }
        for(int i=0;i<mxi;i++){
            if(!grumpy[i]) ans+=customers[i];
        }
        for(int i=mxi;i<mxi+X;i++){
            ans+=customers[i];
        }
        for(int i=mxi+X;i<customers.size();i++){
            if(!grumpy[i]) ans+=customers[i];
        }
        return ans;
    }
};
