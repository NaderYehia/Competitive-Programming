#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=1e5+5,M=1<<30,SEGM=4*N,OO=0x3f3f3f3f;
int n;
map<string,int> mp;
string unmp[2500];
vector<int> adj[2500];
int to[2500];
bool vis[2500];

int dfs(int u){
    vis[u]=1;
    if(to[u]==-1) return u;
    return dfs(to[u]);
}

int main(){
    //freopen("myfile.txt","w",stdout);
    memset(to,-1,sizeof to);
    int mapping=0;
    scanf("%d",&n);
    while(n--){
        string s1,s2;
        cin>>s1>>s2;
        if(mp.find(s2)!=mp.end()) continue;
        if(mp.find(s1)==mp.end()){
            mp[s1]=mapping;
            unmp[mapping++]=s1;
        }
        mp[s2]=mapping;
        unmp[mapping++]=s2;
        to[mp[s1]]=mp[s2];
    }
    vector<int> ans;
    for(int i=0;i<mapping;++i){
        if(!vis[i]){
            ans.push_back(i);
            ans.push_back(dfs(i));
        }
    }
    printf("%d\n",((int)ans.size())/2);
    for(int i=0;i<ans.size();i+=2){
        cout<<unmp[ans[i]]<<" "<<unmp[ans[i+1]]<<"\n";
    }
    return 0;
}
