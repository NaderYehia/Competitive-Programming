#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=1e5+5,M=1e9+7,OO=0x3f3f3f3f;
int t,n,m,k;
char grid[200][200];
bool vis[200][200];
int ans[200][200];

bool valid(int r,int c){
    return r>-1&&c>-1&&r<n&&c<m;
}

void bfs(){
    queue< pair<int,int> > q;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            if(grid[i][j]=='1')
                q.push({i,j}),vis[i][j]=1,ans[i][j]=0;
    while(q.size()){
        int r=q.front().first;
        int c=q.front().second;
        q.pop();
        for(int i=-1;i<2;++i){
            for(int j=-1;j<2;++j){
                if(abs(i)==abs(j)) continue;
                if(valid(r+i,c+j)&&!vis[r+i][c+j])
                    q.push({r+i,c+j}),vis[r+i][c+j]=1,ans[r+i][c+j]=ans[r][c]+1;
            }
        }
    }

}

int main(){
    //freopen("myfile.txt","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d%d\n",&n,&m);
        for(int i=0;i<n;++i)
            scanf("%s",grid[i]);
        memset(vis,0,sizeof vis);
        bfs();
        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j)
                printf("%d%c",ans[i][j]," \n"[j+1==m]);
    }
    return 0;
}
