#include<bits/stdc++.h>

using namespace std;

const int N=2e3+5;
int t,n,m;
int arr[2005];
int meml[2005];
int memd[2005];

int lis(int i){
    if(meml[i]!=-1) return meml[i];
    int ret=1;
    for(int j=i+1;j<n;++j)
        if(arr[j]>arr[i])
            ret=max(ret,1+lis(j));
    return meml[i]=ret;
}

int dis(int i){
    if(~memd[i]) return memd[i];
    int ret=1;
    for(int j=i+1;j<n;++j)
        if(arr[j]<arr[i])
            ret=max(ret,1+dis(j));
    return memd[i]=ret;
}

int main() {
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;++i)
            scanf("%d",arr+i);
        int mx=0;
        memset(meml,-1,sizeof meml);
        memset(memd,-1,sizeof memd);
        for(int i=0;i<n;++i)
            mx=max(mx,lis(i)+dis(i)-1);
        printf("%d\n",mx);
    }
    return 0;
}
