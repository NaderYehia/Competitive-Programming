#include<bits/stdc++.h>
#include <string>

using namespace std;

const int N = 1e3+6,M=1e9+7,OO=0x3f3f3f3f;

int t,n,m,k,sum;
string s;
vector<string>dic,rul,tmp;

void print(){
    for(int i=0;i<tmp.size();++i)
        printf("%s",tmp[i].c_str());
    puts("");
}

void solve(int i){
    if(i==s.size()){
        print();
        return;
    }
    if(s[i]=='0'){
        for(int j=0;j<10;++j){
            tmp.push_back(to_string(j));
            solve(i+1);
            tmp.pop_back();
        }
    }
    else{
        for(int j=0;j<dic.size();++j){
            tmp.push_back(dic[j]);
            solve(i+1);
            tmp.pop_back();
        }
    }
}

int main(){
    while(~scanf("%d",&n)){
        printf("--\n");
        dic.clear();
        for(int i=0;i<n;++i){
            cin>>s;
            dic.push_back(s);
        }
        scanf("%d",&m);
        for(int i=0;i<m;++i){
            cin>>s;
            solve(0);
        }
    }
    return 0;
}
