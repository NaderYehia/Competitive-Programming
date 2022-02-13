#include <bits/stdc++.h>

using namespace std;

const int N=1e3+5,OO=0x3f3f3f3f;
int t,n,m,k,q;


int main(){
    //freopen("myfile.txt","w",stdout);
    while(~scanf("%d%d",&n,&m)&&(n+m)){
        set<int> someone;
        for(int i=0,tmp;i<n;++i){
            scanf("%d",&tmp);
            someone.insert(tmp);
        }
        int cnt=0;
        for(int i=0,tmp;i<m;++i){
            scanf("%d",&tmp);
            if(someone.find(tmp)!=someone.end())
                ++cnt;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
