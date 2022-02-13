#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=1e6+5,M=2<<30,OO=0x3f3f3f3f;
int t,n,m,k;

int main(){
    //freopen("myfile.txt","w",stdout);
    while(~scanf("%d",&n)){
        int mul=10,ans=1,sum=1;
        while(sum%n!=0){
            sum=(sum%n)+(mul%n)%n;
            mul=(mul*10)%n;
            ++ans;
        }
        printf("%d\n",ans);
    }
    return 0;
}
