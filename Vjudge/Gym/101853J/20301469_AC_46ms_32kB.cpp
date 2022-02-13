#include<iostream>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int arr[(int)1e4+5]={};
		for(int i=0;i<n;++i){
			int x;
			scanf("%d",&x);
			arr[x]++;
		}
		int max=0;
		for(int i=0;i<10004;++i)
			if(arr[i]+arr[i+1]>max)
				max=arr[i]+arr[i+1];
		printf("%d\n",max);
	}
}