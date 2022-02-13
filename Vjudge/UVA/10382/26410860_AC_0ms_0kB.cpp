#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e3+5,OO=0x3f3f3f3f;
ll t,n,m,l,w;
vector<pair<double,double> > v;

int main(){
    //freopen("myfile.txt","w",stdout);
    while(~scanf("%lld%lld%lld",&n,&l,&w)){
        v.clear();
        for(ll i=0,x,r;i<n;++i){
            scanf("%lld%lld",&x,&r);
            double dx=0;
            if((double)r>w/2.0)
                dx=sqrt(r*r-w*w/4.0);
            v.push_back({x-dx,x+dx});
        }
        double coverd=0,mx=0;
        int cnt=1;
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();++i){
            if(mx>=l)break;
            if(v[i].first<=coverd){
                mx=max(mx,v[i].second);
            }
            else if(v[i].first>mx){
                break;
            }
            else{
                ++cnt;
                coverd=mx;
                mx=max(mx,v[i].second);
            }
        }
        if(mx<l) printf("-1\n");
        else printf("%d\n",cnt);
    }
    return 0;
}
