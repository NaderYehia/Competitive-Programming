#include<bits/stdc++.h>

using namespace std;

const int N=2e5+5,OO=0x3f3f3f3f,M=1e9+7;
int t,n,m,k;
char grid[100][100];
bool vis[100][100];
bool hasCycle;

bool valid(int r,int c){
    return r>-1&&r<n&&c>-1&&c<m;
}

void dfs(int r,int c,int pr,int pc){
    vis[r][c]=1;
    for(int i=-1;i<2;++i){
        for(int j=-1;j<2;++j){
            if(abs(i)==abs(j))continue;
            if(valid(r+i,c+j)&&grid[r+i][c+j]==grid[r][c]){
                if(!vis[r+i][c+j]) dfs(r+i,c+j,r,c);
                else if(pr!=r+i&&pc!=c+j) hasCycle=1;
            }
        }
    }
}

int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)
        scanf("%s",grid+i);
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(!vis[i][j]){
                dfs(i,j,-1,-1);
            }
        }
    }
    hasCycle?printf("Yes"):printf("No");
    return 0;
}
