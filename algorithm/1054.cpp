#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

struct pqp{
    int ind,num;
    pqp(int a,int b){ind=a;num=b;}

    friend bool operator < (const pqp &a,const pqp &b){
        return a.num<b.num;
    }
};

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        priority_queue<pqp> q;
        map<int,int> mp;
        for(auto c:barcodes) mp[c]++;
        for(auto it=mp.begin();it!=mp.end();it++) q.push(pqp(it->first,it->second));

        int last=-1;
        vector<int> res;
        while(!q.empty()){
            pqp f=q.top();
            q.pop();
            if(f.ind!=last){
                res.push_back(f.ind);
                last=f.ind;
                f.num--;
            }
            else{
                pqp temp=q.top();
                q.pop();
                res.push_back(temp.ind);
                last=temp.ind;
                temp.num--;
                if(temp.num) q.push(temp);
            }
            if(f.num) q.push(f);
        }
        return res;
    }
};

int main(){
    vector<int> v={1,1,1,1,2,4,3};
    Solution s;
    vector<int> res=s.rearrangeBarcodes(v);
    for(auto c:res) cout<<c<<" ";
    return 0;
}
