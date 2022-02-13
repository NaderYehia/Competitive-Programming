#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=9e7+5,M=2e6+7,OO=0x3f3f3f3f;


int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    char ch;
    int cur=0;
    while(~scanf("%c",&ch)){
        if(ch=='\n') continue;
        if(ch=='#'){
            printf((cur==0)?"YES\n":"NO\n");
            cur=0;
            continue;
        }
        cur=cur*2+(ch-'0');
        cur=cur%131071;
    }

    return 0;
}
