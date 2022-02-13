#include<bits/stdc++.h>

using namespace std;

int n;

int main(){
    while(~scanf("%d",&n)){
        queue<int> q;
        stack<int> s;
        priority_queue<int> pq;
        bool qu=1,st=1,pqq=1;
        for(int i=0;i<n;++i){
            int a,b;
            scanf("%d%d",&a,&b);
            if(a==1){
                q.push(b);
                s.push(b);
                pq.push(b);
            }
            else {
                if(q.empty()||q.front()!=b){
                    qu=0;
                }
                else{
                    q.pop();
                }
                if(s.empty()||s.top()!=b){
                    st=0;
                }
                else {
                    s.pop();
                }
                if(pq.empty()||pq.top()!=b){
                    pqq=0;
                }
                else {
                    pq.pop();
                }
            }
        }
        if(st&&!qu&&!pqq)
            printf("stack\n");
        else if(qu&&!st&&!pqq)
            printf("queue\n");
        else if(pqq&&!st&&!qu)
            printf("priority queue\n");
        else if(!st&&!qu&&!pqq)
            printf("impossible\n");
        else
            printf("not sure\n");
    }
    return 0;
}
