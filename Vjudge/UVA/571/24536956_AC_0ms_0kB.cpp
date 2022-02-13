#include<bits/stdc++.h>

using namespace std;

int aCap,bCap,n,k;



int main() {
    while(~scanf("%d%d%d",&aCap,&bCap,&n)){
        map<pair<int,int>,bool>vis;
        queue<pair< pair<int,int> ,string > >q;
        q.push(make_pair(make_pair(0,0),""));
        while(q.size()){
            int a=q.front().first.first;
            int b=q.front().first.second;
            string tmp=q.front().second;
            q.pop();
            vis[{a,b}]=1;
            if(b==n){
                cout<<tmp<<"success\n";
                break;
            }
            if(a!=aCap&&!vis[{aCap,b}]){
                q.push(make_pair(make_pair(aCap,b),tmp+"fill A\n"));
            }
            if(b!=bCap&&!vis[{a,bCap}]){
                q.push(make_pair(make_pair(a,bCap),tmp+"fill B\n"));
            }
            if(a!=0&&!vis[{0,b}]){
                q.push(make_pair(make_pair(0,b),tmp+"empty A\n"));
            }
            if(b!=0&&!vis[{a,0}]){
                q.push(make_pair(make_pair(a,0),tmp+"empty B\n"));
            }
            if(b!=0&&!vis[{a+(min(b,aCap-a)),b-(min(b,aCap-a))}]){
                q.push(make_pair(make_pair(a+(min(b,aCap-a)),b-(min(b,aCap-a))),tmp+"pour B A\n"));
            }
            if(a!=0&&!vis[{a-(min(a,bCap-b)),b+(min(a,bCap-b))}]){
                q.push(make_pair(make_pair(a-(min(a,bCap-b)),b+(min(a,bCap-b))),tmp+"pour A B\n"));
            }
        }
    }
	return 0;
}
