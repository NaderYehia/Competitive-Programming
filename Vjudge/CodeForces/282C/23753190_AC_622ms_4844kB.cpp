#include<bits/stdc++.h>

using namespace std;

const int N = 1e6+6,M=1e9+7,OO=0x3f3f3f3f;



int main(){
    string a,b;
    cin>>a>>b;
    if(a==b){
        puts("YES");
        return 0;
    }
    if(a.length()==b.length()){
        if(a.find('1')!=-1&&b.find('1')!=-1){
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}
