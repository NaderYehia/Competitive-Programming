#include<bits/stdc++.h>

using namespace std;

const int N=2e3+5;
int t,n,m;
vector<int> vp;

int main() {
    scanf("%d\n",&t);
    while(t--){
        string s;
        getline(cin,s);
        stringstream ss(s);
        int tmp;
        while(ss>>tmp)
            vp.push_back(tmp);
        bool found=0;
        for(int i=0;i<(1<<vp.size());++i){
            int msk=i,sum1=0,sum2=0;
            for(int j=0;j<vp.size();++j){
                if(msk&1)
                    sum1+=vp[j];
                else
                    sum2+=vp[j];
                msk>>=1;
            }
            if(sum1==sum2){
                found=1;
                break;
            }
        }
        if(found)
            printf("YES\n");
        else
            printf("NO\n");
        vp.clear();
    }
    return 0;
}
