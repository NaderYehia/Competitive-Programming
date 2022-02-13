#include<bits/stdc++.h>
 
using namespace std;
 
int t,a,b,u,v;
 
 
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d",&a,&b,&u,&v);
        int x=b-a;
        if((x%(u+v))==0)
            cout<<x/(u+v)<<endl;
        else
            cout<<-1<<endl;
    }
    return 0;
}