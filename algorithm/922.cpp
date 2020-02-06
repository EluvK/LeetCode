class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        vector<int> odd,even,ans;
        odd.clear(),even.clear(),ans.clear();
        for(int i=0;i<A.size();i++){
            if(A[i]%2) odd.push_back(A[i]);
            else even.push_back(A[i]);
        }
        sort(odd.begin(),odd.end());
        sort(even.begin(),even.end());
        for(int i=0,j=0;i<odd.size(),j<even.size();++i,++j){
            ans.push_back(even[j]);
            ans.push_back(odd[i]);
        }
        return ans;
    }
};
