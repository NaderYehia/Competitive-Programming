#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e4+5,M=1e9+7,OO=0x3f3f3f3f;


int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    int n;
    while(~scanf("%d",&n)){
        int cur=1,cnt=1;
        while(cur!=0){
            cur=cur*10+1;
            cur=cur%n;
            ++cnt;
        }
        printf("%d\n",cnt);
    }


    return 0;
}
