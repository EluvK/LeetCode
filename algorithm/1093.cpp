class Solution {
public:
    double findnum(int mid,vector<int> &count){
        int cnt=0;
        for(int i=0;i<=255;++i){
            cnt+=count[i];
            if(cnt>=mid){
                return (double)i;
            }
        }
        return -1;
    }
    vector<double> sampleStats(vector<int>& count) {
        int mn=255,mx=0,mode,cnt=0,modenum=0;
        long long sum=0;
        double avg;
        for(int i=0;i<=255;i++){
            if(count[i]){
                mn=min(i,mn);
                mx=max(i,mx);
                cnt+=count[i];
                sum+=i*count[i];
                if(count[i]>modenum){
                    mode=i;modenum=count[i];
                }
            }
        }
        avg=(double)sum/(double)cnt;
        int mid1,mid2;
        mid1=mid2=cnt/2;
        if(cnt%2==0){
            mid2++;
        }
        double midnum=findnum(mid1,count)+findnum(mid2,count);
        midnum/=2;


        return vector<double>{(double)mn,(double)mx,avg,midnum,(double)mode};
    }
};
