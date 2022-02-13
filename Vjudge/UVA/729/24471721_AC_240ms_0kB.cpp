#include<bits/stdc++.h>

using namespace std;

int t,n,h;
vector<int> v;

void print(){
    for(int i=v.size()-1;i>-1;--i)
        printf("%d",v[i]);
    printf("\n");
}

int main() {
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&h);
        for(int i=0;i<(1<<n);++i){
            int tmp=i,cnt=0;;
            for(int j=0;j<n;++j){
                if(tmp&1)
                    ++cnt,v.push_back(1);
                else
                    v.push_back(0);
                tmp>>=1;
            }
            if(cnt==h)
                print();
            v.clear();
        }
        if(t)
            printf("\n");
    }
	return 0;
}
