#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e6+10,M=1e9,OO=0x3f3f3f3f;


int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    int n,m,c;
    while(~scanf("%d%d%d",&n,&m,&c),n||m||c){
        int cur=c;
        if(n%2!=m%2) cur=1-cur;

        int ans=0;
        if(cur){
            ans=((n+1)/2)*((m+1)/2);
            ans+=(n/2)*(m/2);
        }
        else{
            ans=((n+1)/2)*(m/2);
            ans+=((m+1)/2)*(n/2);
        }

        if(c){
            ans-=(n+1)/2*4;
            ans-=n/2*3;
            ans-=(m+1)/2*4;
            ans-=m/2*3;
            ans+=25;
        }
        else{
            ans-=(n+1)/2*3;
            ans-=n/2*4;
            ans-=(m+1)/2*3;
            ans-=m/2*4;
            ans+=24;
        }

        printf("%d\n",ans);

    }

    return 0;
}
