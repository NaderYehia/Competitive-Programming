#include<bits/stdc++.h>

using namespace std;

int aCap,bCap,n,k;
map<pair<int,int>,bool>vis;
string ans;

bool solve(int a,int b,string s){
    vis[{a,b}]=1;
    if(b==n){
        ans=s;
        return 1;
    }
    bool ret=0;
    if(a!=aCap&&!vis[{aCap,b}]){
        ret|=solve(aCap,b,s+"fill A\n");
    }
    if(ret)
        return ret;
    if(b!=bCap&&!vis[{a,bCap}]){
        ret|=solve(a,bCap,s+"fill B\n");
    }
    if(ret)
        return ret;
    if(a!=0&&!vis[{0,b}]){
        ret|=solve(0,b,s+"empty A\n");
    }
    if(ret)
        return ret;
    if(b!=0&&!vis[{a,0}]){
        ret|=solve(a,0,s+"empty B\n");
    }
    if(ret)
        return ret;
    if(b!=0&&!vis[{a+(min(b,aCap-a)),b-(min(b,aCap-a))}]){
        ret|=solve(a+(min(b,aCap-a)),b-(min(b,aCap-a)),s+"pour B A\n");
    }
    if(ret)
        return ret;
    if(a!=0&&!vis[{a-(min(a,bCap-b)),b+(min(a,bCap-b))}]){
        ret|=solve(a-(min(a,bCap-b)),b+(min(a,bCap-b)),s+"pour A B\n");
    }
    return ret;
}

int main() {
    while(~scanf("%d%d%d",&aCap,&bCap,&n)){
        vis.clear();
        solve(0,0,"");
        cout<<ans<<"success\n";
    }
	return 0;
}
