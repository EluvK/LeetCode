class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        set<pair<int,int> > st;
        st.clear();
        int sumsize=0;
        int x1,x2,x3,x4,y1,y2,y3,y4,rx1=INT_MAX,ry1=INT_MAX,rx2=INT_MIN,ry2=INT_MIN;
        for(int i=0;i<rectangles.size();i++){
            x1=x4=rectangles[i][0];
            x2=x3=rectangles[i][2];
            y1=y2=rectangles[i][1];
            y3=y4=rectangles[i][3];
            rx1=min(rx1,x1);
            ry1=min(ry1,y1);
            rx2=max(rx2,x3);
            ry2=max(ry2,y3);
            sumsize+=abs((x1-x3)*(y1-y3));
            pair<int,int> p1=make_pair(x1,y1);
            pair<int,int> p2=make_pair(x2,y2);
            pair<int,int> p3=make_pair(x3,y3);
            pair<int,int> p4=make_pair(x4,y4);
            if(!st.count(p1)) st.insert(p1);
            else st.erase(p1);
            if(!st.count(p2)) st.insert(p2);
            else st.erase(p2);
            if(!st.count(p3)) st.insert(p3);
            else st.erase(p3);
            if(!st.count(p4)) st.insert(p4);
            else st.erase(p4);
        }

        if(sumsize!=abs((rx1-rx2)*(ry1-ry2)))
            return false;
        if(st.count(make_pair(rx1,ry1))&&
        st.count(make_pair(rx1,ry2))&&
        st.count(make_pair(rx2,ry1))&&
        st.count(make_pair(rx2,ry2))&&
        st.size()==4
        ) return true;
        else return false;
    }
};
