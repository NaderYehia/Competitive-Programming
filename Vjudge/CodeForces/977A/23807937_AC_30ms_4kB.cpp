#include<bits/stdc++.h>

using namespace std;

const int N = 1e6+6,M=1e9+7,OO=0x3f3f3f3f;

int n,m,k,dots;

int main(){
    scanf("%d %d",&n,&m);
    while(m--){
        if(n%10==0)
            n/=10;
        else
            n-=1;
    }
    printf("%d",n);
}
