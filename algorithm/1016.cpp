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
    bool queryString(string S, int N) {
        for(int i=1;i<=N;i++){
            string str;
            if(S.find(to_binary_str(i))==string::npos) return false;
        }
        return true;
    }
    string to_binary_str(int n){
        string str="";
        int temp;
        while(n){
            temp=n&1;
            str+=temp+'0';
            n>>=1;
        }
        reverse(str.begin(),str.end());
        return str;
    }
};

int main(){
    string str="0110";
    int n=3;
    Solution s;
    cout<<s.queryString(str,n);
//    for(auto c:res) cout<<c<<" ";
    return 0;
}
