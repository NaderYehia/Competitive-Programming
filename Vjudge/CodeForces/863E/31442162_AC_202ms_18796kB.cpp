#include <bits/stdc++.h>

using namespace std;

const int N = 6e5 + 10, SQ = 320;

int n, st[N], en[N], vec[N], sz, pre[N];
int tree[4 * N];

void compress() {
    sort(vec, vec + sz);
    sz = unique(vec, vec + sz) - vec;
    for (int i = 0; i < n; ++i) {
        st[i] = lower_bound(vec, vec + sz, st[i]) - vec;
        en[i] = lower_bound(vec, vec + sz, en[i]) - vec;
    }
}

void build(int si = 0, int ss = 0, int se = sz - 1) {
    if (ss == se) {
        tree[si] = (pre[ss] == 1);
        return;
    }
    int md = ss + (se - ss) / 2, lf = si * 2 + 1, rt = si * 2 + 2;
    build(lf, ss, md);
    build(rt, md + 1, se);
    tree[si] = (tree[lf] || tree[rt]);
}

bool query(int qs, int qe, int si = 0, int ss = 0, int se = sz - 1) {
    if (ss > qe || se < qs) return 0;
    if (ss >= qs && se <= qe) return tree[si];
    int md = ss + (se - ss) / 2, lf = si * 2 + 1, rt = si * 2 + 2;
    return (query(qs, qe, lf, ss, md) || query(qs, qe, rt, md + 1, se));
}


int main() {

    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d%d", st + i, en + i), vec[sz++] = st[i], vec[sz++] = en[i], vec[sz++] = st[i] - 1;

    compress();

    for (int i = 0; i < n; ++i)
        pre[st[i]] += 1, pre[en[i] + 1] -= 1;

    for (int i = 1; i < sz; ++i)
        pre[i] += pre[i - 1];

    build();


    for (int i = 0; i < n; ++i) {
        if (query(st[i], en[i]) == 0) return printf("%d\n", i + 1), 0;
    }

    printf("-1\n");

    return 0;
}
