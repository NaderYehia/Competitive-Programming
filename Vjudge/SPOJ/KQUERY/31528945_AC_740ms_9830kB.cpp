#include <bits/stdc++.h>

using namespace std;

const int N = 3e4 + 10, M = 4 * N + 10;

int n, m, arr[N];

vector<int> tree[4 * N];

void build(int si = 0, int ss = 0, int se = n - 1) {
    if (ss == se) {
        tree[si] = {arr[ss]};
        return;
    }
    int md = ss + (se - ss) / 2, lf = si * 2 + 1, rt = si * 2 + 2;
    build(lf, ss, md);
    build(rt, md + 1, se);
    merge(tree[lf].begin(), tree[lf].end(), tree[rt].begin(), tree[rt].end(), inserter(tree[si], tree[si].begin()));
}

int query(int qs, int qe, int k, int si = 0, int ss = 0, int se = n - 1) {
    if (ss > qe || se < qs) return 0;
    if (ss >= qs && se <= qe) return int(tree[si].end() - upper_bound(tree[si].begin(), tree[si].end(), k));
    int md = ss + (se - ss) / 2, lf = si * 2 + 1, rt = si * 2 + 2;
    return query(qs, qe, k, lf, ss, md) + query(qs, qe, k, rt, md + 1, se);
}

int main() {

    //freopen("meciul.in", "r", stdin);
    //freopen("meciul.out", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", arr + i);

    build();

    scanf("%d", &m);
    while (m--) {
        int i, j, k;
        scanf("%d%d%d", &i, &j, &k);
        --i, --j;
        printf("%d\n", query(i, j, k));
    }

    return 0;
}