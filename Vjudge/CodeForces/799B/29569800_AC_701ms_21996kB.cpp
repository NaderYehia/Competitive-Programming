#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=5e2+10,M=2e9+7,OO=0x3f3f3f3f;



int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    int n;
    scanf("%d",&n);
    vector<int> p(n),a(n),b(n);
    vector<int> is(n);
    for(int i=0;i<n;++i){
        scanf("%d",&p[i]);
        is[i]=i;
    }


    for(int i=0;i<n;++i)
        scanf("%d",&a[i]);
    for(int i=0;i<n;++i)
        scanf("%d",&b[i]);

    vector<multiset<pair<int,int> > > oc(5);

    for(int i=0;i<n;++i){
        oc[a[i]].insert({p[i],b[i]});
        oc[b[i]].insert({p[i],a[i]});
    }


    int m;
    scanf("%d",&m);
    while(m--){
        int c;
        scanf("%d",&c);
        if(oc[c].size()){
            pair<int,int> cur=*oc[c].begin();
            oc[c].erase(oc[c].begin());
            printf("%d ",cur.first);
            oc[cur.second].erase(oc[cur.second].find({cur.first,c}));
        }
        else{
            printf("-1 ");
        }
    }


    return 0;
}
