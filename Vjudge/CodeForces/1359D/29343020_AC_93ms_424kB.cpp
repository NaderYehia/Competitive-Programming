#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e5+10,M=2e6+7,OO=0x3f3f3f3f;

int n,arr[N];

int kadane(int cur){
    int sum=0,mx=0;
    for(int i=0;i<n;++i){
        sum+=arr[i];
        if(arr[i]>cur||sum<0){
            sum=0;
        }
        mx=max(mx,sum);
    }
    return mx-cur;
}

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",arr+i);

    int ans=0;
    for(int i=1;i<=30;++i)
        ans=max(ans,kadane(i));
    printf("%d\n",ans);

    return 0;
}
