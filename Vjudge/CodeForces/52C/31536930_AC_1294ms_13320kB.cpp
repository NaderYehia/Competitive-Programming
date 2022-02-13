#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10, M = 4 * N + 10;

int n, m, arr[N];

long long tree[M];
long long lazy[M];

void build(int si = 0, int ss = 0, int se = n - 1) {
    if (ss == se) {
        tree[si] = arr[ss];
        return;
    }
    int md = ss + (se - ss) / 2, lf = si * 2 + 1, rt = si * 2 + 2;
    build(lf, ss, md);
    build(rt, md + 1, se);
    tree[si] = min(tree[lf], tree[rt]);
}

void pushdown(int si, int ss, int se) {
    if (ss == se || lazy[si] == 0) return;
    int md = ss + (se - ss) / 2, lf = si * 2 + 1, rt = si * 2 + 2;
    tree[lf] += lazy[si];
    lazy[lf] += lazy[si];
    tree[rt] += lazy[si];
    lazy[rt] += lazy[si];
    lazy[si] = 0;
}

void update(int qs, int qe, int qv, int si = 0, int ss = 0, int se = n - 1) {
    if (ss > qe || se < qs) return;
    if (ss >= qs && se <= qe) {
        tree[si] += qv;
        lazy[si] += qv;
        return;
    }
    pushdown(si, ss, se);
    int md = ss + (se - ss) / 2, lf = si * 2 + 1, rt = si * 2 + 2;
    update(qs, qe, qv, lf, ss, md);
    update(qs, qe, qv, rt, md + 1, se);
    tree[si] = min(tree[lf], tree[rt]);
}

long long query(int qs, int qe, int si = 0, int ss = 0, int se = n - 1) {
    if (ss > qe || se < qs) return LONG_LONG_MAX;
    if (ss >= qs && se <= qe) return tree[si];
    pushdown(si, ss, se);
    int md = ss + (se - ss) / 2, lf = si * 2 + 1, rt = si * 2 + 2;
    return min(query(qs, qe, lf, ss, md), query(qs, qe, rt, md + 1, se));
}

int main() {

    //freopen("meciul.in", "r", stdin);
    //freopen("meciul.out", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", arr + i);

    build();

    scanf("%d\n", &m);
    for (int i = 0; i < m; ++i) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        int st, en, v;
        ss >> st;
        ss >> en;
        if (ss >> v) {
            if (st <= en) {
                update(st, en, v);
            } else {
                update(st, n - 1, v);
                update(0, en, v);
            }
        } else {
            if (st <= en) {
                printf("%lld\n", query(st, en));
            } else {
                printf("%lld\n", min(query(st, n - 1), query(0, en)));
            }
        }
    }

    return 0;
}