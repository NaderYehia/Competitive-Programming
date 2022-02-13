#include<bits/stdc++.h>

using namespace std;

int n;

int main(){
    while(~scanf("%d",&n),n){
        queue<int>q;
        for(int i=1;i<=n;++i)
            q.push(i);
        printf("Discarded cards:");
        bool pr=1;
        while(q.size()>1){
            if(pr)
                printf(" %d",q.front()),q.pop(),printf(q.size()==1?"":",");
            else
                q.push(q.front()),q.pop();
            pr=!pr;
        }
        printf("\nRemaining card: %d\n",q.front()),q.pop();
    }
    return 0;
}
