#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    int sumnum(int m,int n,int mid){
        int cnt=0;
        for(int i=1;i<=m;i++){
            cnt+=min(mid/i,n);
        }
        return cnt;
    }
    int findKthNumber(int m, int n, int k) {
        if(k==1) return 1;
        if(m*n==k) return k;
        int l=1,r=m*n,mid;
        while(l<r){
            mid=(l+r)>>1;
            int t=sumnum(m,n,mid);
            if(t<k) l=mid+1;
            else r=mid;//can not use mid-1 or return mid when =k;
        }
        return l;
    }
};

int main(){

    Solution s;
    cout<<s.findKthNumber(3,3,5);
    return 0;
}
