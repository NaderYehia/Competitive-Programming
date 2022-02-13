#include<bits/stdc++.h>

using namespace std;

const int N = 1e3+6,M=1e9+7,OO=0x3f3f3f3f;

int t,n,m,k,sum;
int arr[25];
bool  suc;

void solve(int i){
    if(sum==k)
        suc=true;
    if(i==n)
        return;
    sum+=arr[i];
    solve(i+1);
    sum-=arr[i];
    solve(i+1);
}


int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&k,&n);
        for(int i=0;i<n;++i)
            scanf("%d",arr+i);
        suc=false;
        solve(0);
        if(suc)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
