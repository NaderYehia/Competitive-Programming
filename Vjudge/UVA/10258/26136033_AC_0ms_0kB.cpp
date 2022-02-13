#include <bits/stdc++.h>

using namespace std;

const int N=1e3+5,OO=0x3f3f3f3f;
int t,n,m,k,q;
int arr[105][16];
bool solved[106][16];

int main(){
    scanf("%d\n\n",&t);
    while(t--){
        memset(arr,0,sizeof arr);
        memset(solved,0,sizeof solved);
        map<int ,pair<int,int> > mp;
        vector<pair<pair<int,int>,int> > v;
        string s;
        while(getline(cin,s)&&s!=""){
            stringstream ss(s);
            int con,pn,mnt;char ch;
            ss>>con;
            ss>>pn;
            ss>>mnt;
            ss>>ch;
            mp[con].first=mp[con].first;
            mp[con].second=mp[con].second;
            if(ch!='C'&&ch!='I'){
                continue;
            }
            if(ch=='C'){
                if(!solved[con][pn]){
                    ++mp[con].first;
                    mp[con].second+=mnt+arr[con][pn]*20;
                    solved[con][pn]=1;
                }
            }
            else{
                ++arr[con][pn];
            }
        }
        map<int ,pair<int,int> >::iterator it=mp.begin();
        while(it!=mp.end()){
            v.push_back(make_pair(make_pair(-(*it).second.first,(*it).second.second),(*it).first));
            ++it;
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();++i){
            cout<<v[i].second<<" "<<-v[i].first.first<<" "<<v[i].first.second<<endl;
        }
        if(t)
            printf("\n");
    }
    return 0;
}
