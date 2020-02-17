class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char,int> cnt;
        for(auto c:text) cnt[c]++;
        return min(min(cnt['b'],cnt['a']),min(cnt['n'],min(cnt['l']/2,cnt['o']/2)));
    }
};
