#include<bits/stdc++.h>

using namespace std;

const int N=2e5+5;
int t,n,k;
bool don[1005];

void solve(int i){
    don[i]=!don[i];
    for(int j=1;j<=k;++j){
        if(j+i<=n)
            don[j+i]=!don[j+i];
        if(i-j>0)
            don[i-j]=!don[i-j];
    }
}

bool ch(){
    for(int i=1;i<=n;++i)
        if(!don[i])
            return 0;
    return 1;
}

int main() {
	scanf("%d%d",&n,&k);
    int ne=(int)ceil((double)n/(k*2+1));
    printf("%d\n",ne);
    for(int i=1;i<=n;++i){
        for(int j=i;j<=n;j+=(2*k+1)){
            solve(j);
        }
        if(ch()){
            for(int j=i;j<=n;j+=(2*k+1))
                printf("%d ",j);
            break;
        }
        else
            memset(don,0,sizeof don);
    }
	return 0;
}
