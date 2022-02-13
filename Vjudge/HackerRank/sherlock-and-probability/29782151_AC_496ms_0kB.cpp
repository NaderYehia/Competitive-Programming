#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e5+10,M=2e4+7,OO=0x3f3f3f3f;
const double eps=1e-9;

char s[N];

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    int t;
    scanf("%d",&t);
    while(t--){
        int n,k;
        scanf("%d%d",&n,&k);
        scanf("%s",s);

        vector<int> pre(n+1,0);
        for(int i=1;i<=n;++i)
            pre[i]=pre[i-1]+(s[i-1]=='1');

        ll all=0,cnt=0;
        for(int i=0;i<n;++i){
            all+=(max(0,i-k))+(min(n-1,i+k)+1);
            if(s[i]=='0') continue;
            cnt+=pre[min(n,i+k+1)]-pre[max(0,i-k)];
        }

        printf("%lld/%lld\n",cnt/__gcd(cnt,all),all/__gcd(cnt,all));
    }

    return 0;
}
