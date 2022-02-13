#include<bits/stdc++.h>

using namespace std;

const int N = 1e6+6,M=1e9+7,OO=0x3f3f3f3f;

int n,m,k;
int row[1005],col[1005];
int grid[1005][1005];

int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            scanf("%d",&grid[i][j]);
    for(int i=0;i<n;++i)
        row[i]=i;
    for(int i=0;i<m;++i)
        col[i]=i;
    while(k--){
        char c;int a,b;
        scanf("\n%c%d%d",&c,&a,&b);
        --a,--b;
        if(c=='g')
            printf("%d\n",grid[row[a]][col[b]]);
        else if(c=='r')
            swap(row[a],row[b]);
        else
            swap(col[a],col[b]);
    }
    return 0;
}
