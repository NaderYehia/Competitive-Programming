#include<bits/stdc++.h>

using namespace std;

int n,kk;
int arr[15][15];

int main(){
    while(scanf("%d",&n),n){
        printf("Case %d:",++kk);
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                scanf("%d",arr[i]+j);
        for(int i=0;i<n/2;++i){
            int sum=0;
            for(int j=i;j<n-i;++j)
                sum+=arr[i][j];
            for(int j=i;j<n-i;++j)
                sum+=arr[n-i-1][j];
            for(int j=i+1;j<n-i-1;++j)
                sum+=arr[j][i];
            for(int j=i+1;j<n-i-1;++j)
                sum+=arr[j][n-i-1];
            printf(" %d",sum);
            sum=0;
        }
        if(n&1)
            printf(" %d",arr[n/2][n/2]);
        puts("");
    }
    return 0;
}
