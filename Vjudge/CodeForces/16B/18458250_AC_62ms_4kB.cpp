#include<iostream>
using namespace std;
void swap(int* a, int* b){ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
int partition (int arr[],int ab[], int low, int high){ 
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high- 1; j++){
        if (arr[j] <= pivot){ 
            i++; 
            swap(&arr[i], &arr[j]);
			swap(&ab[i],&ab[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]);
	swap(&ab[i+1],&ab[high]); 
    return (i + 1); 
}
void quickSort(int arr[],int ab[], int low, int high) { 
    if (low < high) { 
        int pi = partition(arr,ab, low, high); 
        quickSort(arr,ab, low, pi - 1); 
        quickSort(arr,ab, pi + 1, high); 
    } 
} 
int main(){
	int n,m,sum=0;
	cin>>n>>m;
	int boxes[m],matches[m];
	for(int i=0;i<m;i++)
		cin>>boxes[i]>>matches[i];
		quickSort(matches,boxes,0,m-1);
	for(int i=m-1;i>-1;i--){
		if(n>0){
			if(boxes[i]<=n){
				sum+= boxes[i] * matches[i];
				n-=boxes[i];
	}
			else{
				sum+=n * matches[i];
				n=0;
			}
	}
		else
		break;
	}
	cout<<sum;
}