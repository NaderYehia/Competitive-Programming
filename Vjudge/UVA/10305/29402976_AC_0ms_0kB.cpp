#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=2e5+10,M=1e9+7,OO=0x3f3f3f3f;

vector<int> adj[N];
bool vis[N];
vector<int> ans;
int in[N];


int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    int n,m;
    while(~scanf("%d%d",&n,&m),n||m){
        ans.clear();
        for(int i=0;i<n;++i){
            adj[i].clear();
            vis[i]=0;
            in[i]=0;
        }
        for(int i=0;i<m;++i){
            int u,v;
            scanf("%d%d",&u,&v);
            --u,--v;
            adj[u].push_back(v);
            in[v]++;
        }

        queue<int> q;
        for(int i=0;i<n;++i)
            if(in[i]==0)
                q.push(i);

        while(q.size()){
            int u=q.front();
            q.pop();
            ans.push_back(u);
            for(int i=0;i<adj[u].size();++i){
                int v=adj[u][i];
                in[v]--;
                if(in[v]==0){
                    q.push(v);
                }
            }
        }

        for(int i=0;i<ans.size();++i)
            printf("%d%c",ans[i]+1," \n"[i+1==ans.size()]);

    }


    return 0;
}
