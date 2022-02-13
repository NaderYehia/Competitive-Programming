#include <bits/stdc++.h>

using namespace std;

const int N=1e6+5,OO=0x3f3f3f3f;
int t,n,m,k,q;
int val[N];
char s[N];

int main(){
    //freopen("myfile.txt","w",stdout);
    int tc=1;
    while(~scanf("%s",s)){
        memset(val,0,sizeof val);
        for(int i=1;s[i];++i){
            if(s[i]!=s[i-1])
                val[i]=val[i-1]+1;
            else
                val[i]=val[i-1];
        }
        printf("Case %d:\n",tc++);
        scanf("%d",&q);
        while(q--){
            int st,en;
            scanf("%d%d",&st,&en);
            if(val[st]==val[en])
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}
