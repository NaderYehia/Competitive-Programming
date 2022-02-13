#include <bits/stdc++.h>

using namespace std;

const int N=1e3+5,OO=0x3f3f3f3f;
int t,n,m,k,q;
string s;
map<string,int> mp;

int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i){
        cin>>s>>k;
        mp[s]=k;
    }
    int sum=0;
    while(cin>>s){
        if(s=="."){
            cout<<sum<<endl;
            sum=0;
            continue;
        }
        else{
            if(mp.find(s)!=mp.end()){
                sum+=mp[s];
            }
        }
    }
    return 0;
}
