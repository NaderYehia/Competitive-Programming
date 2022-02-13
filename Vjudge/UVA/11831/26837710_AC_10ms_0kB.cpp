#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=1e5+5,M=1e9+7,OO=0x3f3f3f3f;
int t,n,m,k;
char grid[105][105];
char inst[N];
int stk;

bool valid(int u,int v){
    return u>-1&&v>-1&&u<n&&v<m&&grid[u][v]!='#';
}

void dfs(int r,int c,int idx){
    if(idx==k)
        return;
    if(inst[idx]=='D'){
        if(grid[r][c]=='N')
            grid[r][c]='L';
        else if(grid[r][c]=='L')
            grid[r][c]='S';
        else if(grid[r][c]=='S')
            grid[r][c]='O';
        else if(grid[r][c]=='O')
            grid[r][c]='N';
        dfs(r,c,idx+1);
    }
    else if(inst[idx]=='E'){
        if(grid[r][c]=='N')
            grid[r][c]='O';
        else if(grid[r][c]=='L')
            grid[r][c]='N';
        else if(grid[r][c]=='S')
            grid[r][c]='L';
        else if(grid[r][c]=='O')
            grid[r][c]='S';
        dfs(r,c,idx+1);
    }
    else if(inst[idx]=='F'){
        if(grid[r][c]=='N'){
            if(valid(r-1,c)){
                if(grid[r-1][c]=='*') ++stk;
                grid[r-1][c]=grid[r][c];
                grid[r][c]='.';
                dfs(r-1,c,idx+1);
            }else{
                dfs(r,c,idx+1);
            }
        }
        else if(grid[r][c]=='S'){
            if(valid(r+1,c)){
                if(grid[r+1][c]=='*') ++stk;
                grid[r+1][c]=grid[r][c];
                grid[r][c]='.';
                dfs(r+1,c,idx+1);
            }else{
                dfs(r,c,idx+1);
            }
        }
        else if(grid[r][c]=='L'){
            if(valid(r,c+1)){
                if(grid[r][c+1]=='*') ++stk;
                grid[r][c+1]=grid[r][c];
                grid[r][c]='.';
                dfs(r,c+1,idx+1);
            }else{
                dfs(r,c,idx+1);
            }
        }
        else if(grid[r][c]=='O'){
            if(valid(r,c-1)){
                if(grid[r][c-1]=='*') ++stk;
                grid[r][c-1]=grid[r][c];
                grid[r][c]='.';
                dfs(r,c-1,idx+1);
            }else{
                dfs(r,c,idx+1);
            }
        }
    }
}

int main(){
    //freopen("myfile.txt","w",stdout);
    while(~scanf("%d%d%d",&n,&m,&k),(n+m+k)){
        for(int i=0;i<n;++i)
            scanf("%s",grid[i]);
        scanf("%s",inst);
        stk=0;
        bool done=0;
        for(int i=0;i<n&&!done;++i){
            for(int j=0;j<m&&!done;++j){
                if(grid[i][j]>='A'&&grid[i][j]<='Z'){
                    dfs(i,j,0);
                    done=1;
                }
            }
        }
        printf("%d\n",stk);
    }
    return 0;
}
