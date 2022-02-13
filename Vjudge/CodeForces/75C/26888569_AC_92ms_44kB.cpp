#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=1e6+5,M=2<<30,OO=0x3f3f3f3f;
int t,n,m,k;

int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}

int main(){
    //freopen("myfile.txt","w",stdout);
    scanf("%d%d",&n,&m);
    int g=gcd(n,m);
    vector<int> v;
    for(int i=1;i<=g/i;++i){
        if(g%i==0){
            v.push_back(i);
            if(g/i!=i) v.push_back(g/i);
        }
    }
    sort(v.begin(),v.end());
    scanf("%d",&t);
    while(t--){
        int a,b;
        scanf("%d%d",&a,&b);
        int idx=upper_bound(v.begin(),v.end(),b)-v.begin()-1;
        if(v[idx]>=a&&v[idx]<=b)
            printf("%d\n",v[idx]);
        else printf("-1\n");
    }
    return 0;
}
