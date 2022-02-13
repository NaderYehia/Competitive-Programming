#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 10, M = 1e6 + 10;

int arr[N], n, m;
int lp[M], D[M];

void sieve() {
    iota(lp, lp + M, 0);
    for (int i = 2; i < M / i; ++i) {
        if (i == lp[i]) {
            for (int j = i * i; j < M; j += i)
                lp[j] = min(lp[j], i);
        }
    }
    for (int i = 1; i < M; ++i) {
        D[i] = 1;
        int cur = i, cnt = 0, last = lp[cur];
        while (cur > 1) {
            while (last == lp[cur]) {
                ++cnt;
                last = lp[cur];
                cur /= lp[cur];
            }
            D[i] *= cnt + 1;
            cnt = 0;
            last = lp[cur];
        }
    }
}

long long tree[4 * N];
bool smallerThan2[4 * N];

void build(int si = 0, int ss = 0, int se = n - 1) {
    if (ss == se) {
        tree[si] = arr[ss];
        smallerThan2[si] = (arr[ss] <= 2);
        return;
    }
    int md = ss + (se - ss) / 2, lf = si * 2 + 1, rt = si * 2 + 2;
    build(lf, ss, md);
    build(rt, md + 1, se);
    tree[si] = tree[lf] + tree[rt];
    smallerThan2[si] = smallerThan2[lf] && smallerThan2[rt];
}

long long query(int qs, int qe, int si = 0, int ss = 0, int se = n - 1) {
    if (ss > qe || se < qs) return 0;
    if (ss >= qs && se <= qe) return tree[si];
    int md = ss + (se - ss) / 2, lf = si * 2 + 1, rt = si * 2 + 2;
    return query(qs, qe, lf, ss, md) + query(qs, qe, rt, md + 1, se);
}

void update(int qs, int qe, int si = 0, int ss = 0, int se = n - 1) {
    if (ss > qe || se < qs || smallerThan2[si]) return;
    if (ss == se) {
        tree[si] = D[tree[si]];
        smallerThan2[si] = (tree[si] <= 2);
        return;
    }
    int md = ss + (se - ss) / 2, lf = si * 2 + 1, rt = si * 2 + 2;
    update(qs, qe, lf, ss, md);
    update(qs, qe, rt, md + 1, se);
    tree[si] = tree[lf] + tree[rt];
    smallerThan2[si] = smallerThan2[lf] && smallerThan2[rt];
}

int main() {

    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    sieve();

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf("%d", arr + i);

    build();

    while (m--) {
        int op, a, b;
        scanf("%d%d%d", &op, &a, &b);
        if (op == 1) {
            update(--a, --b);
        } else {
            printf("%lld\n", query(--a, --b));
        }
    }

    return 0;
}
