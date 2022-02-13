#include <bits/stdc++.h>

using namespace std;

const int N=1e6+5,OO=0x3f3f3f3f;
int t,n,m,k,q;
int arr[N];
string s1,s2;


int main(){
    //freopen("myfile.txt","w",stdout);
    while(getline(cin,s1)&&s1!="#"){
        getline(cin,s2);
        stringstream ss(s1+" "+s2);
        vector<vector<string> > v;
        for(int i=0;i<52;++i){
            ss>>s2;
            vector<string> tmp;tmp.push_back(s2);
            v.push_back(tmp);
        }
        for(int i=1;i<v.size();++i){
            if(i>=3&&(v[i].back()[0]==v[i-3].back()[0]||v[i].back()[1]==v[i-3].back()[1])){
                v[i-3].push_back(v[i].back());
                v[i].pop_back();
                if(v[i].size()==0){
                    v.erase(v.begin()+i);
                }
                i-=4;
            }
            else if((i>=1)&&(v[i].back()[0]==v[i-1].back()[0]||v[i].back()[1]==v[i-1].back()[1])){
                v[i-1].push_back(v[i].back());
                v[i].pop_back();
                if(v[i].size()==0){
                    v.erase(v.begin()+i);
                }
                i-=2;
            }
        }
        printf("%d pile%s remaining: ",v.size(),(v.size()==1)?"":"s");
        for(int i=0;i<v.size();++i)
            printf("%d%c",v[i].size()," \n"[i+1==v.size()]);
    }
    return 0;
}
