class TweetCounts {
public:
    unordered_map<string,multiset<int>> tc;

    TweetCounts() {
    }

    void recordTweet(string tweetName, int time) {
        tc[tweetName].insert(time);
    }

    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        map<string,int> f={{"minute",60},{"hour",3600},{"day",86400}};
        int sz=f[freq];
        int n=1+(endTime-startTime)/sz;
        vector<int> ans(n);
        auto lb=tc[tweetName].lower_bound(startTime);
        while(lb!=tc[tweetName].end()&&*lb<=endTime){
            ++ans[(*lb-startTime)/sz];
            ++lb;
        }
        return ans.empty()?vector<int>{0}:ans;
    }
};
/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */
