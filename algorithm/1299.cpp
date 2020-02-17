class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> res;

        reverse(arr.begin(),arr.end());
        int len=arr.size();
        res.resize(len);
        int mx=arr[0];
        res[0]=-1;
        for(int i=1;i<len;i++){
            res[i]=mx;
            mx=mx>arr[i]?mx:arr[i];
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
