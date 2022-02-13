#include<bits/stdc++.h>

using namespace std;

int n,m;
int arr[10005];

bool srt(int i,int j){
    if(i%m!=j%m)
        return i%m<j%m;
    if(i&1){
        if(j&1)
            return i>j;
        return true;
    }
    if(j&1)
        return false;
    return i<j;
}

int main(){
    while(scanf("%d%d",&n,&m),printf("%d %d\n",n,m),n){
        for(int i=0;i<n;++i)
            scanf("%d",arr+i);
        sort(arr,arr+n,srt);
        for(int i=0;i<n;++i)
            printf("%d\n",arr[i]);
    }
    return 0;
}
