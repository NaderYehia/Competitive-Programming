#include<bits/stdc++.h>

using namespace std;

int n,m;
vector<string> v;
vector<string> ans;
string s;

void print(){
    for(int i=0;i<ans.size();++i)
        printf("%s",ans[i].c_str());
    printf("\n");
}

void solve(int i,string s){
    if(i==s.length()){
        print();
        return;
    }
    if(s[i]=='0'){
        for(int j=0;j<10;++j){
            ans.push_back(to_string(j));
            solve(i+1,s);
            ans.pop_back();
        }
    } else {
        for(int j=0;j<v.size();++j){
            ans.push_back(v[j]);
            solve(i+1,s);
            ans.pop_back();
        }
    }
}

int main() {
    while(~scanf("%d",&n)){
        printf("--\n");
        for(int i=0;i<n;++i){
            cin>>s;
            v.push_back(s);
        }
        scanf("%d",&m);
        while(m--){
            cin>>s;
            solve(0,s);
        }
        v.clear();
    }
	return 0;
}
