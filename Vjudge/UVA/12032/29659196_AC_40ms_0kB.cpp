#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e6+10,M=1e3+7,OO=0x3f3f3f3f;

bool can(int x,vector<int> &arr){
    int cur=0;
    for(int i=0;i<arr.size();++i){
        if(arr[i]-cur>x) return 0;
        if(arr[i]-cur==x) --x;
        cur=arr[i];
    }
    return 1;
}


int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    int t,tc=1;
    scanf("%d",&t);
    while(t --> 0){
        int n;
        scanf("%d",&n);
        vector<int> arr(n);
        for(int i=0;i<n;++i)
            scanf("%d",&arr[i]);

        sort(arr.begin(),arr.end());

        int lo=1,hi=2e7;
        while(lo<hi){
            int md=lo+(hi-lo)/2;
            if(can(md,arr)) hi=md;
            else lo=md+1;
        }
        printf("Case %d: %d\n",tc++,lo);
    }
    return 0;
}
