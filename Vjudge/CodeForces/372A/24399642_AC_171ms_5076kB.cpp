#include<bits/stdc++.h>

using namespace std;

const int N=5e5+5;
int n,t,cnt,a;
int arr[N];
vector<int> v;

int main() {

    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",&a),++arr[a];
    for(int i=100000;i>-1;--i)
        while(arr[i]--)
            v.push_back(i);
    int i=0,j=(n+1)/2;
    while(i<(n+1)/2&&j<n){
        if(v[i]>=v[j]*2)
            ++cnt,++i,++j;
        else
            ++j;
    }
    printf("%d",n-cnt);
	return 0;
}
