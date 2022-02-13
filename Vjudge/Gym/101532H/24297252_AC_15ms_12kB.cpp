#include<bits/stdc++.h>

using namespace std;

const int N=1e7+5;
char s[100][100];
int n,m,t;

int main() {
	scanf("%d",&t);
	while(t--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;++i)
            scanf("%s",s[i]);
        int reqO=(2*n)+(2*(m-2)),o=0;
        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j)
                if(s[i][j]=='1')
                    ++o;
        if(o<reqO){
            printf("-1\n");
            continue;
        }
        int z=0;
        for(int i=0;i<m;++i){
            if(s[0][i]=='0')
                ++z;
            if(s[n-1][i]=='0')
                ++z;
        }
        for(int i=1;i<n-1;++i){
            if(s[i][0]=='0')
                ++z;
            if(s[i][m-1]=='0')
                ++z;
        }
        printf("%d\n",z);
	}
	return 0;
}
