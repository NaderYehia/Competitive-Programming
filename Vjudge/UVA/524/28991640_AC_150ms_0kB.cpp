#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=2e5+5,M=1e9+7,OO=0x3f3f3f3f;

int n;
int arr[20];

bool prime[35];

vector<int> v;

void solve(int bk,int msk){
    if(msk==(1<<n)-1){
        if(prime[bk+1]){
            for(int i=0;i<v.size();++i){
                printf("%d%c",v[i]," \n"[i+1==v.size()]);
            }
        }
        else{
            //not answer
        }
    }
    for(int i=0;i<n;++i){
        if(msk&(1<<i)) continue;
        if(prime[i+1+bk]){
            v.push_back(i+1);
            solve(i+1,msk|(1<<i));
            v.pop_back();
        }
        else{
            //prune
        }
    }
}

int main(){

    //freopen("myfile.txt","w",stdout);
    prime[2]=prime[3]=prime[5]=prime[7]=prime[11]=prime[13]=prime[17]=prime[19]=prime[23]=prime[29]=prime[31]=1;
    int tc=1;
    while(~scanf("%d",&n)){
        if(tc>1) printf("\n");
        printf("Case %d:\n",tc++);
        v.push_back(1);
        solve(1,1);
        v.pop_back();
    }

    return 0;
}
