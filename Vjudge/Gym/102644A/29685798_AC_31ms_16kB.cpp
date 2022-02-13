#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e3+10,M=1e9,OO=0x3f3f3f3f;

typedef vector<vector<double> > vvi;

vvi matrixMul(vvi a,vvi b){
    vvi ret(a.size(),vector<double> (b[0].size(),0));
    for(int i=0;i<a.size();++i){
        for(int j=0;j<b[0].size();++j){
            for(int k=0;k<a[0].size();++k){
                ret[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    return ret;
}

vvi matrixPow(vvi x,ll p){
    vvi ret={{1,0},{0,1}};
    while(p){
        if(p&1) ret=matrixMul(ret,x);
        x=matrixMul(x,x);
        p>>=1;
    }
    return ret;
}



int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);


    int n;
    double p;
    cin>>n>>p;
    vvi cur={{1-p,p},{p,1-p}};

    cur=matrixPow(cur,n);

    printf("%.6f",cur[0][0]);

    return 0;
}
