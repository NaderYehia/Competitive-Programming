#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e6+10,M=1e3+7,OO=0x3f3f3f3f;

ll mem[2];


int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);


    int n;
    scanf("%d",&n);
    vector<int> arr(n);
    for(int i=0;i<n;++i)
        scanf("%d",&arr[i]);

    int g=0;
    for(int i=0;i<n;++i)
        g=__gcd(g,arr[i]);

    sort(arr.rbegin(),arr.rend());

    int lastDraw=(arr[0]/g)-n;

    if(lastDraw%2==0) printf("Bob");
    else printf("Alice");


    return 0;
}
