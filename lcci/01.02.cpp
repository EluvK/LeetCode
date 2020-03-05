class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        map<char,int> mp;
        mp.clear();
        if(s1.size()!=s2.size()) return false;
        for(int i=0;i<s1.size();++i) mp[s1[i]]++;
        for(int i=0;i<s2.size();++i){
            if(mp[s2[i]]--==0) return false;
        }
        return true;
    }
};
