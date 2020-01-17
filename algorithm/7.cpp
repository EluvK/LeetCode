#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int res=0;
        while(x!=0){
            int temp=x%10;
            x/=10;
            if(res>INT_MAX/10||(res==INT_MAX/10&&temp>7)) return 0;
            if(res<INT_MIN/10||(res==INT_MIN/10&&temp<-8)) return 0;
            res=res*10+temp;
        }
        return res;
    }
};

int main(){
    int n=1534236469;
    Solution s;
    cout<<s.reverse(n);
//    for(auto c:res) cout<<c<<" ";
    return 0;
}
