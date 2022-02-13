#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=1e5+5,M=1e9+7,SEGM=4*N,OO=0x3f3f3f3f;
int t,n,m,k;
int arr[105];
int cost[105][105];
ll mem[105][105][105];

ll solve(int i,int cnt,int lst){
    if(cnt>k) return (ll)1e17;
    if(i==n) return cnt==k?0:(ll)1e17;
    ll &ret=mem[i][cnt][lst];
    if(~ret) return ret;
    if(arr[i]) return solve(i+1,cnt+(arr[i]!=lst),arr[i]);
    ret=1e17;
    for(int col=0;col<m;++col){
        ret=min(ret,solve(i+1,cnt+(col+1!=lst),col+1)+cost[i][col]);
    }
    return ret;
}

int main(){
    //freopen("myfile.txt","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;++i)
        scanf("%d",arr+i);
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            scanf("%d",cost[i]+j);
    memset(mem,-1,sizeof mem);
    printf("%lld",solve(0,0,m+1)>=1e17?-1:solve(0,0,m+1));
    return 0;
}
