#include<bits/stdc++.h>

using namespace std;

long long mem[201][25][25];
int grid[25][25];
int row[25];
int t,m,c;

int solve(int rem,int i,int j){
    if(i==c)    return 0;
    if(row[i]==j)   return 0;
    if(mem[rem][i][j]!=-1)  return mem[rem][i][j];
    return mem[rem][i][j]=max(solve(rem,i,j+1),rem-grid[i][j]>=0?grid[i][j]+solve(rem-grid[i][j],i+1,0):(int)-1e9);
}

int main() {
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&m,&c);
        int sum=0;
        for(int i=0;i<c;++i){
            scanf("%d",row+i);
            int mn=(int)1e9;
            for(int j=0;j<row[i];++j)
                scanf("%d",grid[i]+j),mn=min(mn,grid[i][j]);
            sum+=mn;
        }
        memset(mem,-1,sizeof mem);
        if(sum>m)
            printf("no solution\n");
        else
            printf("%d\n",solve(m,0,0));
    }
	return 0;
}
