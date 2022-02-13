#include<bits/stdc++.h>
using namespace std;

const int N=1e2+5;
const int oo=0x3f3f3f3f;

char grid[N][N];
bool vis[N][N];
int q,n,m,u,v,x,ke;
int arr[]={0,1,-1};

bool valid(int r,int c){
    return r<n&&c<n&&r>-1&&c>-1;
}

void dfs(int r,int c){
    vis[r][c]=1;
    for(int i=0;i<3;++i)
        for(int j=0;j<3;++j){
            if(abs(arr[i])==abs(arr[j]))
                continue;
            if(valid(r+arr[i],c+arr[j])&&!vis[r+arr[i]][c+arr[j]]&&(grid[r+arr[i]][c+arr[j]]=='x'||grid[r+arr[i]][c+arr[j]]=='@'))
                dfs(r+arr[i],c+arr[j]);
        }
}


int main(){
        scanf("%d\n",&q);
        while(q--){
            memset(vis,0,sizeof vis);
            scanf("%d",&n);
            for(int i=0;i<n;++i)
                scanf("%s",grid[i]);
            x=0;
            for(int i=0;i<n;++i)
                for(int j=0;j<n;++j)
                    if(grid[i][j]=='x'&&!vis[i][j]){
                        dfs(i,j);
                        ++x;
                    }
            printf("Case %d: %d\n",++ke,x);
        }
}
