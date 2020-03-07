class Cashier {
public:
    int tm,cnt;
    double dis;
    map<int,int> mp;
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        cnt=0;tm=n;dis=(double)discount;
        for(int i=0;i<products.size();++i) mp[products[i]]=prices[i];
    }

    double getBill(vector<int> product, vector<int> amount) {
        double ans=0;
        for(int i=0;i<product.size();++i){
            ans+=(double)(mp[product[i]]*amount[i]);
        }
        if(++cnt%tm==0) ans-=(dis*ans)/100;
        return ans;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */
