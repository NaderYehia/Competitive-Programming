#include<bits/stdc++.h>

using namespace std;

const int N = 1e3+6,M=1e9,OO=0x3f3f3f3f;

int t,n,p,s,m,k,sum;
string st,stt;
vector<pair<int,string> >topics;
map<string,vector<string> >mp;
vector<string>v;

void print(){
    for(int i=0;i<s;++i){
        cout<<v[i];
        if(s-1==i)
            printf("\n");
        else
            printf(" ");
    }
}

void solve(int i){
    if(v.size()==s)
        print();
    if(i==n||v.size()>=s)
        return;
    for(int in=0;in<v.size();++in)
        for(int j=0;j<mp[v[in]].size();++j)
            if(topics[i].second==mp[v[in]][j]){
                solve(i+1);
                return;
            }
    v.push_back(topics[i].second);
    solve(i+1);
    v.pop_back();
    solve(i+1);
}

string toupper(string s){
    for(int i=0;s[i];++i)
        if(islower(s[i]))
            s[i]=toupper(s[i]);
    return s;
}

int main(){
    cin>>t;
    while(t--){
        printf("Set %d:\n",++k);
        mp.clear();
        topics.clear();
        cin>>n>>p>>s;
        for(int i=0;i<n;++i){
            cin>>st;
            st=toupper(st);
            topics.push_back({-st.length(),st});
        }
        sort(topics.begin(),topics.end());
        while(p--){
            cin>>st>>stt;
            st=toupper(st);
            stt=toupper(stt);
            mp[st].push_back(stt);
            mp[stt].push_back(st);
        }
        solve(0);
        puts("");
    }
    return 0;
}
