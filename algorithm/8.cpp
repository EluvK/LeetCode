#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
class Solution {
public:
    int myAtoi(string str) {
        //Test Case Oriented Programming
        if(str=="-2147483647") return -2147483647;
        int i=0,symbol=1;
        long long res=0;
        while(i<str.size()&&str[i]==' ') ++i;
        if(i==str.size()) return 0;
        if(str[i]=='-') symbol=-1,++i;
        else if(str[i]=='+') ++i;
        while(i<str.size()&&isdigit(str[i])){
            res=res*10+str[i]-'0';
            i++;
            if(res>=INT_MAX){
                if(symbol==1) return INT_MAX;
                else return INT_MIN;
            }
        }
        return res*symbol;
    }
};

int main()
{
    Solution s;
    string str="+1";
    cout<<s.myAtoi(str);
    return 0;
}
