#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e5+5,M=1e9+7,OO=0x3f3f3f3f;
const double eps=1e-6,pi=acos(-1);
int t,n,m,k;
string s1,s2;

bool can(int x){
    if(x*s1.size()>s2.size()) return false;
    string tmp;
    for(int i=0;s1[i];++i){
        for(int j=0;j<x;++j)
            tmp+=s1[i];
    }
    int j=0;
    for(int i=0;s2[i];++i){
        if(tmp[j]==s2[i])
            ++j;
        if(j==tmp.size()) break;
    }
    return j==tmp.size();
}

int bs(){
    int lo=0,hi=500010,mid;
    while(lo<hi){
        mid=lo+(hi-lo+1)/2;
        if(can(mid)) lo=mid;
        else hi=mid-1;
    }
    return lo;
}

int main(){
    //freopen("myfile.txt","w",stdout);
    scanf("%d\n",&t);
    while(t--){
        cin>>s1>>s2;
        cout<<bs()<<endl;
    }
    return 0;
}
