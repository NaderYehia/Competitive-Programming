#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e3+10,M=1e3+7,OO=0x3f3f3f3f;




int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    int n,m,a,c,x0;
    scanf("%d%d%d%d%d",&n,&m,&a,&c,&x0);
    vector<int> vals;
    vals.push_back((a*1ll*x0+c)%m);
    for(int i=1;i<n;++i)
        vals.push_back((a*1ll*vals[i-1]+c)%m);

    int cnt=0;
    for(int i=0;i<n;++i){
        int x=vals[i];
        int lo=0,hi=n-1;
        while(lo<=hi){
            int md=lo+(hi-lo)/2;
            if(vals[md]==x){
                ++cnt;
                break;
            }
            else if(vals[md]<x){
                lo=md+1;
            }
            else{
                hi=md-1;
            }
        }
    }

    printf("%d\n",cnt);

    return 0;
}
