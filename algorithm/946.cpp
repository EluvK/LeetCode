class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        while(!st.empty()) st.pop();
        int len=popped.size(),ind=0;
        map<int,int> mp;
        for(int i=0;i<len;i++){
            if(ind==len){
                if(st.empty()) return false;
                if(st.top()!=popped[i]) return false;
                st.pop();
                continue;
            }
            if(mp[popped[i]]==-1){
                if(st.empty()) return false;
                if(st.top()!=popped[i]) return false;
            }
            else{
                do{
                    if(ind==len) return false;
                    st.push(pushed[ind]);
                    mp[pushed[ind]]=-1;
                }while(pushed[ind++]!=popped[i]);
            }

            st.pop();
        }
        return true;
    }
};
