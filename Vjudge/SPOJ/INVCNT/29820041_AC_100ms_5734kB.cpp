#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=2e5+10,M=10000007,OO=0x3f3f3f3f;
const double eps=1e-9;

int arr[N];

ll mrge(int ss1,int se1,int ss2,int se2){
    vector<int> temp;
    int l=ss1,r=se2,sz=se1-ss1+1;
    ll ret=0;
    while(ss1<=se1&&ss2<=se2){
        if(arr[ss1]<=arr[ss2]) temp.push_back(arr[ss1++]);
        else temp.push_back(arr[ss2++]),ret+=sz-(ss1-l);
    }
    while(ss1<=se1) temp.push_back(arr[ss1++]);
    while(ss2<=se2) temp.push_back(arr[ss2++]);
    for(int i=l,j=0;i<=r;++i,++j)
        arr[i]=temp[j];
    return ret;
}

ll srt(int ss,int se){
    if(ss==se) return 0;
    int md=ss+(se-ss)/2;
    return srt(ss,md)+srt(md+1,se)+mrge(ss,md,md+1,se);
}

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;++i)
            scanf("%d",arr+i);
        printf("%lld\n",srt(0,n-1));
    }

    return 0;
}
