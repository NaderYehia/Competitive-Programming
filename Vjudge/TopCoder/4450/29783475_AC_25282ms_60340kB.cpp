#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=2e4+10,M=2e4+7,OO=0x3f3f3f3f;
const double eps=1e-9;

double mem[N][205];

int vis[N][206],vid;

double go(int rem,int ops,vector<int> &sidesA){
    if(rem<0) return 0;
    if(ops==0) return rem==0;
    if(vis[rem][ops]==vid) return mem[rem][ops];
    vis[rem][ops]=vid;
    double ret=0;
    for(int i=0;i<6;++i){
        ret+=1.0/6*go(rem-sidesA[i],ops-1,sidesA);
    }
    return mem[rem][ops]=ret;
}

double probA[N],probB[N];

class DiceThrows{

public:
    double winProbability(int numDiceA, vector<int> sidesA, int numDiceB, vector<int> sidesB){
        sort(sidesA.begin(),sidesA.end());
        sort(sidesB.begin(),sidesB.end());

        ++vid;
        for(int i=0;i<=sidesA.back()*numDiceA;++i)
            probA[i]=go(i,numDiceA,sidesA);

        ++vid;
        for(int i=0;i<=sidesB.back()*numDiceB;++i)
            probB[i]=go(i,numDiceB,sidesB);

        double ret=0;
        for(int i=0;i<=sidesA.back()*numDiceA;++i){
            for(int j=0;j<i;++j){
                ret+=probA[i]*probB[j];
            }
        }
        return ret;

    }

};

