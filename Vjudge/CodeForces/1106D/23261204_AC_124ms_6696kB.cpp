#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
const int oo=0x3f3f3f3f;

vector<int> adj[N];
int q,n,m,u,v,mx,x;
bool vis[N];
set<int> st;



int main(){
        scanf("%d %d",&n,&m);
        for(int i=0;i<m;++i){
            scanf("%d %d",&u,&v);
            --u,--v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        st.insert(0);
        vis[0]=1;
        while(st.size()){
            int u=*st.begin();
            st.erase(u);
            printf("%d ",u+1);
            for(int v : adj[u]){
                if(!vis[v]){
                    st.insert(v);
                    vis[v]=1;
                }
            }
        }
}
