class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int,int> mp;
        int ans=0;
        for(auto num:answers){
            if(num) mp[num]++;
            else ans++;
        }
        for(auto it=mp.begin();it!=mp.end();it++){
            int a=it->first,b=it->second;
            int div=(a+b)/(a+1)*(a+1);
            ans+=div;
        }
        return ans;
    }
};
