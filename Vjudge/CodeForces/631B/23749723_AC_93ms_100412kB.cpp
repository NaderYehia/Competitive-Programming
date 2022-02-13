#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+6,M=1e9+7,OO=0x3f3f3f3f;

int n,m,k;
int grid[5005][5005];
bool vis[3][5005];
vector<pair<pair<int,int>,int> > v;

int main(){
    scanf("%d %d %d",&n,&m,&k);
    while(k--){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        v.push_back(make_pair(make_pair(a,b),c));
    }
    for(int i=v.size()-1;i>=0;--i){
        int a=v[i].first.first;
        int b=v[i].first.second;
        int c=v[i].second;
        if(!vis[a][b]){
            if(a==1){
                for(int i=0;i<m;++i)
                    if(grid[b-1][i]==0)
                        grid[b-1][i]=c;
            }
            else if(a==2){
                for(int i=0;i<n;++i)
                    if(grid[i][b-1]==0)
                        grid[i][b-1]=c;
            }
            vis[a][b]=1;
        }
    }
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            printf("%d%c",grid[i][j]," \n"[j==m-1]);
    return 0;
}
