#include<bits/stdc++.h>

using namespace std;

int n,m,mx;
int arr[50];
vector<int> v,ans;

int main() {
    while(~scanf("%d%d",&m,&n)){
        mx=0;
        for(int i=0;i<n;++i)
            scanf("%d",arr+i);
        for(int i=0;i<(1<<n);++i){
            int msk=i,sum=0;
            for(int j=0;j<n;++j){
                if(msk&1)
                    sum+=arr[j],v.push_back(arr[j]);
                msk>>=1;
            }
            if(sum>mx&&sum<=m){
                mx=sum;
                ans=v;
            }
            v.clear();
        }
        for(int i=0;i<ans.size();++i)
            printf("%d ",ans[i]);
        printf("sum:%d\n",mx);
    }
	return 0;
}
