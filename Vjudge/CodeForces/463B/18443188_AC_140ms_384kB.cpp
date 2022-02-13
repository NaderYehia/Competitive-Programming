#include<iostream>
using namespace std;
int main(){
	int energy=0,dollars=0,n;
	cin>>n;
	int arr[++n]={0};
	for(int i=1;i<n;i++)
	cin>>arr[i];
	for(int i=0;i<n-1;i++){
		if(arr[i]>=arr[i+1])
		energy+=arr[i]-arr[i+1];
		else
		{
			if(energy>=arr[i+1]-arr[i])
				energy-=arr[i+1]-arr[i];
			else
			{
				dollars+=(arr[i+1]-arr[i])-energy;
				energy=0;
			}
		}
	}
	cout<<dollars;
}