#include<bits/stdc++.h>

using namespace std;

int t,sum,mx,n,m;
vector<string> v;
vector<string> ans;

void print(){
    for(int i=0;i<ans.size();++i)
        cout<<ans[i];
    cout<<endl;
}

void solve(string s,int i){
    if(i==s.length()){
        print();
        return;
    }
    if(s[i]=='#'){
        for(int j=0;j<v.size();++j){
            ans.push_back(v[j]);
            solve(s,i+1);
            ans.pop_back();
        }
    }
    else {
        for(int j=0;j<10;++j){
            ans.push_back(to_string(j));
            solve(s,i+1);
            ans.pop_back();
        }
    }
}


int main() {
    while(~scanf("%d",&n)){
        printf("--\n");
        v.clear();
        for(int i=0;i<n;++i){
            string a;cin>>a;
            v.push_back(a);
        }
        scanf("%d",&m);
        for(int i=0;i<m;++i){
            string a;cin>>a;
            solve(a,0);
        }
    }

	return 0;
}
