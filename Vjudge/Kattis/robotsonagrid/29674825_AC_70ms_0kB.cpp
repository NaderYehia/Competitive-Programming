#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e3+10,M=(1<<31)-1,OO=0x3f3f3f3f;

char grid[N][N];
int n;
bool vis[N][N];

bool valid(int r,int c){
    return r>-1&&c>-1&&r<n&&c<n&&grid[r][c]!='#';
}

void dfs(int r,int c){
    vis[r][c]=1;
    for(int i=-1;i<2;++i){
        for(int j=-1;j<2;++j){
            if(abs(i)==abs(j)) continue;
            if(valid(r+i,c+j)&&!vis[r+i][c+j]){
                dfs(r+i,c+j);
            }
        }
    }
}


int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%s",grid[i]);

    vector<vector<int> > dp(n,vector<int>(n,0));

    for(int i=0;i<n;++i){
        if(grid[0][i]=='#') break;
        dp[0][i]=1;
    }
    for(int i=0;i<n;++i){
        if(grid[i][0]=='#') break;
        dp[i][0]=1;
    }

    for(int i=1;i<n;++i){
        for(int j=1;j<n;++j){
            if(grid[i][j]=='#') continue;
            dp[i][j]=(1ll*dp[i-1][j]+dp[i][j-1])%M;
        }
    }

    if(dp[n-1][n-1]==0){
        if(grid[0][0]!='#') dfs(0,0);
        if(vis[n-1][n-1]) printf("THE GAME IS A LIE\n");
        else printf("INCONCEIVABLE\n");
    }
    else{
        printf("%d\n",dp[n-1][n-1]);
    }

    return 0;
}
