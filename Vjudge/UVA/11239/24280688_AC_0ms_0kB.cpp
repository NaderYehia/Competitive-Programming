#include<bits/stdc++.h>

using namespace std;

string s,tmp;
map<string,set<string> >mp;
vector<string>v;
map<string,int> cnt;
set<pair<int,string> > sol;

void ans(){
    for(int i=0;i<v.size();++i){
        set<string> tt=mp[v[i]];
        for(set<string>::iterator it=tt.begin();it!=tt.end();++it)
            ++cnt[(*it)];
    }
    for(int i=0;i<v.size();++i){
        set<string> tt=mp[v[i]];
        for(set<string>::iterator it=tt.begin();it!=tt.end();++it)
            if(cnt[(*it)]>1)
                (mp[v[i]]).erase((*it));
    }
    for(int i=0;i<v.size();++i)
        sol.insert(make_pair(-mp[v[i]].size(),v[i]));
    for(set<pair<int,string> >::iterator it=sol.begin();it!=sol.end();++it){
        cout<<(*it).second<<" "<<-(*it).first<<endl;
    }
    mp.clear(),v.clear(),cnt.clear(),sol.clear();
}

int main(){
    while(getline(cin,s)){
        if(s[0]=='1'){
            ans();
            continue;
        }
        else if(s[0]=='0')
            return 0;
        else if(s[0]>='A'&&s[0]<='Z')
            v.push_back(s),mp[v.back()].clear();
        else if(s[0]>='a'&&s[0]<='z')
            mp[v.back()].insert(s);
    }
    return 0;
}
