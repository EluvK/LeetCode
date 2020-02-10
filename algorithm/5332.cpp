class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        map<int,int> mp;
        for(int i=0;i<arr.size();i++) mp[arr[i]]++;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<INT_MAX/2){
                if((mp[2*arr[i]]>0&&arr[i]!=0)||(mp[2*arr[i]]>1&&arr[i]==0)){
                    return true;
                }
            }
        }
        return false;
    }
};
