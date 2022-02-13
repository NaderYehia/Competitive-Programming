#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=2e2+10,M=1e9+7,OO=0x3f3f3f3f;


int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    int n;
    while(~scanf("%d",&n)){
        stack<int> s;
        queue<int> q;
        priority_queue<int> pq;
        int st=1,qu=1,pqu=1;
        for(int i=0;i<n;++i){
            int op,x;
            scanf("%d%d",&op,&x);
            if(op==1){
                s.push(x);
                q.push(x);
                pq.push(x);
            }
            else{
                if(s.empty()||s.top()!=x) st=0;
                if(q.empty()||q.front()!=x) qu=0;
                if(pq.empty()||pq.top()!=x) pqu=0;
                if(!s.empty()) s.pop();
                if(!q.empty()) q.pop();
                if(!pq.empty()) pq.pop();
            }
        }
        if(st+qu+pqu>1) printf("not sure\n");
        else if(st+qu+pqu==0) printf("impossible\n");
        else if(st) printf("stack\n");
        else if(qu) printf("queue\n");
        else printf("priority queue\n");
    }

    return 0;
}
