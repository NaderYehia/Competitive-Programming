#include<bits/stdc++.h>

using namespace std;

const int N=1e5+5,OO=0x3f3f3f3f;
int n,m;

int get_powers(int n, int p) {
    long long res=0,power=p;
    while(power<=n){
        res+=n/power;
        power=power*1ll*p;
    }
    return res;
}

int main() {
    while(~scanf("%d%d",&n,&m)){
        vector<int> pf;
        set<int> spf;
        int mm=m;
        for(int i=2;i<=m/i;++i){
            while(m%i==0)
                pf.push_back(i),spf.insert(i),m/=i;
        }
        if(m>1)
            pf.push_back(m),spf.insert(m);
        bool failed=0;
        for(int val : spf){
            int cnt=upper_bound(pf.begin(),pf.end(),val)-lower_bound(pf.begin(),pf.end(),val);
            if(get_powers(n,val)<cnt){
                failed=1;
                break;
            }
        }
        if(!failed)
            printf("%d divides %d!\n",mm,n);
        else
            printf("%d does not divide %d!\n",mm,n);
    }
    return 0;
}
