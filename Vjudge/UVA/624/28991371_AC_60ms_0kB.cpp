#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=2e5+5,M=1e9+7,OO=0x3f3f3f3f;

vector<int> v;
vector<int> ans;
int mx=0;

int arr[30];
int n,k;

void solve(int i,ll sum){
    if(i==n){
        if(sum<=k&&sum>mx){
            mx=sum;
            ans=v;
        }
        return;
    }

    solve(i+1,sum);

    v.push_back(arr[i]);
    solve(i+1,sum+arr[i]);
    v.pop_back();

}

int main(){

    while(~scanf("%d%d",&k,&n)){
        for(int i=0;i<n;++i){
            scanf("%d",&arr[i]);
        }
        mx=0;
        solve(0,0);
        for(int i=0;i<ans.size();++i){
            printf("%d ",ans[i]);
        }
        printf("sum:%d\n",mx);
    }

    return 0;
}
