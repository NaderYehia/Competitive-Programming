#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e5+10,M=10000007,OO=0x3f3f3f3f;
const double eps=1e-9;



int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);


    int a1,b1,a2,b2,a3,b3,a4,b4;
    scanf("%d%d%d%d%d%d%d%d",&a1,&b1,&a2,&b2,&a3,&b3,&a4,&b4);

    int emma=0,gunnar=0;

    for(int i=a1;i<=b1;++i){
        for(int j=a2;j<=b2;++j){
            for(int k=a3;k<=b3;++k){
                for(int r=a4;r<=b4;++r){
                    if(i+j>k+r) ++gunnar;
                    else if(i+j<k+r) ++emma;
                }
            }
        }
    }

    if(gunnar>emma) printf("Gunnar\n");
    else if(gunnar<emma) printf("Emma\n");
    else printf("Tie\n");

    return 0;
}
