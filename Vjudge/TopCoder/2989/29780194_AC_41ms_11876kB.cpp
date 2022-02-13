#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e3+10,M=2e4+7,OO=0x3f3f3f3f;
const double eps=1e-9;


class QuizShow{
public:
    int wager(vector<int> scores, int wager1, int wager2){
        int ans=0,cnt=0;
        for(int w=0;w<=scores[0];++w){
            int cur=0;
            for(int i=-1;i<2;i+=2){
                for(int j=-1;j<2;j+=2){
                    for(int k=-1;k<2;k+=2){
                        int s0=w*i+scores[0];
                        int s1=wager1*j+scores[1];
                        int s2=wager2*k+scores[2];
                        cur+=(s0>s1&&s0>s2);
                    }
                }
            }
            if(cur>cnt) cnt=cur,ans=w;
        }
        return ans;
    }

};


