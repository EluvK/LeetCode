class Solution {
public:
    vector<vector<int>> group;
    queue<int> q,rq;

    int qpush(queue<int> &q,int i,int f,vector<int> &ans,vector<int> &vis,vector<int> &rvis){
        if(!rvis[f-1]) return 1;
        if(i>0&&i<ans.size()&&!vis[f-1]){
            q.push(i);
            vis[i]=true;
            ans[i]=ans[f]+1;
        }
        return 0;
    }

    int minJumps(vector<int>& arr) {
        group.clear();
        group.push_back({-1});
        int ind=1;//next;
        map<int,int> mp;
        arr.insert(arr.begin(),-1);
        for(int i=1;i<arr.size();i++){
            if(mp[arr[i]]==0){
                group.push_back({i});
                mp[arr[i]]=ind++;
            }else{
                group[mp[arr[i]]].push_back(i);
            }
        }
        // for(int i=1;i<group.size();i++){
        //     for(int j=0;j<group[i].size();j++){
        //         cout<<group[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        vector<bool> vis(arr.size()+1,false),rvis(arr.size()+1,false);
        vector<int> ans(arr.size()+1,0),rans(arr.size()+1,0);
        while(!q.empty()) q.pop();
        while(!rq.empty()) rq.pop();

        q.push(1);
        rq.push(arr.size()-1);

        vis[1]=true;
        rvis[arr.size()-1]=true;

        while(!q.empty()&&!rq.empty()){

            if(rq.size()<=q.size()){
                int f=rq.front();
                rq.pop();
                if(f-1>0&&!rvis[f-1]){
                    if(vis[f-1]) return rans[f]+ans[f-1]+1;
                    rq.push(f-1);
                    rvis[f-1]=true;
                    rans[f-1]=rans[f]+1;
                }
                if(f+1<arr.size()&&!rvis[f+1]){
                    if(vis[f+1]) return rans[f]+ans[f+1]+1;
                    rq.push(f+1);
                    rvis[f+1]=true;
                    rans[f+1]=rans[f]+1;
                }
                int mpi=mp[arr[f]];
                for(int i=0;i<group[mpi].size();i++){
                    int t=group[mpi][i];
                    if(!rvis[t]){
                        if(vis[t]) return rans[f]+ans[t]+1;
                        rq.push(t);
                        rvis[t]=true;
                        rans[t]=rans[f]+1;
                    }
                }
            }else{
                int f=q.front();
                q.pop();
                if(f-1>0&&!vis[f-1]){
                    if(rvis[f-1]) return ans[f]+rans[f-1]+1;
                    q.push(f-1);
                    vis[f-1]=true;
                    ans[f-1]=ans[f]+1;
                }
                if(f+1<arr.size()&&!vis[f+1]){
                    if(rvis[f+1]) return ans[f]+rans[f+1]+1;
                    q.push(f+1);
                    vis[f+1]=true;
                    ans[f+1]=ans[f]+1;
                }
                int mpi=mp[arr[f]];
                for(int i=0;i<group[mpi].size();i++){
                    int t=group[mpi][i];
                    if(!vis[t]){
                        if(rvis[t]) return ans[f]+rans[t]+1;
                        q.push(t);
                        vis[t]=true;
                        ans[t]=ans[f]+1;
                    }
                }
            }


        }

        return 0;
    }
};
