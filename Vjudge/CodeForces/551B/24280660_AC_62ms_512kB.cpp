#include<bits/stdc++.h>

using namespace std;

int mxlen,mxb,mxc,db=0x3f3f3f3f,dc=0x3f3f3f3f;
string a,b,c;
int frqA[30];
int frqB[30];
int frqC[30];


int main(){
    cin>>a>>b>>c;
    for(int i=0;a[i];++i)
        ++frqA[a[i]-'a'];
    for(int i=0;b[i];++i)
        ++frqB[b[i]-'a'];
    for(int i=0;c[i];++i)
        ++frqC[c[i]-'a'];
    for(int i=0;i<26;++i)
        if(frqB[i])
            db=min(db,frqA[i]/frqB[i]);
    for(int i=0;i<=db;++i){
        dc=0x3f3f3f3f;
        for(int j=0;j<26;++j)
            if(frqC[j])
                dc=min(dc,(frqA[j]-frqB[j]*i)/frqC[j]);
        if(dc+i>mxb+mxc)
            mxb=i,mxc=dc;
    }
    for(int i=0;i<26;++i)
        frqA[i]-=frqB[i]*mxb;
    for(int i=0;i<26;++i)
        frqA[i]-=frqC[i]*mxc;
    while(mxb--)
        cout<<b;
    while(mxc--)
        cout<<c;
    for(int i=0;i<26;++i)
        while(frqA[i]--)
            cout<<(char)('a'+i);
    return 0;
}
