class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int ans=0;
        map<int,int> mp;
        for(int i=0;i<wall.size();i++){
            int st=0;
            for(int j=0;j<wall[i].size()-1;j++){
                st+=wall[i][j];
                mp[st]++;
            }
        }
        for(auto c:mp){
            if(c.second>ans) ans=c.second;
        }
        return wall.size()-ans;

    }
};
