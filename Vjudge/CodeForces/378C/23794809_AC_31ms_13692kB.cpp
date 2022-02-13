#include<bits/stdc++.h>

using namespace std;

const int N = 1e6+6,M=1e9+7,OO=0x3f3f3f3f;

int n,m,k,dots;
char grid[1005][1005];
int arr[]={0,1,-1};
bool vis[1005][1005];

bool valid(int i,int j){
    return i<n&&j<m&&i>-1&&j>-1;
}
void print(){
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            if(grid[i][j]=='.'&&!vis[i][j])
                grid[i][j]='X';
    for(int i=0;i<n;++i)
        printf("%s\n",grid[i]);
}

void dfs(int u,int v){
    vis[u][v]=1;
    if(--dots==0)
        print();
    for(int i=0;i<3;++i){
        for(int j=0;j<3;++j){
            if(abs(arr[i])==abs(arr[j]))
                continue;
            if(valid(u+arr[i],v+arr[j])&&grid[u+arr[i]][v+arr[j]]=='.'&&!vis[u+arr[i]][v+arr[j]])
                dfs(u+arr[i],v+arr[j]);
        }
    }

}

int main(){
    scanf("%d %d %d\n",&n,&m,&k);
    for(int i=0;i<n;++i)
        scanf("%s",grid[i]);
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            if(grid[i][j]=='.')
                ++dots;
    dots-=k;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            if(grid[i][j]=='.')
                dfs(i,j);
    return 0;
}
