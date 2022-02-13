#include<bits/stdc++.h>

using namespace std;

const int N = 1e6+6,M=1e9+7,OO=0x3f3f3f3f;

int n,m,k,dots;

int main(){
    scanf("%d %d",&n,&m);
    printf("%d\n",min(n,m)+1);
    for(int i=0;i<=min(n,m);++i)
        printf("%d %d\n",i,min(n,m)-i);
    return 0;
}
