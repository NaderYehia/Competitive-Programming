#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-2,pi=acos(-1);
const int N=1e3+5,M=1e9+7,SEGM=4*N,OO=0x3f3f3f3f;
int t,w,n;;
double d,x[N],y[N];
bool vis[N];

void dfs(int i){
    vis[i]=1;
    for(int j=0;j<n;++j)
        if(!vis[j]&&sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]))<=d)
            dfs(j);
}

int main(){
    //freopen("myfile.txt","w",stdout);
    int tc=1;
    cin>>t;
    while(t--){
        cin>>n>>d;
        for(int i=0;i<n;++i)
            cin>>x[i]>>y[i];
        memset(vis,0,sizeof vis);
        int cons=0;
        for(int i=0;i<n;++i)
            if(!vis[i])
                dfs(i),cons++;
        printf("Case %d: %d\n",tc++,cons);
    }
    return 0;
}
