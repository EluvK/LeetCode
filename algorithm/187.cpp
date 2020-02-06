class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> mp;
        int l=0,r=9;
        vector<string> ans;
        ans.clear();
        while(r<s.size()){
            string tmp=s.substr(l,10);
            if(mp[tmp]==1){
                ans.push_back(tmp);
            }
            mp[tmp]++;
            l++,r++;
        }
        return ans;
    }
};
