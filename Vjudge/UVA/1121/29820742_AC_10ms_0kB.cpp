#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e6+10,M=10000007,OO=0x3f3f3f3f;
const double eps=1e-9;



int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    int n,s;
    while(~scanf("%d%d",&n,&s)){
        vector<int> arr(n+1);
        for(int i=0;i<n;++i)
            scanf("%d",&arr[i]);

        int i=0,j=1,seg=OO;
        int cur=arr[0];
        while(j<=n){
            while(i<j&&cur-arr[i]>=s) cur-=arr[i++];
            if(cur>=s) seg=min(seg,j-i);
            cur+=arr[j];
            j++;
        }
        seg=seg==OO?0:seg;
        printf("%d\n",seg);
    }

    return 0;
}
