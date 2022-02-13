#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=5e2+10,M=2e9+7,OO=0x3f3f3f3f;



int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    int n,s;
    scanf("%d%d",&n,&s);
    char arr[n];
    int price[n],vol[n];
    for(int i=0;i<n;++i)
        scanf(" %c%d%d",arr+i,price+i,vol+i);

    bool vis[n]={};

    for(int i=0;i<n;++i){
        if(vis[i]) continue;
        for(int j=i+1;j<n;++j){
            if(vis[j]) continue;
            if(arr[i]==arr[j]&&price[i]==price[j]){
                vis[j]=1;
                vol[i]+=vol[j];
            }
        }
    }

    priority_queue<pair<int,int> > bs;
    set<pair<int,int> > ss;

    for(int i=0;i<n;++i){
        if(vis[i]) continue;
        if(arr[i]=='S'){
            ss.insert({price[i],vol[i]});
        }
        else{
            bs.push({price[i],vol[i]});
        }
    }

    vector<pair<int,int> > v;
    for(int i=0;i<s&&ss.size();++i){
        v.push_back({(*ss.begin()).first,(*ss.begin()).second});
        ss.erase(ss.begin());
    }
    while(v.size()){
        printf("S %d %d\n",v.back().first,v.back().second);
        v.pop_back();
    }
    for(int i=0;i<s&&bs.size();++i){
        printf("B %d %d\n",bs.top().first,bs.top().second);
        bs.pop();
    }


    return 0;
}
