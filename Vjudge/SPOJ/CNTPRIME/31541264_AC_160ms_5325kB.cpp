#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 10, M = 1e6 + 10;

int n, m, arr[N];
bool isPrime[M];

void sieve() {
    fill(isPrime, isPrime + M, 1);
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i < M / i; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j < M; j += i) {
                isPrime[j] = 0;
            }
        }
    }
}

int tree[4 * N];
int lazy[4 * N];

void build(int si = 0, int ss = 0, int se = n - 1) {
    lazy[si] = -1;
    if (ss == se) {
        tree[si] = isPrime[arr[ss]];
        return;
    }
    int md = ss + (se - ss) / 2, lf = si * 2 + 1, rt = si * 2 + 2;
    build(lf, ss, md);
    build(rt, md + 1, se);
    tree[si] = tree[lf] + tree[rt];
}

void pushdown(int si, int ss, int se) {
    if (ss == se || lazy[si] == -1) return;
    int md = ss + (se - ss) / 2, lf = si * 2 + 1, rt = si * 2 + 2;
    tree[lf] = (md - ss + 1) * isPrime[lazy[si]];
    lazy[lf] = lazy[si];
    tree[rt] = (se - md) * isPrime[lazy[si]];
    lazy[rt] = lazy[si];
    lazy[si] = -1;
}

void update(int qs, int qe, int qv, int si = 0, int ss = 0, int se = n - 1) {
    if (ss > qe || se < qs) return;
    if (ss >= qs && se <= qe) {
        tree[si] = (se - ss + 1) * isPrime[qv];
        lazy[si] = qv;
        return;
    }
    pushdown(si, ss, se);
    int md = ss + (se - ss) / 2, lf = si * 2 + 1, rt = si * 2 + 2;
    update(qs, qe, qv, lf, ss, md);
    update(qs, qe, qv, rt, md + 1, se);
    tree[si] = tree[lf] + tree[rt];
}

int query(int qs, int qe, int si = 0, int ss = 0, int se = n - 1) {
    if (ss > qe || se < qs) return 0;
    if (ss >= qs && se <= qe) return tree[si];
    pushdown(si, ss, se);
    int md = ss + (se - ss) / 2, lf = si * 2 + 1, rt = si * 2 + 2;
    return query(qs, qe, lf, ss, md) + query(qs, qe, rt, md + 1, se);
}

int main() {

    //freopen("meciul.in", "r", stdin);
    //freopen("meciul.out", "w", stdout);

    sieve();

    int t;
    scanf("%d", &t);
    for (int tc = 1; tc <= t; ++tc) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i)
            scanf("%d", arr + i);

        build();

        printf("Case %d:\n", tc);
        for (int i = 0; i < m; ++i) {
            int op, st, en, x;
            scanf("%d%d%d", &op, &st, &en);
            if (op == 0) {
                scanf("%d", &x);
                update(st - 1, en - 1, x);
            } else {
                printf("%d\n", query(st - 1, en - 1));
            }
        }

    }

    return 0;
}