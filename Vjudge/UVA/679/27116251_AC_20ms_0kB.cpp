#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=1e4+5,M=1e9+7,SEGM=4*N,OO=0x3f3f3f3f;
int t,w,n,l;

int main(){
    //freopen("myfile.txt","w",stdout);
    scanf("%d",&t);
    while(t--){
        int ans=1;
        scanf("%d%d",&n,&l);
        for(int i=1;i<n;++i){
            if(!l) ans*=2;
            else if(l&1) ans*=2;
            else ans=ans*2+1;
            l=(l+1)/2;
        }
        printf("%d\n",ans);
    }
    return 0;
}
