#include<bits/stdc++.h>

using namespace std;

const int N = 1e3+6,M=1e9+7,OO=0x3f3f3f3f;

int t,n,m,k,sum;
string l,o;
vector<string>v;
vector<string>tmpv;

void print(){
    for(int i=0;i<tmpv.size();++i){
        cout<<tmpv[i];
        if(i==tmpv.size()-1)
            puts("");
        else
            printf(", ");
    }
}

void solve(int i,int n){
    if(tmpv.size()==n)
        print();
    if(i==v.size()||tmpv.size()>=n)
        return;
    tmpv.push_back(v[i]);
    solve(i+1,n);
    tmpv.pop_back();
    solve(i+1,n);
}

int main(){
    scanf("%d\n",&t);
    while(t--){
        v.clear();
        int a=-1,b=-1;
        getline(cin,o);
        while(getline(cin,l),l!="")
            v.push_back(l);
        if(o=="*")
            a=1,b=v.size();
        else if(sscanf(o.c_str(),"%d %d",&a,&b)==1)
            b=a;
        for(int i=a;i<=b;++i){
            printf("Size %d\n",i);
            solve(0,i);
            puts("");
        }
        if(t)
            puts("");
    }
    return 0;
}
