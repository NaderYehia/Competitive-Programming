#include<bits/stdc++.h>
 
using namespace std;
 
const int N = 1e6+6,M=1e9+7,OO=0x3f3f3f3f;
 
long long n,y,x;
 
int main(){
    scanf("%lld %lld %lld",&n,&x,&y);
    if((y-n+1)*1ll*(y-n+1)+n-1<x||(y-n+1)<=0)
        printf("-1\n");
    else
    {
        for(int i=0;i<n-1;++i)
            printf("1\n");
        printf("%lld",y-n+1);
    }
    return 0;
}