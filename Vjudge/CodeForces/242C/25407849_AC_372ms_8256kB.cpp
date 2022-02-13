#include<bits/stdc++.h>

using namespace std;

const int N=1e6+5,OO=0x3f3f3f3f;
int n,m,k;
map<pair<int,int> ,int> vis;

int bfs(int stx,int sty,int enx,int eny){
    queue<pair<int,int> > q;
    q.push({stx,sty});
    vis[{stx,sty}]=0;
    while(q.size()){
        int r=q.front().first;
        int c=q.front().second;
        q.pop();
        if(r==enx&&c==eny) return vis[{r,c}];
        for(int i=-1;i<2;++i){
            for(int j=-1;j<2;++j){
                int nx=r+i;
                int ny=c+j;
                if(vis[{nx,ny}]==-1){
                    q.push({nx,ny}),vis[{nx,ny}]=vis[{r,c}]+1;
                }
            }
        }
    }
    return -1;
}

int main() {
    int stx,sty,enx,eny;
    scanf("%d%d%d%d",&stx,&sty,&enx,&eny);
    scanf("%d",&n);
    for(int i=0,r,a,b;i<n;++i){
        scanf("%d%d%d",&r,&a,&b);
        for(int i=a;i<=b;++i)
            vis[{r,i}]=-1;
    }
    printf("%d",bfs(stx,sty,enx,eny));
    return 0;
}
