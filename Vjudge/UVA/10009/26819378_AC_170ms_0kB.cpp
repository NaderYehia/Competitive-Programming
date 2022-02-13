#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=1e5+5,M=1e9+7,OO=0x3f3f3f3f;
int t,n,m,k;
vector<int> adj[30];
string ans;
bool vis[30];

void bfs(int u,int v){
    queue<pair<int,string> > q;
    string st;
    st+=('A'+u);
    q.push(make_pair(u,st));
    vis[u]=1;
    while(q.size()){
        int cur=q.front().first;
        string tmp=q.front().second;
        q.pop();
        if(cur==v){
            cout<<tmp<<endl;
            return;
        }
        for(int i=0,vv;i<adj[cur].size();++i){
            vv=adj[cur][i];
            if(!vis[vv]){
                string tmpp=tmp;
                tmpp+=('A'+vv);
                q.push(make_pair(vv,tmpp));
            }
        }
    }
}

int main(){
    //freopen("myfile.txt","w",stdout);
    scanf("%d",&t);
    while(t--){
        for(int i=0;i<30;++i)
            adj[i].clear();
        scanf("%d%d",&m,&n);
        for(int i=0;i<m;++i){
            char s1[N],s2[N];
            scanf("%s %s",s1,s2);
            adj[s1[0]-'A'].push_back(s2[0]-'A');
            adj[s2[0]-'A'].push_back(s1[0]-'A');
        }
        while(n--){
            char s1[N],s2[N];
            scanf("%s %s",s1,s2);
            memset(vis,0,sizeof vis);
            bfs(s1[0]-'A',s2[0]-'A');
        }
        if(t) printf("\n");
    }
    return 0;
}
