#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll N=1e3+10,M=(1ll<<32),OO=0x3f3f3f3f;

typedef vector<vector<unsigned int> > vvi;

vvi matrixMul(vvi a,vvi b){
    vvi ret(a.size(),vector<unsigned int> (b[0].size(),0));
    for(int i=0;i<a.size();++i){
        for(int j=0;j<b[0].size();++j){
            for(int k=0;k<a[0].size();++k){
                ret[i][j]=(ret[i][j]+(a[i][k]*b[k][j])%M)%M;
            }
        }
    }
    return ret;
}

vvi matrixPow(vvi x,ll p,int n){
    vvi ret(n,vector<unsigned int> (n,0));
    for(int i=0;i<n;++i)
        ret[i][i]=1;
    while(p){
        if(p&1) ret=matrixMul(ret,x);
        x=matrixMul(x,x);
        p>>=1;
    }
    return ret;
}

bool valid(int r,int c){
    return r>-1&&c>-1&&r<8&&c<8;
}

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);


    vvi cur(65,vector<unsigned int>(65,0));
    for(int i=0;i<8;++i){
        for(int j=0;j<8;++j){
            for(int ii=-1;ii<2;ii+=2){
                for(int jj=-1;jj<2;jj+=2){
                    for(int k=0,di=1,dj=2;k<2;++k,swap(di,dj)){
                        int ni=(di*ii)+i,nj=(dj*jj)+j;
                        if(!valid(ni,nj)) continue;
                        cur[i*8+j][ni*8+nj]=cur[ni*8+nj][i*8+j]=1;
                    }
                }
            }
        }
    }
    for(int i=0;i<65;++i)
        cur[64][i]=1;

    int n;
    scanf("%d",&n);

    cur=matrixPow(cur,n+1,65);

    vvi ans(65,vector<unsigned int> (1,0));
    ans[0][0]=1;

    ans=matrixMul(cur,ans);

    printf("%u\n",ans[64][0]);

    return 0;
}
