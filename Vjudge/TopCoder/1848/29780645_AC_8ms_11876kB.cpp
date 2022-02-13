#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e3+10,M=2e4+7,OO=0x3f3f3f3f;
const double eps=1e-9;


class BirthdayOdds{
public:
    int minPeople(int minOdds, int daysInYear){
        double curOdds=1.0;
        int ret=1;
        double num=daysInYear-1;
        double p=minOdds/100.0;
        while(1.0-curOdds<p){
            curOdds*=num--/daysInYear;
            ++ret;
        }
        return ret;
    }

};

