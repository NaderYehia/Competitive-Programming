#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=2e3+5,M=1e9+7,OO=0x3f3f3f3f;
const double eps=1e-6,pi=acos(-1);
int t,n,k,a,b,m;
int arr[N];
int asc[N];
int dsc[N];

int main(){
    //freopen("myfile.txt","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;++i)
            scanf("%d",arr+i);
        for(int i=n-1;i>=0;--i){
            int ret=1;
            for(int j=n-1;j>i;--j){
                if(arr[i]>arr[j])
                    ret=max(ret,asc[j]+1);
            }
            asc[i]=ret;
        }
        for(int i=n-1;i>=0;--i){
            int ret=1;
            for(int j=n-1;j>i;--j){
                if(arr[i]<arr[j])
                    ret=max(ret,dsc[j]+1);
            }
            dsc[i]=ret;
        }
        int mx=0;
        for(int i=0;i<n;++i)
            mx=max(mx,asc[i]+dsc[i]-1);
        printf("%d\n",mx);
    }
    return 0;
}
