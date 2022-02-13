#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=5e3+10,M=1e9+7,OO=0x3f3f3f3f;

vector<int> adj[N];
int vis[N],vid;

void init(int n){
    ++vid;
    for(int i=0;i<n;++i)
        adj[i].clear();
}

int dfs(int u){
    vis[u]=vid;
    int ret=1;
    for(int i=0;i<adj[u].size();++i){
        int v=adj[u][i];
        if(vis[v]!=vid) ret+=dfs(v);
    }
    return ret;
}

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    int n,m;
    while(~scanf("%d%d",&n,&m),n||m){
        init(n);
        vector<string> arr(n);
        map<string,int> mp;
        for(int i=0;i<n;++i){
            cin>>arr[i];
            mp[arr[i]]=i;
        }
        for(int i=0;i<m;++i){
            string s1,s2;
            cin>>s1>>s2;
            int u=mp[s1],v=mp[s2];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans=0;
        for(int i=0;i<n;++i){
            if(vis[i]!=vid){
                ans=max(ans,dfs(i));
            }
        }

        printf("%d\n",ans);

    }


    return 0;
}
