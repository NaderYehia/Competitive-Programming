#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=5e2+5,M=1e8,SEGM=4*N,OO=0x3f3f3f3f;
int t,n,m,k;
int arr[N];
int d[N][N];

int main(){
    //freopen("myfile.txt","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            scanf("%d",d[i]+j);
    for(int i=0;i<n;++i)
        scanf("%d",arr+i),--arr[i];
    reverse(arr,arr+n);
    vector<ll> ans;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(j==arr[i]) continue;
            for(int k=0;k<n;++k){
                if(k==arr[i]) continue;
                d[j][k]=min(d[j][k],d[j][arr[i]]+d[arr[i]][k]);
            }
        }
        ll tmp=0;
        for(int j=0;j<=i;++j)
            for(int k=0;k<=i;++k)
                tmp+=d[arr[j]][arr[k]];
        ans.push_back(tmp);
    }
    for(int i=ans.size()-1;i>-1;--i)
        printf("%lld%c",ans[i]," \n"[i==0]);
    return 0;
}
