#include<bits/stdc++.h>

using namespace std;

const int N=1e5+5,OO=0x3f3f3f3f;
int t,n,k;
int x[N],h[N];

int main() {
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d%d",x+i,h+i);
    int cnt=0,lst=-OO;
    for(int i=0;i<n-1;++i){
        if(x[i]-h[i]>lst)
            ++cnt,lst=x[i];
        else if(x[i]+h[i]<x[i+1])
            ++cnt,lst=x[i]+h[i];
        else
            lst=x[i];
    }
    printf("%d",cnt+1);
    return 0;
}
