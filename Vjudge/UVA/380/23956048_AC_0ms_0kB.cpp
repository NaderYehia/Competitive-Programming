#include<bits/stdc++.h>

using namespace std;

const int N = 1e3+6,M=1e9,OO=0x3f3f3f3f;

int t,n,p,s,m,k,sum;
map<string,vector<pair<pair<string,string>,string> > >mp;
map<string,bool>vis;

int toInt(string s){
    int in=0;
    for(int i=0;s[i];++i)
        in=in*10+(s[i]-'0');
    return in;
}

string ans(int time,string callee){
    if(vis[callee])
        return "9999";
    vis[callee]=1;
    for(int i=0;i<mp[callee].size();++i){
        int start=toInt(mp[callee][i].first.first);
        int en=toInt(mp[callee][i].first.second)+start;
        if(time>=start&&time<=en)
            return ans(time,mp[callee][i].second);
    }
    return callee;
}

int main(){
    cin>>t;
    printf("CALL FORWARDING OUTPUT\n");
    while(t--){
        printf("SYSTEM %d\n",++k);
        string a,b,c,d;
        while(cin>>a,a!="0000"){
            cin>>b>>c>>d;
            mp[a].push_back(make_pair(make_pair(b,c),d));
        }
        while(cin>>a,a!="9000"){
            cin>>b;
            printf("AT %s CALL TO %s RINGS %s\n",a.c_str(),b.c_str(),ans(toInt(a),b).c_str());
            vis.clear();
        }
        mp.clear();
    }
    printf("END OF OUTPUT\n");
    return 0;
}
