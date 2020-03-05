class Solution {
public:
    bool isUnique(string astr) {
        map<char,int> mp;
        mp.clear();
        for(int i=0;i<astr.size();++i){
            if(mp[astr[i]]++>0) return false;
        }
        return true;
    }
};
