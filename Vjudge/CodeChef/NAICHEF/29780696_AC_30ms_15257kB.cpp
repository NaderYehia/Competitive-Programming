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
        int n,a,b;
        scanf("%d%d%d",&n,&a,&b);
        vector<int> arr(n);
        int cnt0=0,cnt1=0;
        for(int i=0;i<n;++i){
            scanf("%d",&arr[i]);
            cnt0+=(arr[i]==a);
            cnt1+=(arr[i]==b);
        }

        printf("%.6lf\n",(1.0*cnt0/n)*(1.0*cnt1/n));

    }

    return 0;
}
