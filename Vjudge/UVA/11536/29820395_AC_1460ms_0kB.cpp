#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e6+10,M=10000007,OO=0x3f3f3f3f;
const double eps=1e-9;

int arr[N];

set<int> st;
map<int,int> mp;

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    int t,tc=1;
    scanf("%d",&t);
    while(t--){
        st.clear(),mp.clear();
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        arr[1]=1,arr[2]=2,arr[3]=3;
        for(int i=4;i<=n;++i)
            arr[i]=(arr[i-1]+arr[i-2]+arr[i-3])%m+1;
        arr[n+1]=k+1;

        int i=1,j=2,seg=OO;
        st.insert(1),st.insert(2),mp[1]=1,mp[2]=1;
        while(j<=n){
            while(arr[i]>k) ++i;
            if(st.size()>=k) seg=min(seg,j-i+1);
            if(mp[arr[i]]>1){
                --mp[arr[i]];
                ++i;
                continue;
            }
            if(arr[j+1]>k){
                ++j;
                continue;
            }
            mp[arr[j+1]]++;
            st.insert(arr[j+1]);
            ++j;
        }
        if(seg==OO) printf("Case %d: sequence nai\n",tc++);
        else printf("Case %d: %d\n",tc++,seg);

    }

    return 0;
}
