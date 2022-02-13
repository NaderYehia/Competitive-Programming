#include<bits/stdc++.h>

using namespace std;

const int N=1e3+5,OO=0x3f3f3f3f;
int t,n,m,k;
char grid[105][105];
int dis[105][105][20];

bool valid(int x,int y){
    return x>-1&&y>-1&&x<n&&y<m&&grid[x][y]!='#';
}

int bfs(int stx,int sty){
    memset(dis,-1,sizeof dis);
    queue<pair< pair<int,int> , int > > q;
    dis[stx][sty][0]=0;
    q.push(make_pair(make_pair(stx,sty),0));
    while(q.size()){
        int r=q.front().first.first;
        int c=q.front().first.second;
        int col=q.front().second;
        q.pop();
        for(int i=-1;i<2;++i){
            for(int j=-1;j<2;++j){
                if(abs(i)==abs(j))continue;
                int nx=r+i,ny=c+j;
                if(valid(nx,ny)&&dis[nx][ny][col]==-1){
                    if(grid[nx][ny]=='X')
                        return dis[r][c][col]+1;
                    if(grid[nx][ny]=='r'){
                        dis[nx][ny][col|1<<0]=dis[r][c][col]+1,q.push(make_pair(make_pair(nx,ny),col|1<<0));
                    }
                    if(grid[nx][ny]=='g'){
                        dis[nx][ny][col|1<<1]=dis[r][c][col]+1,q.push(make_pair(make_pair(nx,ny),col|1<<1));
                    }
                    if(grid[nx][ny]=='b'){
                        dis[nx][ny][col|1<<2]=dis[r][c][col]+1,q.push(make_pair(make_pair(nx,ny),col|1<<2));
                    }
                    if(grid[nx][ny]=='y'){
                        dis[nx][ny][col|1<<3]=dis[r][c][col]+1,q.push(make_pair(make_pair(nx,ny),col|1<<3));
                    }
                    if(grid[nx][ny]=='.'){
                        dis[nx][ny][col]=dis[r][c][col]+1,q.push(make_pair(make_pair(nx,ny),col));
                    }
                    if(grid[nx][ny]=='*'){
                        dis[nx][ny][col]=dis[r][c][col]+1,q.push(make_pair(make_pair(nx,ny),col));
                    }
                    if(grid[nx][ny]=='R'){
                        if(col&(1<<0))
                            dis[nx][ny][col]=dis[r][c][col]+1,q.push(make_pair(make_pair(nx,ny),col));
                    }
                    if(grid[nx][ny]=='G'){
                        if(col&(1<<1))
                            dis[nx][ny][col]=dis[r][c][col]+1,q.push(make_pair(make_pair(nx,ny),col));
                    }
                    if(grid[nx][ny]=='B'){
                        if(col&(1<<2))
                            dis[nx][ny][col]=dis[r][c][col]+1,q.push(make_pair(make_pair(nx,ny),col));
                    }
                    if(grid[nx][ny]=='Y'){
                        if(col&(1<<3))
                            dis[nx][ny][col]=dis[r][c][col]+1,q.push(make_pair(make_pair(nx,ny),col));
                    }
                }
            }
        }
    }
    return -1;
}

int main() {
    while(~scanf("%d%d",&n,&m),(n+m)){
        int stx,sty;
        for(int i=0;i<n;++i){
            scanf("%s",grid+i);
            for(int j=0;j<m;++j){
                if(grid[i][j]=='*')
                    stx=i,sty=j;
            }
        }
        int ans=bfs(stx,sty);
        if(!~ans) printf("The poor student is trapped!\n");
        else printf("Escape possible in %d steps.\n",ans);
    }
    return 0;
}
