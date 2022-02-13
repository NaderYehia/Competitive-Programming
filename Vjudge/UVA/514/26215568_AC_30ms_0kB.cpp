#include <bits/stdc++.h>

using namespace std;

const int N=1e3+5,OO=0x3f3f3f3f;
int t,n,m,k,q;
int arr[N];


int main(){
    while(~scanf("%d",&n),n){
        bool stop=0;
        while(true){
            for(int i=0;i<n;++i){
                scanf("%d",arr+i);
                if(i==0&&arr[i]==0){
                    stop=1;
                    break;
                }
            }
            if(stop) break;
            stack<int> st;
            int j=0;
            for(int i=1;i<=n;++i){
                if(i==arr[j]) j++;
                else st.push(i);
                while(st.size()&&st.top()==arr[j]){
                    j++;
                    st.pop();
                }
            }
            if(st.size()) printf("No\n");
            else printf("Yes\n");
        }
        printf("\n");
    }
    return 0;
}
