class Solution {
public:
    int maxDepth(Node* root) {
        if(!root) return 0;
        int m=0;
        for(auto c:root->children)
            m=max(m,maxDepth(c));
        return ++m;
    }
};
