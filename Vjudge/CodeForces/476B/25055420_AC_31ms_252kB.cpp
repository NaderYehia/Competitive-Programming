#include<bits/stdc++.h>

using namespace std;

const int N=2e5+5;
int t,n,c;
string s1,s2;

int main() {
    cin>>s1>>s2;
    int sum1=0,sum2=0,un=0;
    for(int i=0;s1[i];++i)
        if(s1[i]=='+')
            ++sum1;
        else
            --sum1;
    for(int i=0;s2[i];++i){
        if(s2[i]=='+')
            ++sum2;
        else if(s2[i]=='-')
            --sum2;
        else
            ++un;
    }
    int tr=0;
    for(int i=0;i<(1<<un);++i){
        int sum=0;
        for(int j=0;j<un;++j){
            if((i>>j)&1)
                ++sum;
            else
                --sum;
        }
        if(sum==sum1-sum2)
            ++tr;
    }
    printf("%.9lf",(double)tr/pow(2,un));
    return 0;
}
