class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        int cnt[10]={0};
        int sum=0;
        for(int i=0;i<digits.size();++i) ++cnt[digits[i]],sum+=digits[i];
        if(sum%3==1){
            for(int i=1;i<10;i=i+3){
                if(cnt[i]){cnt[i]--;sum-=i;break;}
            }
            if(sum%3){
                int tmp=2;
                for(int i=2;i<10;i=i+3){
                    while(cnt[i]&&(tmp--)) cnt[i]--;
                }
                if(tmp) return "";
            }
        }else if(sum%3==2){
            for(int i=2;i<10;i=i+3){
                if(cnt[i]){cnt[i]--;sum-=i;break;}
            }
            if(sum%3){
                int tmp=2;
                for(int i=1;i<10;i=i+3){
                    while(cnt[i]&&(tmp--)) cnt[i]--;
                }
                if(tmp) return "";
            }
        }
        string ans="";
        for(int i=9;i>=0;--i){
            char c='0'+i;
            while(cnt[i]--) ans+=c;
        }
        if(ans.size()&&ans[0]=='0') return "0";
        return ans;
    }
};
