class Solution {
public:
    double angleClock(int hour, int minutes) {
        double h=double(hour),m=double(minutes);
        double a=h*30+(m/2);
        if(a>=360) a-=360;
        double b=m*6;
        cout<<"a:"<<a<<" b:"<<b<<endl;
        double ans;
        if(a>b) ans=a-b;
        else ans=b-a;
        if(ans>180) ans=360-ans;
        return ans;

    }
};
