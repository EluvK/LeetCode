class Solution {
public:
    bool canPermutePalindrome(string s) {
        map<char,int> mp;
        mp.clear();
        for(int i=0;i<s.size();++i) mp[s[i]]++;
        int cnt=0;
        for(auto it=mp.begin();it!=mp.end();++it){
            if(it->second%2) cnt++;
        }
        return cnt>1?false:true;
    }
};
