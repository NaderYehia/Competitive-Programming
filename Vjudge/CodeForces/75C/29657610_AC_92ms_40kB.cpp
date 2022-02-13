#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e3+10,M=1e3+7,OO=0x3f3f3f3f;


int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    int a,b;
    scanf("%d%d",&a,&b);
    int g=__gcd(a,b);

    vector<int> divs;
    for(int i=1;i<=g/i;++i){
        if(g%i==0){
            divs.push_back(i);
            if(g/i!=i) divs.push_back(g/i);
        }
    }
    sort(divs.begin(),divs.end());

    int q;
    scanf("%d",&q);
    while(q--){
        int l,r;
        scanf("%d%d",&l,&r);
        int lo=lower_bound(divs.begin(),divs.end(),l)-divs.begin();
        int hi=upper_bound(divs.begin(),divs.end(),r)-divs.begin();
        if(lo==hi) printf("-1\n");
        else printf("%d\n",divs[hi-1]);
    }

    return 0;
}
