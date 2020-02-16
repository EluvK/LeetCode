class ProductOfNumbers {
public:
    vector<int> l;
    int len=0;
    ProductOfNumbers() {
        l.clear();
    }
    void add(int num) {
        l.push_back(num);
        ++len;
    }

    int getProduct(int k) {
        int st=len-k,ed=len-1,ans=1;
        for(int i=st;i<=ed&&ans;++i) ans*=l[i];
        return ans;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
