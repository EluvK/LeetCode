class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        long long sum=0;
        for(int i=0;i<A.size();i++){
            sum+=A[i];
        }
        if(sum%3) return false;
        long long p=sum/3;
        sum=0;
        for(int i=0;i<A.size();i++){
            sum+=A[i];
            if(sum==p){
                int j=i+1;
                for(;j<A.size();j++){
                    sum+=A[j];
                    if(sum==p*2) return true;
                }
                return false;
            }
        }
        return false;
    }
};
