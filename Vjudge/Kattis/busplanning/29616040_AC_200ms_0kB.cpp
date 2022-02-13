#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=2e2+10,M=2e4+7,OO=0x3f3f3f3f;

int n,k,c;
bool mat[20][20];
string arr[20];

void go(int msk,vector<int> &dp){
    if(dp[msk]==1){
        for(int i=0;i<n;++i)
            if((1<<i)&msk)
                printf("%s ",arr[i].c_str());
        puts("");
        return;
    }
    for(int j=(msk-1)&msk;j;j=(j-1)&msk){
        if(dp[msk]==dp[j]+dp[j^msk]){
            go(j,dp);
            go(j^msk,dp);
            return;
        }
    }
}

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    scanf("%d%d%d",&n,&k,&c);
    map<string,int> mp;
    for(int i=0;i<n;++i){
        char s[20];
        scanf("%s",s);
        string ss=s;
        arr[i]=ss;
        mp[ss]=i;
    }

    for(int i=0;i<k;++i){
        char s[20],t[20];
        scanf("%s%s",s,t);
        string ss1=s;
        string ss2=t;
        mat[mp[ss1]][mp[ss2]]=mat[mp[ss2]][mp[ss1]]=1;
    }

    vector<int> dp(1<<n,OO);

    dp[0]=0;
    for(int i=1;i<(1<<n);++i){
        bool failed=0;
        for(int j=0;j<n;++j){
            for(int k=j+1;k<n;++k){
                if(((1<<j)&i)&&((1<<k)&i))
                    if(mat[j][k]) failed=1;
            }
        }
        if(!failed&&__builtin_popcount(i)<=c){
            dp[i]=1;
            continue;
        }
        for(int j=i;j;j=(j-1)&i)
            dp[i]=min(dp[i],dp[j]+dp[j^i]);
    }
    printf("%d\n",dp[(1<<n)-1]);
    go((1<<n)-1,dp);


    return 0;
}
