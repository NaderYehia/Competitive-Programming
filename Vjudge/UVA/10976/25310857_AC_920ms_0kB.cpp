#include<bits/stdc++.h>

using namespace std;

const int N=2e5+5,OO=0x3f3f3f3f;
int t,n,a,b;

int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}

int lcm(int a,int b){
    return a*(b/gcd(a,b));
}

int main() {
    while(~scanf("%d",&n)){
        int ans=0;
        for(int i=1;i<=100000;++i){
            int dom=lcm(i,n);
            int nom=dom/n-dom/i;
            if(nom<=0)
                continue;
            if(dom%nom==0&&dom/nom>=i)
                ++ans;
        }
        printf("%d\n",ans);
        for(int i=1;i<=100000;++i){
            int dom=lcm(i,n);
            int nom=dom/n-dom/i;
            if(nom<=0)
                continue;
            if(dom%nom==0&&dom/nom>=i)
                printf("1/%d = 1/%d + 1/%d\n",n,dom/nom,i);
        }
    }
    return 0;
}
