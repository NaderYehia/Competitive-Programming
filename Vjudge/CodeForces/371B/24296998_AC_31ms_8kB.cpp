#include<bits/stdc++.h>
 
using namespace std;
 
int a,b,a2,a3,a5,b2,b3,b5;
 
int main(){
    scanf("%d%d",&a,&b);
    while(a%2==0){
        a/=2;
        ++a2;
    }
    while(a%3==0){
        a/=3;
        ++a3;
    }
    while(a%5==0){
        a/=5;
        ++a5;
    }
    while(b%2==0){
        b/=2;
        ++b2;
    }
    while(b%3==0){
        b/=3;
        ++b3;
    }
    while(b%5==0){
        b/=5;
        ++b5;
    }
    if(a!=b){
        printf("-1");
        return 0;
    }
    printf("%d",(abs(a2-b2)+abs(a3-b3)+abs(a5-b5)));
    return 0;
}