#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e5+5,M=1e9+7,OO=0x3f3f3f3f;
const double eps=1e-6,pi=acos(-1);
int t,n,m,k;
int arr[N];

bool can(int x){
    int tmp=k,prv=-1e9;
    for(int i=0;i<n;++i){
        if(arr[i]>prv){
            --tmp;
            prv=arr[i]+x-1;
        }
    }
    return tmp>=0;
}

int bs(){
    int lo=0,hi=1e9,mid;
    while(lo<hi){
        mid=lo+(hi-lo)/2;
        if(can(mid)) hi=mid;
        else lo=mid+1;
    }
    return lo;
}

int main(){
    //freopen("myfile.txt","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;++i)
            scanf("%d",arr+i);
        printf("%d\n",bs());
    }
    return 0;
}
