#include<bits/stdc++.h>

using namespace std;

int t,c,n,k;
map<string,vector<pair< pair<int,int> ,string > > >mp;
map<string,bool> vis;

int dig(string s){
    int sum=0;
    for(int i=0;s[i];++i)
        sum=sum*10+(s[i]-'0');
    return sum;
}

string get(int x,string fin){
    if(vis[fin]){
        return "9999";
    }
    vis[fin]=1;
    for(int i=0;i<mp[fin].size();++i){
        if(x>=mp[fin][i].first.first&&x<=mp[fin][i].first.second){
            return get(x,mp[fin][i].second);
        }
    }
    return fin;
}

int main() {
    printf("CALL FORWARDING OUTPUT\n");
    scanf("%d",&t);
    while(t--){
        printf("SYSTEM %d\n",++k);
        string s;
        while(cin>>s,s!="0000"){
            string fr,to,dest;
            cin>>fr>>to>>dest;
            mp[s].push_back(make_pair(make_pair(dig(fr),dig(to)+dig(fr)),dest));
        }
        while(cin>>s,s!="9000"){
            string dest;
            cin>>dest;
            printf("AT %s CALL TO %s RINGS %s\n",s.c_str(),dest.c_str(),get(dig(s),dest).c_str());
            vis.clear();
        }
        mp.clear();
    }
    printf("END OF OUTPUT\n");
	return 0;
}
