#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=5e2+10,M=2e9+7,OO=0x3f3f3f3f;



int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    set<pair<ll,int> > ocs;

    int n;
    scanf("%d",&n);
    vector<int> arr(n);
    for(int i=0;i<n;++i)
        scanf("%d",&arr[i]),ocs.insert({arr[i],i});

    vector<pair<ll,ll> > rem;

    while(ocs.size()>1){
        pair<ll,ll> f=*ocs.begin();
        ocs.erase(ocs.begin());
        pair<ll,ll> s=*ocs.begin();
        ocs.erase(ocs.begin());
        if(f.first==s.first){
            ocs.insert({f.first+s.first,s.second});
        }
        else{
            rem.push_back(f);
            ocs.insert(s);
        }
    }

    while(ocs.size()){
        rem.push_back(*ocs.begin());
        ocs.erase(ocs.begin());
    }

    for(int i=0;i<rem.size();++i)
        swap(rem[i].first,rem[i].second);

    printf("%d\n",rem.size());
    sort(rem.begin(),rem.end());
    for(int i=0;i<rem.size();++i)
        printf("%lld ",rem[i].second);


    return 0;
}
