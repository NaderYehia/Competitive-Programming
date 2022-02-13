#include<iostream>
#include<math.h>
using namespace std;
int main(){
int x,y,z,a,b,c;
cin>>x>>y>>z;
cin>>a>>b>>c;
a=a-x;
if(a<0)
cout<<"NO";
else
{
y-=a+b;
if(y>0)
cout<<"NO";
else
{
z-=c+abs(y);
if(z>0)
cout<<"NO";
else
cout<<"YES";
}
}
}
	