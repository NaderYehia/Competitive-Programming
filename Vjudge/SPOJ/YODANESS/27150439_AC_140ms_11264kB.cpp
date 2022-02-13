#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=3e4+5,M=1e9+7,SEGM=4*N,OO=0x3f3f3f3f;
int t,w,n,l;
string arr[N];
map<string,int>mp;
int fr[N];

struct BIT{
    vector<int>v;
    BIT(int n){
        v.resize(n);
    }

    int get(int i){
        int ret=0;
        for(++i;i;i-=i&-i)
            ret+=v[i-1];
        return ret;
    }

    void update(int i,int val){
        for(++i;i<=v.size();i+=i&-i)
            v[i-1]+=val;
    }

    int count(int i){
        return get(n-1)-get(i);
    }

};

int main(){
    //freopen("myfile.txt","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;++i){
            cin>>arr[i];
            mp[arr[i]]=i;
        }
        for(int i=0;i<n;++i){
            cin>>arr[i];
            fr[mp[arr[i]]]=i;
        }
        BIT bit(n);
        int ans=0;
        for(int i=0;i<n;++i){
            ans+=bit.count(fr[i]);
            bit.update(fr[i],1);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
