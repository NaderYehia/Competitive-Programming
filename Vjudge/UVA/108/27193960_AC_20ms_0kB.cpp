#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=1e5+5,M=1e9+7,SEGM=4*N,OO=0x3f3f3f3f;
int t,n,m,k;
int arr[105][105];


int main(){
    //freopen("myfile.txt","w",stdout);
    while(~scanf("%d",&n)){
        //memset(arr,0,sizeof arr);
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                scanf("%d",arr[i]+j),arr[i][j]+=arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1];
        int mx=101*-127;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                for(int ii=i;ii<=n;++ii)
                    for(int jj=j;jj<=n;++jj)
                        mx=max(mx,arr[ii][jj]-arr[i-1][jj]-arr[ii][j-1]+arr[i-1][j-1]);
        printf("%d\n",mx);
    }
    return 0;
}
