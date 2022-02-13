#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n, m, a[N], b[N], tree[4 * N];


void push_down(int si, int ss, int se) {
    if (ss == se || tree[si] == -1) return;
    int md = ss + (se - ss) / 2, lf = si * 2 + 1, rt = si * 2 + 2;
    tree[lf] = tree[si];
    tree[rt] = tree[si] + (md - ss) + 1;
    tree[si] = -1;
}

void update(int qs, int qe, int x, int si = 0, int ss = 0, int se = n - 1) {
    if (ss > qe || se < qs) return;
    if (ss >= qs && se <= qe) {
        tree[si] = x + (ss - qs);
        return;
    }
    push_down(si, ss, se);
    int md = ss + (se - ss) / 2, lf = si * 2 + 1, rt = si * 2 + 2;
    update(qs, qe, x, lf, ss, md);
    update(qs, qe, x, rt, md + 1, se);
}

int query(int qi, int si = 0, int ss = 0, int se = n - 1) {
    if (ss == se) {
        return tree[si] == -1 ? b[ss] : a[tree[si]];
    }
    push_down(si, ss, se);
    int md = ss + (se - ss) / 2, lf = si * 2 + 1, rt = si * 2 + 2;
    if (qi <= md) return query(qi, lf, ss, md);
    return query(qi, rt, md + 1, se);
}

int main() {

    //freopen("meciul.in", "r", stdin);
    //freopen("meciul.out", "w", stdout);

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf("%d", a + i);
    for (int i = 0; i < n; ++i)
        scanf("%d", b + i);

    memset(tree, -1, sizeof tree);

    while (m--) {
        int op, x, y, k;
        scanf("%d%d", &op, &x);
        if (op == 1) {
            scanf("%d%d", &y, &k);
            update(y - 1, y + k - 2, x - 1);
        } else {
            printf("%d\n", query(x - 1));
        }
    }

    return 0;
}