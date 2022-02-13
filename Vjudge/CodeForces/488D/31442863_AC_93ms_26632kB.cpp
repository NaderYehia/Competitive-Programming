#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10, M = 1e6 + 10;

int n, s, l, arr[N];
int sparse[30][N][2], lg[N];
int g[N], dp[N];

void buildSparse() {
    lg[0] = -1;
    for (int i = 1; i <= n; ++i) {
        sparse[0][i][0] = sparse[0][i][1] = arr[i];
        lg[i] = lg[i - 1] + !(i & (i - 1));
    }
    for (int i = 1; (1 << i) <= n + 1; ++i) {
        for (int j = 1; j + (1 << i) <= n + 1; ++j) {
            int a = sparse[i - 1][j][0];
            int b = sparse[i - 1][j + (1 << (i - 1))][0];
            sparse[i][j][0] = max(a, b);
            a = sparse[i - 1][j][1];
            b = sparse[i - 1][j + (1 << (i - 1))][1];
            sparse[i][j][1] = min(a, b);
        }
    }
}

int querysparse(int qs, int qe) {
    int sz = qe - qs + 1;
    int l = lg[sz];
    int a = sparse[l][qs][0];
    int b = sparse[l][qe - (1 << l) + 1][0];
    int mx = max(a, b);
    a = sparse[l][qs][1];
    b = sparse[l][qe - (1 << l) + 1][1];
    int mn = min(a, b);
    return mx - mn;
}

int tree[4 * N];

void build(int si = 0, int ss = 0, int se = n) {
    if (ss == se) {
        tree[si] = 2e9;
        return;
    }
    int md = ss + (se - ss) / 2, lf = si * 2 + 1, rt = si * 2 + 2;
    build(lf, ss, md);
    build(rt, md + 1, se);
    tree[si] = 2e9;
}

void update(int qi, int val, int si = 0, int ss = 0, int se = n) {
    if (ss > qi || se < qi) return;
    if (ss == se) {
        tree[si] = val;
        return;
    }
    int md = ss + (se - ss) / 2, lf = si * 2 + 1, rt = si * 2 + 2;
    update(qi, val, lf, ss, md);
    update(qi, val, rt, md + 1, se);
    tree[si] = min(tree[lf], tree[rt]);
}

int query(int qs, int qe, int si = 0, int ss = 0, int se = n) {
    if (ss > qe || se < qs) return 2e9;
    if (ss >= qs && se <= qe) return tree[si];
    int md = ss + (se - ss) / 2, lf = si * 2 + 1, rt = si * 2 + 2;
    return min(query(qs, qe, lf, ss, md), query(qs, qe, rt, md + 1, se));
}

int main() {

    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    scanf("%d%d%d", &n, &s, &l);
    for (int i = 1; i <= n; ++i)
        scanf("%d", arr + i);

    buildSparse();

    for (int i = 1; i <= n; ++i) {
        int lo = 1, hi = i, md;
        while (lo < hi) {
            md = lo + (hi - lo) / 2;
            if (querysparse(md, i) <= s) hi = md;
            else lo = md + 1;
        }
        g[i] = i - lo + 1;
    }

    if (g[l] < l) return printf("-1\n"), 0;

    build();
    update(0, 0);
    dp[0] = 0;
    update(l, 1);
    dp[l] = 1;
    for (int i = l + 1; i <= n; ++i) {
        int a = i - g[i], b = i - l;
        dp[i] = query(a, b) + 1;
        update(i, dp[i]);
    }

    printf("%d\n", (dp[n] >= 2e9 ? -1 : dp[n]));

    return 0;
}
