#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 250005, M = 10005, MAX_SQ = 500, MAX_VAL = 5e4;
 
int BIT[1<<9][1<<16], A[N], n, q, idx, val;
long long R;
 
int get(int i, int j) {
    ++i, ++j;
    int res = 0;
    while (i) {
        int jj = j;
        while(jj){
            res += BIT[i - 1][jj-1];
            jj -= (jj & -jj);
        }
        i -= (i & -i);
    }
    return res;
}
 
void add(int i, int j, int val) {
    ++i, ++j;
    while (i <=MAX_SQ) {
        int jj =j;
        while(jj<=MAX_VAL){
            BIT[i - 1][jj-1] += val;
            jj += (jj & -jj);
        }
 
        i += (i & -i);
    }
}
 
int get(int iMn, int jMn, int iMx, int jMx){
    return get(iMx, jMx) - get(iMn-1, jMx)
                - get(iMx, jMn-1) + get(iMn-1, jMn-1);
}
 
int bruteForce(int l, int r, int idx){
  int ret = 0;
  for(int i=l; i<idx; i++){
    ret += (A[i]>A[idx]);
  }
  for(int i=idx+1; i<=r; i++){
    ret += (A[i]<A[idx]);
  }
  return ret;
}
 
int main() {
 
//  freopen("input.in", "r", stdin);
//  freopen("output.out", "w", stdout);
//	cin.sync_with_stdio(0);
 
  scanf("%d", &n);
  for(int i=0; i<n; i++){
    scanf("%d", A+i);
    int x = MAX_VAL - A[i];
    R += get(MAX_SQ-1, x-1);
    add(MAX_SQ-1, x, 1);
  }
//  cout << R << endl;
  memset(BIT[MAX_SQ-1], 0, sizeof BIT[MAX_SQ-1]);
//  cout << sizeof(BIT[0]) << endl;
  int sq = sqrt(n);
  for(int i=0; i<n; i++){
    int blkId = i/sq;
    add(blkId, A[i], 1);
  }
  scanf("%d", &q);
  while(q--){
    scanf("%d %d", &idx, &val);
    --idx;
    int blkId = idx / sq;
//    cout << blkId << endl;
    R -= get(0, A[idx]+1, blkId-1, MAX_VAL);
//    printf("%lld\n", R);
    R -= get(blkId+1, 0, (n+sq-1)/sq, A[idx]-1);
//    printf("%lld\n", R);
    R -= bruteForce(blkId*sq, blkId*sq+sq-1, idx);
//    printf("%lld\n", R);
    add(blkId, A[idx], -1);
    A[idx] = val;
    R += get(0, A[idx]+1, blkId-1, MAX_VAL);
//    printf("%lld\n", R);
    R += get(blkId+1, 0, (n+sq-1)/sq, A[idx]-1);
//    printf("%lld\n", R);
    R += bruteForce(blkId*sq, blkId*sq+sq-1, idx);
//    printf("%lld\n", R);
    add(blkId, A[idx], 1);
    printf("%lld\n", R);
//    return 0;
  }
 
  return 0;
}