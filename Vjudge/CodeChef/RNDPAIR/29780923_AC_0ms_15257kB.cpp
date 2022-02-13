#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e3+10,M=2e4+7,OO=0x3f3f3f3f;
const double eps=1e-9;



int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        vector<int> arr(n);
        for(int i=0;i<n;++i)
            scanf("%d",&arr[i]);

        int ans=0,cnt=1,all=0;
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                ++all;
                if(arr[i]+arr[j]==ans) ++cnt;
                if(arr[i]+arr[j]>ans) ans=arr[i]+arr[j],cnt=1;
            }
        }

        printf("%.15f\n",1.0*cnt/all);

    }

    return 0;
}
