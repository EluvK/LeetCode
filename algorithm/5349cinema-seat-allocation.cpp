class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        sort(reservedSeats.begin(),reservedSeats.end(),[&](vector<int> a,vector<int> b){
            return a[0]!=b[0]?a[0]<b[0]:a[1]<b[1];
        });
        int cnt[8]={0,1,1,1,1,2,1,2};
        int ans=0;
        int infrow=0;
        for(int i=0;i<reservedSeats.size();){
            int j;
            for(j=i;j<reservedSeats.size();++j){
                if(reservedSeats[j][0]!=reservedSeats[i][0]) break;
            }
            int tmp=7;
            for(int k=i;k<j;++k){
                int col=reservedSeats[k][1];
                if(col==2||col==3) tmp&=3;//011;
                else if(col==4||col==5) tmp&=1;//001;
                else if(col==6||col==7) tmp&=4;//100;
                else if(col==8||col==9) tmp&=6;//110;
            }
            ans+=cnt[tmp];
            i=j;
            infrow++;
        }
        return ans+2*(n-infrow);
    }
};
