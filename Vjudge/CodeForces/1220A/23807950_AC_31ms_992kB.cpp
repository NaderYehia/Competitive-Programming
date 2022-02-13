#include<bits/stdc++.h>

using namespace std;

const int N = 1e6+6,M=1e9+7,OO=0x3f3f3f3f;

int n,m,k,dots;
char s[N];

int main(){
    scanf("%d\n%s",&n,s);
    for(int i=0;s[i];++i)
        if(s[i]=='n')
            ++k;
        else if(s[i]=='z')
            ++m;
    while(k--)
        printf("1 ");
    while(m--)
        printf("0 ");
}
