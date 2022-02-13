#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=3e4+5,M=1e9+7,SEGM=4*N,OO=0x3f3f3f3f;
int t,n,m;
char grid[305][305];
int dis[305][305][5];

bool validrc(int r,int c){
    return r>-1&&c>-1&&r<n&&c<m&&grid[r][c]!='#';
}

bool valid(int cr,int ci,int cc,int cj,int cm){
    for(int i=1;i<=cm;++i)
        if(!validrc(cr+ci*i,cc+cj*i))
            return 0;
    return 1;
}

int nxtCurm(int x){
    ++x;
    return x%3==0?3:x%3;
}

int bfs(int i,int j){
    memset(dis,-1,sizeof dis);
    queue<pair<pair<int,int>,int> >q;
    q.push(make_pair(make_pair(i,j),1));
    dis[i][j][1]=0;
    while(q.size()){
        int curi=q.front().first.first;
        int curj=q.front().first.second;
        int curm=q.front().second;
        q.pop();
        if(grid[curi][curj]=='E') return dis[curi][curj][curm];
        for(int i=-1;i<2;++i){
            for(int j=-1;j<2;++j){
                if(abs(i)==abs(j)) continue;
                if(valid(curi,i,curj,j,curm)&&dis[curi+i*curm][curj+j*curm][nxtCurm(curm)]==-1){
                    q.push(make_pair(make_pair(curi+i*curm,curj+j*curm),nxtCurm(curm)));
                    dis[curi+i*curm][curj+j*curm][nxtCurm(curm)]=dis[curi][curj][curm]+1;
                }
            }
        }
    }
    return -1;
}

int main(){
    //freopen("myfile.txt","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;++i)
            scanf("%s",grid+i);
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]=='S'){
                    int ans=bfs(i,j);
                    ans==-1?printf("NO\n"):printf("%d\n",ans);
                    break;
                }
            }
        }
    }
    return 0;
}
