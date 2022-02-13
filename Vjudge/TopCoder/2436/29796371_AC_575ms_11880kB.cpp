#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e5+10,M=10000007,OO=0x3f3f3f3f;
const double eps=1e-9;

double prob(int cur,int rem,int sum,int msk,vector<int> &chips){
    if(rem==0) return 0;
    double ret=1.0*chips[cur]/sum;
    for(int i=0;i<chips.size();++i){
        if(i==cur||((1<<i)&msk)) continue;
        ret+=(1.0*chips[i]/sum)*prob(cur,rem-1,sum-chips[i],msk|(1<<i),chips);
    }
    return ret;
}

class ChipRace{
public:
    vector<double> chances(vector<int> chips){
        int sum=0;;
        for(int i=0;i<chips.size();++i)
            sum+=chips[i];
        int cnt=sum/5+((sum%5)>2);
        vector<double> ret(chips.size());
        for(int i=0;i<chips.size();++i)
            ret[i]=prob(i,cnt,sum,0,chips);
        return ret;
    }
};

