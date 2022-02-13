#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e3+10,M=2e4+7,OO=0x3f3f3f3f;
const double eps=1e-6;



int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    int t;
    scanf("%d",&t);
    while(t--){
        int n,s,q;
        scanf("%d%d%d",&n,&s,&q);
        stack<int> carrier;
        vector<queue<int> > qs(n);
        int rem=0;
        for(int i=0;i<n;++i){
            int qi;
            scanf("%d",&qi);
            for(int j=0;j<qi;++j){
                int x;
                scanf("%d",&x);
                qs[i].push(x);
                ++rem;
            }
        }

        int cnt=0;
        for(int i=0;rem;i=(i+1)%n){
            cnt+=2;
            while(carrier.size()){
                if(carrier.top()==i+1) carrier.pop(),--rem,++cnt;
                else if(qs[i].size()<q) qs[i].push(carrier.top()),carrier.pop(),++cnt;
                else break;
            }
            while(carrier.size()<s&&qs[i].size()) carrier.push(qs[i].front()),qs[i].pop(),++cnt;
        }
        printf("%d\n",cnt-2);
    }

    return 0;
}
