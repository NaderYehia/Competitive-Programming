#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+6,M=1e9+7,OO=0x3f3f3f3f;

int n,boo[105],sr,sc,er,ec;
bool grid[105][N];
int dis[105][N];

int bfs(int u,int v){
    memset(dis,OO,sizeof dis);
    queue<pair<int,int> >q;
    q.push({u,v});
    dis[u][v]=0;
    while(q.size()){
        int r=q.front().first;
        int c=q.front().second;
        q.pop();
        if(r==er&&c==ec)
            return dis[r][c];
        if(r>0){
            if(c<=boo[r-1]&&dis[r-1][c]==OO)
                q.push({r-1,c}),dis[r-1][c]=dis[r][c]+1;
            else if(c>boo[r-1]&&dis[r-1][boo[r-1]]==OO)
                q.push({r-1,boo[r-1]}),dis[r-1][boo[r-1]]=dis[r][c]+1;
        }
        if(r<n-1){
            if(c<=boo[r+1]&&dis[r+1][c]==OO)
                q.push({r+1,c}),dis[r+1][c]=dis[r][c]+1;
            else if(c>boo[r+1]&&dis[r+1][boo[r+1]]==OO)
                q.push({r+1,boo[r+1]}),dis[r+1][boo[r+1]]=dis[r][c]+1;
        }
        if(c>0&dis[r][c-1]==OO){
            q.push({r,c-1}),dis[r][c-1]=dis[r][c]+1;
        }
        if(c<boo[r]&&dis[r][c+1]==OO)
            q.push({r,c+1}),dis[r][c+1]=dis[r][c]+1;
    }

}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",boo+i);
        for(int j=0;j<=boo[i];++j)
            grid[i][j]=1;
    }
    scanf("%d%d%d%d",&sr,&sc,&er,&ec);
    --sr,--sc,--er,--ec;
    printf("%d",bfs(sr,sc));
    return 0;
}
