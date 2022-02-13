#include <bits/stdc++.h>

using namespace std;

const int N=1e3+5,OO=0x3f3f3f3f;
int t,n,m,k,q;
string s;

int main(){
    while(~scanf("%d",&n),n){
        deque<int> dq;
        vector<int> v;
        for(int i=1;i<=n;++i)
            dq.push_back(i);
        while(dq.size()>1){
            v.push_back(dq.front());
            dq.pop_front();
            dq.push_back(dq.front());
            dq.pop_front();
        }
        printf("Discarded cards:");
        for(int i=0;i<v.size();++i){
            printf(" %d",v[i]);
            if(i+1!=v.size())
                printf(",");
        }
        printf("\n");
        printf("Remaining card: %d\n",dq.front());
    }
    return 0;
}
