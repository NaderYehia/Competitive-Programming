#include<bits/stdc++.h>

using namespace std;

const int N = 1e6+6,M=1e9+7,OO=0x3f3f3f3f;

int n,m,k,dots;
string s;

int main(){
    cin>>s;
    if(s=="Sunny")
        printf("Cloudy");
    else if(s=="Cloudy")
        printf("Rainy");
    else
        printf("Sunny");
    return 0;
}
