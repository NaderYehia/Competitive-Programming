#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e3+10,M=2e4+7,OO=0x3f3f3f3f;
const double eps=1e-9;

double mem[N][15];
bool vis[N][16];

class NestedRandomness{

public:
    double probability(int N, int nestings, int target){
        if(N<=target) return 0;
        if(nestings==1) return 1.0/N;
        if(vis[N][nestings]) return mem[N][nestings];
        vis[N][nestings]=1;
        double ret=0;
        for(int i=0;i<N;++i){
            ret+=(1.0/N)*probability(i,nestings-1,target);
        }
        return mem[N][nestings]=ret;
    }

};


