#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10, M = 4 * N + 10;

int n, m;
int tree[M][3];
int lazy[M];

void build(int si = 0, int ss = 0, int se = n - 1) {
    if (ss == se) {
        tree[si][0] = 1;
        return;
    }
    int md = ss + (se - ss) / 2, lf = si * 2 + 1, rt = si * 2 + 2;
    build(lf, ss, md);
    build(rt, md + 1, se);
    for (int i = 0; i < 3; ++i) tree[si][i] = tree[lf][i] + tree[rt][i];
}

void go(int si) {
    swap(tree[si][0], tree[si][2]);
    swap(tree[si][1], tree[si][2]);
}

void pushdown(int si, int ss, int se) {
    if (ss == se || lazy[si] == 0) return;
    int md = ss + (se - ss) / 2, lf = si * 2 + 1, rt = si * 2 + 2;
    lazy[lf] = (lazy[si] + lazy[lf]) % 3;
    lazy[rt] = (lazy[si] + lazy[rt]) % 3;
    while (lazy[si]) {
        --lazy[si];
        go(lf);
        go(rt);
    }
}

void update(int qs, int qe, int si = 0, int ss = 0, int se = n - 1) {
    if (ss > qe || se < qs) return;
    if (ss >= qs && se <= qe) {
        go(si);
        lazy[si] = (lazy[si] + 1) % 3;
        return;
    }
    pushdown(si, ss, se);
    int md = ss + (se - ss) / 2, lf = si * 2 + 1, rt = si * 2 + 2;
    update(qs, qe, lf, ss, md);
    update(qs, qe, rt, md + 1, se);
    for (int i = 0; i < 3; ++i) tree[si][i] = tree[lf][i] + tree[rt][i];
}

int query(int qs, int qe, int si = 0, int ss = 0, int se = n - 1) {
    if (ss > qe || se < qs) return 0;
    if (ss >= qs && se <= qe) return tree[si][0];
    pushdown(si, ss, se);
    int md = ss + (se - ss) / 2, lf = si * 2 + 1, rt = si * 2 + 2;
    return query(qs, qe, lf, ss, md) + query(qs, qe, rt, md + 1, se);
}

int main() {

    //freopen("meciul.in", "r", stdin);
    //freopen("meciul.out", "w", stdout);

    scanf("%d%d", &n, &m);
    build();

    for (int i = 0; i < m; ++i) {
        int op, l, r;
        scanf("%d%d%d", &op, &l, &r);
        if (op) {
            printf("%d\n", query(l, r));
        } else {
            update(l, r);
        }
    }

    return 0;
}