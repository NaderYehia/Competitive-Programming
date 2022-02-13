#include<bits/stdc++.h>

using namespace std;

const int N=2e5+5;
int t,n,a,b,x,y;
vector<int>v;

int main() {
	scanf("%d%d",&a,&b);
	int gcd=__gcd(a,b);
	int sq=sqrt(gcd);
    for(int i=1;i<=sq;++i){
        if(gcd%i==0){
            v.push_back(i);
            if(gcd/i!=i)
                v.push_back(gcd/i);
        }
    }
    sort(v.begin(),v.end());
    scanf("%d",&n);
    while(n--){
        scanf("%d%d",&x,&y);
        bool found=0;
        for(int i=v.size()-1;i>-1;--i){
            if(v[i]>=x&&v[i]<=y){
                printf("%d\n",v[i]);
                found=1;
                break;
            }
        }
        if(!found)
            printf("-1\n");
    }
	return 0;
}
