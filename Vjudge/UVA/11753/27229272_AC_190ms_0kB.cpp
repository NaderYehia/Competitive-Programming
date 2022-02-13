#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=1e4+5,M=1e9+7,SEGM=4*N,OO=0x3f3f3f3f;
int t,n,m,k;
int arr[N];

int solve(int i=0,int j=n-1,int ops=0){
    if(ops>k) return OO;
    if(i>=j) return 0;
    if(arr[i]==arr[j]) return solve(i+1,j-1,ops);
    return min(solve(i+1,j,ops+1)+1,solve(i,j-1,ops+1)+1);
}

bool pal(){
    int i=0,j=n-1;
    while(i<j){
        if(arr[i]!=arr[j]) return 0;
        ++i,--j;
    }
    return 1;
}

int main(){
    //freopen("myfile.txt","w",stdout);
    int tc=1;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;++i)
            scanf("%d",arr+i);
        if(pal()){
            printf("Case %d: Too easy\n",tc++);
            continue;
        }
        if(!k){
            printf("Case %d: Too difficult\n",tc++);
            continue;
        }
        int ans=solve();
        if(ans>=OO){
            printf("Case %d: Too difficult\n",tc++);
            continue;
        }
        printf("Case %d: %d\n",tc++,ans);
    }
    return 0;
}
