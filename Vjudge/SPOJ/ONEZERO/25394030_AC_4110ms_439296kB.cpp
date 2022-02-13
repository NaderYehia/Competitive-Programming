#include<bits/stdc++.h>

using namespace std;

const int N=1e3+5,OO=0x3f3f3f3f;
int t,n,m,k;

string bfs(){
    queue<pair<int,string> >q;
    q.push({1,"1"});
    while(q.size()){
        int tmp=q.front().first;
        string s=q.front().second;
        q.pop();
        if(!tmp)
            return s;
        q.push({(tmp*10)%n,s+'0'});
        q.push({(tmp*10+1)%n,s+'1'});
    }
}

int main() {
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        string ans=bfs();
        cout<<ans<<endl;
    }
    return 0;
}
