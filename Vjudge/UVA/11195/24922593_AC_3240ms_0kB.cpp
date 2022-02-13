#include<bits/stdc++.h>

using namespace std;

const int N=2e3+5;
int t,n,m,cnt;
char grid[20][20];
bool cols[20];
bool ld[50];
bool rd[50];


void solve(int i){
    if(i==n){
        ++cnt;
        return;
    }
    for(int j=0;j<n;++j){
        if(grid[i][j]!='*'&&!cols[j]&&!ld[i+j]&&!rd[abs(j-i+n-1)]){
            cols[j]=1;
            ld[i+j]=1;
            rd[abs(j-i+n-1)]=1;
            solve(i+1);
            cols[j]=0;
            ld[i+j]=0;
            rd[abs(j-i+n-1)]=0;
        }
    }
}

int main() {
    while(~scanf("%d",&n),n){
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                cin>>grid[i][j];
        cnt=0;
        solve(0);
        printf("Case %d: %d\n",++t,cnt);
    }
    return 0;
}
