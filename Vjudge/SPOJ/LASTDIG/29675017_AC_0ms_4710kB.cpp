#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e6+10,M=98765431,OO=0x3f3f3f3f;

int power(int b,int p,int m){
    int ret=1;
    while(p){
        if(p&1) ret=(ret*b)%m;
        b=(b*b)%m;
        p>>=1;
    }
    return ret;
}

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    int t;
    scanf("%d",&t);
    while(t--){
        int b,p,m;
        scanf("%d%d",&b,&p);
        m=10;
        printf("%d\n",power(b%m,p,m));


    }

    return 0;
}
