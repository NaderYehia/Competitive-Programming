#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e3+10,M=2e4+7,OO=0x3f3f3f3f;
const double eps=1e-9;


class PipeCuts{
public:
    double probability(vector<int> weldLocations, int L){
        sort(weldLocations.begin(),weldLocations.end());
        int cnt=0;
        for(int i=0;i<weldLocations.size();++i){
            for(int j=i+1;j<weldLocations.size();++j){
                bool cur=0;
                cur|=(weldLocations[i]>L);
                cur|=(weldLocations[j]-weldLocations[i]>L);
                cur|=(100-weldLocations[j]>L);
                cnt+=cur;
            }
        }
        int all=weldLocations.size()*(weldLocations.size()-1)/2;
        return 1.0*cnt/all;
    }

};

