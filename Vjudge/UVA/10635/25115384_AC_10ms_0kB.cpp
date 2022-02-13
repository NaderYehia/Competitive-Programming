#include<bits/stdc++.h>

using namespace std;

const int N=2e5+5,OO=0x3f3f3f3f;
int t,n,p,q,a;
int s1[63000],s2[63000];
vector<int> v;
vector<int> v1;
int ans[250*250+5];

int main() {
    int tc=1;
    scanf("%d",&t);
    while(t--){
        v.clear();
        scanf("%d%d%d",&n,&p,&q);
        ++p,++q;
        memset(s2,0,sizeof s2);
        for(int i=0;i<p;++i)
            scanf("%d",s1+i),s2[s1[i]]=i+1;
        for(int i=0;i<q;++i){
            scanf("%d",&a);
            if(s2[a]!=0)
                v.push_back(s2[a]);
        }
        ans[0]=-OO;
        memset(ans+1,OO,sizeof ans);
        for(int i=0;i<v.size();++i){
            int idx=lower_bound(ans,ans+250*250+5,v[i])-ans;
            if(v[i]<ans[idx]&&v[i]>ans[idx-1])
                ans[idx]=v[i];
        }
        int lis=lower_bound(ans,ans+250*250+5,250*250+5)-ans-1;
        printf("Case %d: %d\n",tc++,lis);
    }
    return 0;
}