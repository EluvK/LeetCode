class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> res,vx,vy;
        set<int> st;
        vx.push_back(1);
        vy.push_back(1);
        int a=x,b=y;
        while(a!=1&&a<bound){
            vx.push_back(a);a*=x;
        }
        while(b!=1&&b<bound){
            vy.push_back(b);b*=y;
        }

        for(auto i:vx){
            for(auto j:vy){
                if(i+j<=bound) st.insert(i+j);
            }
        }
        res.assign(st.begin(),st.end());
        return res;
    }
};
