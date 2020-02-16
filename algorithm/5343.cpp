class Solution {
public:
    long long sum=0;
    bool isPossible(vector<int>& target) {
        auto mx=max_element(target.begin(),target.end());
        if(*mx==1) return true;
        for(auto it=target.begin();it!=target.end();it++) if(it!=mx) sum+=*it;
        if(sum>=*mx) return false;
        else{
            *mx-=sum;
            sum+=*mx;
            return iip(target);
        }
    }
    bool iip(vector<int>& target){
        auto mx=max_element(target.begin(),target.end());
        if(*mx==1) return true;
        sum-=*mx;
        if(sum>=*mx) return false;
        else{
            *mx-=sum;
            sum+=*mx;
            return iip(target);
        }
    }
};
