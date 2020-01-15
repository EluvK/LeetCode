#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> v={12,23,34,45,56,67,78,89,123,234,345,456,567,678,789,1234,2345,3456,4567,5678,6789,12345,23456,34567,45678,56789,123456,234567,345678,456789,1234567,2345678,3456789,12345678,23456789,123456789};
        vector<int> res;
        for(auto c:v){
            if(low<=c&&c<=high) res.push_back(c);
        }
        return res;
    }
};

int main(){
    int low=100,high=300;
    Solution s;
    vector<int> res=s.sequentialDigits(low,high);
    for(auto c:res) cout<<c<<" ";
    return 0;
}
