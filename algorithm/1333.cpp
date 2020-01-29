vector<vector<int> > ans;
inline bool cmp(const vector<int> &a,const vector<int> &b){return a[1]!=b[1]?a[1]>b[1]:a[0]>b[0];}
class Solution {
public:

    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        ans.clear();
        for(auto r:restaurants){
            int id=r[0],rating=r[1],vegan=r[2],price=r[3],dist=r[4];
            if(veganFriendly==1&&vegan==0) continue;
            if(price>maxPrice) continue;
            if(dist>maxDistance) continue;
            ans.push_back(r);
        }
        sort(ans.begin(),ans.end(),cmp);
        vector<int> res;
        for(auto r:ans) res.push_back(r[0]);
        return res;
    }
};
