#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minTaps(int n,vector<int> &ranges){
        vector<int> land(n,0);
        for(int i=0;i<ranges.size();i++){
            int l=max(i-ranges[i],0);
            int r=min(i+ranges[i],n);
            for(int j=l;j<r;j++){
                land[j]=max(land[j],r);
            }
        }

        int cnt=0,cur=0;
        while(cur<n){
            if(land[cur]==0) return -1;
            cur=land[cur];
            cnt++;
        }
        return cnt;
    }
};

int main()
{
    Solution s;
    vector<int> v={3,4,1,1,0,0};
    cout<<s.minTaps(5,v);
    return 0;
}
