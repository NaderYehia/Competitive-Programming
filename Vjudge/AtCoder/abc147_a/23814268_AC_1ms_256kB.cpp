#include<bits/stdc++.h>

using namespace std;

const int N = 1e6+6,M=1e9+7,OO=0x3f3f3f3f;

int n,m,k,dots;
string s;

int main(){
    scanf("%d%d%d",&n,&m,&k);
    if(n+m+k<22)
        printf("win");
    else
        printf("bust");
    return 0;
}
