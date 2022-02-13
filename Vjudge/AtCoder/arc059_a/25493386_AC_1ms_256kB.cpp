#include<bits/stdc++.h>

using namespace std;

const int N=2e5+5,OO=0x3f3f3f3f,M=1e9+7;
int t,n,m,k;
int arr[200];

int tr(int x){
    int ret=0;
    for(int i=0;i<n;++i){
        ret+=(arr[i]-x)*(arr[i]-x);
    }
    return ret;
}

int main() {
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",arr+i);
    int mn=OO;
    for(int i=-100;i<101;++i){
        mn=min(mn,tr(i));
    }
    cout<<mn;
    return 0;
}
