#include<bits/stdc++.h>

using namespace std;

int t,n;
int arr[2005];
int meml[2005];
int memd[2005];

int lis(int lst){
    if(meml[lst]!=-1) return meml[lst];
    int ret=1;
    for(int j=lst+1;j<n;++j){
        if(arr[j]>arr[lst])
            ret=max(ret,1+lis(j));
    }
    return meml[lst]=ret;
}

int dis(int lst){
    if(memd[lst]!=-1) return memd[lst];
    int ret=1;
    for(int j=lst+1;j<n;++j){
        if(arr[j]<arr[lst])
            ret=max(ret,1+dis(j));
    }
    return memd[lst]=ret;
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
        for(int i=0;i<n;++i){
            mx=max(mx,lis(i)+dis(i)-1);
        }
        printf("%d\n",mx);
    }
    return 0;
}
