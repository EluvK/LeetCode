class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> cnt(n,0);
        for(int i=0;i<n;++i){
            if(leftChild[i]==i||rightChild[i]==i) return false;
            if(leftChild[i]!=-1) ++cnt[leftChild[i]];
            if(rightChild[i]!=-1) ++cnt[rightChild[i]];
        }
        int cnt0=0;
        for(int i=0;i<n;++i){
            if(cnt[i]==0) cnt0++;
            else if(cnt[i]>1) return false;
            if(cnt0>1) return false;
        }
        if(cnt0) return true;
        else return false;
    }
};
