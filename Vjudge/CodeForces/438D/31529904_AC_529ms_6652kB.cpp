#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10, M = 4 * N + 10;

int n, m, arr[N];

pair<int, long long> tree[M];

void build(int si = 0, int ss = 0, int se = n - 1) {
    if (ss == se) {
        tree[si] = {arr[ss], arr[ss]};
        return;
    }
    int md = ss + (se - ss) / 2, lf = si * 2 + 1, rt = si * 2 + 2;
    build(lf, ss, md);
    build(rt, md + 1, se);
    tree[si] = {max(tree[lf].first, tree[rt].first), tree[lf].second + tree[rt].second};
}

void update(int qs, int qe, int mod, int si = 0, int ss = 0, int se = n - 1) {
    if (ss > qe || se < qs || tree[si].first < mod) return;
    if (ss == se) {
        tree[si] = {tree[si].first % mod, tree[si].second % mod};
        return;
    }
    int md = ss + (se - ss) / 2, lf = si * 2 + 1, rt = si * 2 + 2;
    update(qs, qe, mod, lf, ss, md);
    update(qs, qe, mod, rt, md + 1, se);
    tree[si] = {max(tree[lf].first, tree[rt].first), tree[lf].second + tree[rt].second};
}

void sett(int qi, int k, int si = 0, int ss = 0, int se = n - 1) {
    if (ss > qi || se < qi) return;
    if (ss == se) {
        tree[si] = {k, k};
        return;
    }
    int md = ss + (se - ss) / 2, lf = si * 2 + 1, rt = si * 2 + 2;
    sett(qi, k, lf, ss, md);
    sett(qi, k, rt, md + 1, se);
    tree[si] = {max(tree[lf].first, tree[rt].first), tree[lf].second + tree[rt].second};
}

long long query(int qs, int qe, int si = 0, int ss = 0, int se = n - 1) {
    if (ss > qe || se < qs) return 0;
    if (ss >= qs && se <= qe) return tree[si].second;
    int md = ss + (se - ss) / 2, lf = si * 2 + 1, rt = si * 2 + 2;
    return query(qs, qe, lf, ss, md) + query(qs, qe, rt, md + 1, se);
}

int main() {

    //freopen("meciul.in", "r", stdin);
    //freopen("meciul.out", "w", stdout);


    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf("%d", arr + i);

    build();

    for (int i = 0; i < m; ++i) {
        int op;
        scanf("%d", &op);
        if (op == 1) {
            int l, r;
            scanf("%d%d", &l, &r);
            printf("%lld\n", query(l - 1, r - 1));
        } else if (op == 2) {
            int l, r, mod;
            scanf("%d%d%d", &l, &r, &mod);
            update(l - 1, r - 1, mod);
        } else {
            int idx, k;
            scanf("%d%d", &idx, &k);
            sett(idx - 1, k);
        }
    }

    return 0;
}