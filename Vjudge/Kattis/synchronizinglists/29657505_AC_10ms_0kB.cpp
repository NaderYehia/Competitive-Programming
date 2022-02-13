#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e3+10,M=1e3+7,OO=0x3f3f3f3f;




int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    bool first=1;
    int n;
    while(~scanf("%d",&n),n){
        if(!first) puts("");
        first=0;
        vector<pair<int,int> > vp(n);
        vector<int> v(n);
        for(int i=0;i<n;++i)
            scanf("%d",&vp[i].first),vp[i].second=i;
        for(int i=0;i<n;++i)
            scanf("%d",&v[i]);
        sort(vp.begin(),vp.end());
        sort(v.begin(),v.end());
        vector<int> ans(n);
        for(int i=0;i<n;++i)
            ans[vp[i].second]=v[i];

        for(int i=0;i<n;++i)
            printf("%d\n",ans[i]);

    }

    return 0;
}
