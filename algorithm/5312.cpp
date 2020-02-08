class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        long long temp=0;
        long long tar=threshold*k;
        int cnt=0;
        for(int i=0;i<k;i++){
            temp+=arr[i];
        }
        for(int i=k;i<arr.size();i++){
            if(temp>=tar) cnt++;
            temp=temp-arr[i-k]+arr[i];
        }
        if(temp>=tar) cnt++;
        return cnt;
    }
};
