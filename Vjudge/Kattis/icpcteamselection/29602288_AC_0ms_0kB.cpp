#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e4+10,M=2e4+7,OO=0x3f3f3f3f;



int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    int t,tc=1;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        n*=3;
        vector<int> arr(n);
        for(int i=0;i<n;++i)
            scanf("%d",&arr[i]);
        sort(arr.begin(),arr.end());
        int sum=0;
        for(int i=0,j=n-2;i<n/3;++i,j-=2)
            sum+=arr[j];
        printf("%d\n",sum);
    }

    return 0;
}
