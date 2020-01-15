#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class Solution{
public:
    string convert(string s,int numRows){
        if(numRows==1) return s;
        int r=numRows,len=s.size(),t=0;
        vector<string> ans(r,"");
        bool flag=true;
        for(int i=0;i<len;i++){
            ans[t]+=s[i];
            if(flag) t++;
            else t--;
            if(t==r-1) flag=false;
            if(t==0) flag=true;
        }
        string res;
        for(int i=0;i<r;i++){
            res+=ans[i];
        }
        return res;
    }
};

int main(){
    string str="LEETCODEISHIRING";
    int num=1;
    Solution s;
    cout<<"LEETCODEISHIRING"<<endl;
    cout<<s.convert(str,num);
    return 0;
}
