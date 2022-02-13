#include<bits/stdc++.h>
using namespace std;
int n,k;
bool a;
int main(){
	scanf("%d",&n);
		while(n--){
			a=0;
			scanf("%d",&k);
			for(int i=0;i<sqrt(k);++i){
				for(int j=0;j<sqrt(k);++j){
					int x=(int)sqrt(k-i*i-j*j);
					if(k==(i*i)+(j*j)+(x*x)){
						printf("%d %d %d\n",i,j,x);
						a=1;
						break;
					}
				}
					if(a)
						break;
					}
			if(!a)
				printf("-1\n");
		}
}