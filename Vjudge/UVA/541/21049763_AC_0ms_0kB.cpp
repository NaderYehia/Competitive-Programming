#include<iostream>
using namespace std;
int n,c,r,cc,rr;
int arr[101][101];
int main(){
	while(1){
		scanf("%d",&n);
		if(n==0)
			return 0;
		c=0,r=0;
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			scanf("%d",&arr[i][j]);
	for(int i=0;i<n;++i){
		int ones=0;
		for(int j=0;j<n;++j){
			if(arr[i][j]==1)
				++ones;
			}
			if(ones&1){
				++r;
				rr=i;	
			}
		}
	for(int i=0;i<n;++i){
		int ones=0;
		for(int j=0;j<n;++j){
			if(arr[j][i]==1)
				++ones;
			}
			if(ones&1){
				++c;
				cc=i;	
			}
		}		
	if(c==0&&r==0)
		printf("OK\n");
	else if(c==1&&r==1)
		printf("Change bit (%d,%d)\n",rr+1,cc+1);
	else 
		printf("Corrupt\n");
	}
}