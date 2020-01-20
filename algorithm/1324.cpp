class Solution {
public:
    int Max(int a,int b){
        if(a>b) return a;
        else return b;
    }
    vector<string> printVertically(string s) {
        string temp;
        temp.clear();
        int mx=-1;
        vector<string> ipt,res;
        for(int i=0;i<s.length();i++){
            if(s[i]==' '&&temp.length()>0){
                ipt.push_back(temp);
                mx=Max(mx,temp.length());
                temp.clear();
            }else{
                temp=temp+s[i];
            }
        }
        if(temp.length()>0){
            ipt.push_back(temp);
            mx=Max(mx,temp.length());
            temp.clear();
        }

        for(int j=0;j<mx;j++){
            for(int k=0;k<ipt.size();k++){
                if(ipt[k].length()>j){
                    temp=temp+ipt[k][j];
                }else{
                    temp=temp+' ';
                }
            }
            res.push_back(temp);
            temp.clear();
        }
        for(int i=0;i<res.size();i++){
            for(int j=res[i].size()-1;j>0;j--){
                if(res[i][j]==' '){
                    res[i].pop_back();
                }else{
                    break;
                }
            }
        }
        return res;
    }
};
