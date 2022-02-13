#include <bits/stdc++.h>

using namespace std;

const int N=1e3+5,OO=0x3f3f3f3f;
int t,n,m,k,q;
map<string,int> mp;
string s;

int main(){
    //freopen("myfile.txt","w",stdout);
    int cnt=1;
    for(int i=0;i<26;++i){
        string tmp="";tmp+=(char)('a'+i);
        mp[tmp]=cnt++;
    }
    for(int i=0;i<26-1;++i){
        for(int j=i+1;j<26;++j){
            string tmp="";tmp+=(char)('a'+i);tmp+=(char)('a'+j);
            mp[tmp]=cnt++;
        }
    }
    for(int i=0;i<26-2;++i){
        for(int j=i+1;j<26-1;++j){
            for(int k=j+1;k<26;++k){
                string tmp="";tmp+=(char)('a'+i);tmp+=(char)('a'+j);tmp+=(char)('a'+k);
                mp[tmp]=cnt++;
            }
        }
    }
    for(int i=0;i<26-3;++i){
        for(int j=i+1;j<26-2;++j){
            for(int k=j+1;k<26-1;++k){
                for(int q=k+1;q<26;++q){
                    string tmp="";tmp+=(char)('a'+i);tmp+=(char)('a'+j);tmp+=(char)('a'+k);tmp+=(char)('a'+q);
                    mp[tmp]=cnt++;
                }
            }
        }
    }
    for(int i=0;i<26-4;++i){
        for(int j=i+1;j<26-3;++j){
            for(int k=j+1;k<26-2;++k){
                for(int q=k+1;q<26-1;++q){
                    for(int l=q+1;l<26;++l){
                        string tmp="";tmp+=(char)('a'+i);tmp+=(char)('a'+j);tmp+=(char)('a'+k);tmp+=(char)('a'+q);tmp+=(char)('a'+l);
                        mp[tmp]=cnt++;
                    }
                }
            }
        }
    }
    while(cin>>s){
        if(mp.find(s)!=mp.end())
            cout<<mp[s]<<endl;
        else
            cout<<0<<endl;
    }
    return 0;
}
