#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=2e4+5,OO=0x3f3f3f3f;
int t,n,m,l,w;
int kn[N];
int dr[N];

int main(){
    //freopen("myfile.txt","w",stdout);
    while(~scanf("%d%d",&n,&m),(n+m)){
        for(int i=0;i<n;++i)
            scanf("%d",kn+i);
        for(int i=0;i<m;++i)
            scanf("%d",dr+i);
        sort(kn,kn+n);
        sort(dr,dr+m);
        int j=0,cnt=0;
        for(int i=0;i<m;++i){
            if(j==n)break;
            if(dr[i]>=kn[j])
                ++j,cnt+=dr[i];
        }
        if(j==n) printf("%d\n",cnt);
        else printf("Loowater is doomed!\n");
    }
    return 0;
}
