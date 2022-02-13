#include<bits/stdc++.h>

using namespace std;

string s,s1,s2;
vector<string> v1,v2;
int mem[1005][1005];

int solve(int i,int j){
    if(i==v1.size()||j==v2.size())
        return 0;
    if(mem[i][j]!=-1) return mem[i][j];
    if(v1[i]==v2[j]) return mem[i][j]=1+solve(i+1,j+1);
    return mem[i][j]=max(solve(i+1,j),solve(i,j+1));
}

bool islet(char c){
    if(c>='a'&&c<='z')
        return 1;
    if(c>='A'&&c<='Z')
        return 1;
    if(c>='0'&&c<='9')
        return 1;
    return 0;
}

int main() {
    int tc=1;
    while(getline(cin,s1)&&getline(cin,s2)){
        if(!(int)(s1.length())||!(int)(s2.length())){
            printf("%2d. Blank!\n",tc++);
            continue;
        }
        for(int i=0;s1[i];++i){
            if(!islet(s1[i])){
                s1[i]=' ';
            }
        }
        for(int i=0;s2[i];++i){
            if(!islet(s2[i])){
                s2[i]=' ';
            }
        }
        v1.clear(),v2.clear();
        stringstream ss1(s1);
        while(ss1>>s){
            v1.push_back(s);
        }
        stringstream ss2(s2);
        while(ss2>>s){
            v2.push_back(s);
        }
        memset(mem,-1,sizeof mem);
        printf("%2d. Length of longest match: %d\n",tc++,solve(0,0));
    }
    return 0;
}
