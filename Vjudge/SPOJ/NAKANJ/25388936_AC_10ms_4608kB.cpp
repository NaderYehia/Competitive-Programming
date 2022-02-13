#include<bits/stdc++.h>

using namespace std;

const int N=1e3+5,OO=0x3f3f3f3f;
int t,n,m,k;
char s1[4],s2[4];
int grid[15][15];
int dx[]={2,2,-2,-2,1,-1,1,-1};
int dy[]={1,-1,1,-1,2,2,-2,-2};

bool valid(int x,int y){
    return x>-1&&x<8&&y>-1&&y<8;
}

void bfs(int stx,int sty){
    memset(grid,-1,sizeof grid);
    queue< pair<int,int> > q;
    q.push({stx,sty});
    grid[stx][sty]=0;
    while(q.size()){
        int r=q.front().first;
        int c=q.front().second;
        q.pop();
        for(int i=0;i<8;++i){
            int nxtx=r+dx[i];
            int nxty=c+dy[i];
            if(valid(nxtx,nxty)&&grid[nxtx][nxty]==-1){
                q.push({nxtx,nxty}),grid[nxtx][nxty]=grid[r][c]+1;
            }
        }
    }
}

int main() {
    scanf("%d",&t);
    while(t--){
        scanf("%s %s",s1,s2);
        int stx=s1[0]-'a';
        int sty=s1[1]-'1';
        int enx=s2[0]-'a';
        int eny=s2[1]-'1';
        bfs(stx,sty);
        printf("%d\n",grid[enx][eny]);
    }
    return 0;
}
