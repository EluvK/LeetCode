class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int len=arr.size();
        if(len==0) return arr;
        vector<int> res,temp=arr;
        res.clear();
        sort(temp.begin(),temp.end());
        int i=1;
        map<int,int> mp;
        mp[temp[0]]=1;
        for(int j=1;j<len;j++){
            if(temp[j]>temp[j-1]) i++;
            mp[temp[j]]=i;
        }
        for(int j=0;j<len;j++){
            res.push_back(mp[arr[j]]);
        }
        return res;
    }
};
