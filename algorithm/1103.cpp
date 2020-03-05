class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people,0);
        int n=1;
        while(candies>0){
            for(int i=0;i<num_people;++i,++n){
                if(candies>n) ans[i]+=n,candies-=n;
                else{
                    ans[i]+=candies;
                    candies=0;
                    break;
                }
            }
        }
        return ans;
    }
};
