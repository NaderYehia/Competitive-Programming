#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10, M = 4 * N + 10;

int n, m, arr[N];

int tree[M][20];
int lazy[M];

void build(int si = 0, int ss = 0, int se = n - 1) {
    if (ss == se) {
        for (int i = 0; i < 20; ++i) tree[si][i] = (arr[ss] >> i) & 1;
        return;
    }
    int md = ss + (se - ss) / 2, lf = si * 2 + 1, rt = si * 2 + 2;
    build(lf, ss, md);
    build(rt, md + 1, se);
    for (int i = 0; i < 20; ++i) tree[si][i] = tree[lf][i] + tree[rt][i];
}

void pushdown(int si, int ss, int se) {
    if (ss == se || lazy[si] == 0) return;
    int md = ss + (se - ss) / 2, lf = si * 2 + 1, rt = si * 2 + 2;
    for (int i = 0; i < 20; ++i) if ((1 << i) & lazy[si]) tree[lf][i] = (md - ss + 1) - tree[lf][i];
    lazy[lf] ^= lazy[si];
    for (int i = 0; i < 20; ++i) if ((1 << i) & lazy[si]) tree[rt][i] = (se - md) - tree[rt][i];
    lazy[rt] ^= lazy[si];
    lazy[si] = 0;
}

void update(int qs, int qe, int x, int si = 0, int ss = 0, int se = n - 1) {
    if (ss > qe || se < qs) return;
    if (ss >= qs && se <= qe) {
        for (int i = 0; i < 20; ++i) if ((x >> i) & 1) tree[si][i] = (se - ss + 1) - tree[si][i];
        lazy[si] ^= x;
        return;
    }
    pushdown(si, ss, se);
    int md = ss + (se - ss) / 2, lf = si * 2 + 1, rt = si * 2 + 2;
    update(qs, qe, x, lf, ss, md);
    update(qs, qe, x, rt, md + 1, se);
    for (int i = 0; i < 20; ++i) tree[si][i] = tree[lf][i] + tree[rt][i];
}

long long query(int qs, int qe, int si = 0, int ss = 0, int se = n - 1) {
    if (ss > qe || se < qs) return 0;
    if (ss >= qs && se <= qe) {
        long long ret = 0;
        for (int i = 0; i < 20; ++i) ret += tree[si][i] * 1ll * (1 << i);
        return ret;
    }
    pushdown(si, ss, se);
    int md = ss + (se - ss) / 2, lf = si * 2 + 1, rt = si * 2 + 2;
    return query(qs, qe, lf, ss, md) + query(qs, qe, rt, md + 1, se);
}

int main() {

    //freopen("meciul.in", "r", stdin);
    //freopen("meciul.out", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", arr + i);

    build();

    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        int op, st, en, x;
        scanf("%d%d%d", &op, &st, &en);
        if (op == 1) {
            printf("%lld\n", query(st - 1, en - 1));
        } else {
            scanf("%d", &x);
            update(st - 1, en - 1, x);

        }
    }

    return 0;
}