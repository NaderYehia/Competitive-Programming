#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e5+10,M=2e4+7,OO=0x3f3f3f3f;

int n;
int arr[2][15];
int mem[15][15];

int solve(int ss,int se){
    if(ss==se) return 0;
    int &ret=mem[ss][se];
    if(~ret) return ret;
    ret=OO;
    for(int i=ss;i<se;++i){
        ret=min(ret,solve(ss,i)+solve(i+1,se)+arr[0][ss]*arr[1][se]*arr[1][i]);
    }
    return ret;
}

void dfs(int ss,int se){
    if(ss==se){
        printf("A%d",ss+1);
        return;
    }
    int ret=solve(ss,se);
    for(int i=ss;i<se;++i){
        if(ret==solve(ss,i)+solve(i+1,se)+arr[0][ss]*arr[1][se]*arr[1][i]){
            printf("(");
            dfs(ss,i);
            printf(" x ");
            dfs(i+1,se);
            printf(")");
            return;
        }
    }
}

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    int tc=1;
    while(~scanf("%d",&n),n){
        for(int i=0;i<n;++i)
            scanf("%d%d",arr[0]+i,arr[1]+i);
        memset(mem,-1,sizeof mem);
        printf("Case %d: ",tc++);
        dfs(0,n-1);
        puts("");
    }

    return 0;
}
