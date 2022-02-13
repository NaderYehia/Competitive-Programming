#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=2e3+10,M=1e9+7,OO=0x3f3f3f3f;

int nxt[N];
bool vis[N];

int go(int i){
    vis[i]=1;
    if(nxt[i]==-1) return i;
    return go(nxt[i]);
}

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    int n;
    scanf("%d",&n);
    map<string,int> mp;
    vector<string> unmp;
    memset(nxt,-1,sizeof nxt);

    int m=0;
    for(int i=0;i<n;++i){
        string s1,s2;
        cin>>s1>>s2;
        if(mp.find(s1)==mp.end()) mp[s1]=m++,unmp.push_back(s1);
        mp[s2]=m++;
        unmp.push_back(s2);
        nxt[mp[s1]]=mp[s2];
    }

    vector<pair<string,string> > v;
    for(int i=0;i<m;++i){
        if(!vis[i]){
            v.push_back({unmp[i],unmp[go(i)]});
        }
    }

    printf("%d\n",v.size());
    for(int i=0;i<v.size();++i)
        printf("%s %s\n",v[i].first.c_str(),v[i].second.c_str());

    return 0;
}
