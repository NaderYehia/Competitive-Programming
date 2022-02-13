#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e5+10,M=2e4+7,OO=0x3f3f3f3f;
const double eps=1e-9;



int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    int n;
    scanf("%d",&n);
    vector<double> arr(n);
    for(int i=0;i<n;++i){
        char s[15];
        scanf("%s%lf",s,&arr[i]);
    }

    sort(arr.rbegin(),arr.rend());

    double ans=0;
    for(int i=1;i<=n;++i){
        ans+=arr[i-1]*i;
    }
    printf("%.6f",ans);

    return 0;
}
