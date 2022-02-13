#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e3+10,M=1e3+7,OO=0x3f3f3f3f;


void print(vector<int> &nums,vector<char> &ops,string var){
    printf("%d ",nums[0]);
    for(int i=0;i<ops.size();++i)
        printf("%c %d ",ops[i],nums[i+1]);
    printf("%c %s\n",'=',var.c_str());
}

void delop(int pos,vector<char> &ops){
    for(int i=pos;i<ops.size()-1;++i)
        ops[i]=ops[i+1];
    ops.pop_back();
}

void replc(int i,char op,vector<int> &nums){
    if(op=='+') nums[i]+=nums[i+1];
    else if(op=='-') nums[i]-=nums[i+1];
    else if(op=='*') nums[i]*=nums[i+1];
    else nums[i]/=nums[i+1];
    for(int j=i+1;j<nums.size()-1;++j)
        nums[j]=nums[j+1];
    nums.pop_back();
}

int idx(vector<char> &ops){
    for(int i=0;i<ops.size();++i){
        if(ops[i]=='*'||ops[i]=='/'){
            return i;
        }
    }
    return 0;
}

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    bool first=0;
    string s;
    while(getline(cin,s)){
        if(first) puts("");
        first=1;
        vector<int> nums;
        vector<char> ops;
        string var;
        for(int i=0;s[i];){
            if(s[i]==' ') ++i;
            if(s[i]=='-'||s[i]=='+'||s[i]=='*'||s[i]=='/'){
                int j=i-1;
                while(s[j]==' ') --j;
                if(s[j]=='-'||s[j]=='+'||s[j]=='*'||s[j]=='/'){
                    j=i;
                    ++i;
                    while(s[i]==' ') ++i;
                    int tmp=0;
                    while(s[i]&&s[i]>='0'&&s[i]<='9'){
                        tmp=tmp*10+s[i]-'0';
                        ++i;
                    }
                    if(s[j]=='-') tmp*=-1;
                    nums.push_back(tmp);
                }
                else ops.push_back(s[i]),++i;
            }
            else if(s[i]>='0'&&s[i]<='9'){
                int tmp=0;
                while(s[i]&&s[i]>='0'&&s[i]<='9'){
                    tmp=tmp*10+s[i]-'0';
                    ++i;
                }
                nums.push_back(tmp);
            }
            else{
                ++i;
                while(s[i]==' ') ++i;
                var=s.substr(i);
                break;
            }
        }
        print(nums,ops,var);
        while(ops.size()){
            int cur=idx(ops);
            replc(cur,ops[cur],nums);
            delop(cur,ops);
            print(nums,ops,var);
        }
    }

    return 0;
}
