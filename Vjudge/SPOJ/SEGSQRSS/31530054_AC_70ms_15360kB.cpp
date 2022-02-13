#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10, M = 4 * N + 10;

int n, m, arr[N];

struct node {
    long long sum, sum2, setval, addval;
    bool there;

    void setlazy(int ss, int se, long long val) {
        there = 1;
        sum = (se - ss + 1) * val;
        sum2 = (se - ss + 1) * val * val;
        setval = val;
        addval = 0;
    }

    void addlazy(int ss, int se, long long val) {
        sum2 = sum2 + (se - ss + 1) * val * val + 2 * sum * val;
        sum = sum + (se - ss + 1) * val;
        addval += val;
    }

};

node tree[M];

void build(int si = 0, int ss = 0, int se = n - 1) {
    tree[si].addval = 0;
    tree[si].there = 0;
    if (ss == se) {
        tree[si].sum = arr[ss];
        tree[si].sum2 = arr[ss] * arr[ss];
        return;
    }
    int md = ss + (se - ss) / 2, lf = si * 2 + 1, rt = si * 2 + 2;
    build(lf, ss, md);
    build(rt, md + 1, se);
    tree[si].sum = tree[lf].sum + tree[rt].sum;
    tree[si].sum2 = tree[lf].sum2 + tree[rt].sum2;
}

void pushdown(int si, int ss, int se) {
    if (ss == se || (tree[si].addval == 0 && !tree[si].there)) return;
    int md = ss + (se - ss) / 2, lf = si * 2 + 1, rt = si * 2 + 2;
    if (tree[si].there) {
        tree[lf].setlazy(ss, md, tree[si].setval);
        tree[rt].setlazy(md + 1, se, tree[si].setval);
        tree[si].there = 0;
    } else {
        tree[lf].addlazy(ss, md, tree[si].addval);
        tree[rt].addlazy(md + 1, se, tree[si].addval);
        tree[si].addval = 0;
    }
}

void sett(int qs, int qe, int x, int si = 0, int ss = 0, int se = n - 1) {
    if (ss > qe || se < qs) return;
    if (ss >= qs && se <= qe) {
        tree[si].setlazy(ss, se, x);
        return;
    }
    pushdown(si, ss, se);
    int md = ss + (se - ss) / 2, lf = si * 2 + 1, rt = si * 2 + 2;
    sett(qs, qe, x, lf, ss, md);
    sett(qs, qe, x, rt, md + 1, se);
    tree[si].sum = tree[lf].sum + tree[rt].sum;
    tree[si].sum2 = tree[lf].sum2 + tree[rt].sum2;
}

void add(int qs, int qe, int x, int si = 0, int ss = 0, int se = n - 1) {
    if (ss > qe || se < qs) return;
    if (ss >= qs && se <= qe) {
        tree[si].addlazy(ss, se, x);
        return;
    }
    pushdown(si, ss, se);
    int md = ss + (se - ss) / 2, lf = si * 2 + 1, rt = si * 2 + 2;
    add(qs, qe, x, lf, ss, md);
    add(qs, qe, x, rt, md + 1, se);
    tree[si].sum = tree[lf].sum + tree[rt].sum;
    tree[si].sum2 = tree[lf].sum2 + tree[rt].sum2;
}

long long query(int qs, int qe, int si = 0, int ss = 0, int se = n - 1) {
    if (ss > qe || se < qs) return 0;
    if (ss >= qs && se <= qe) return tree[si].sum2;
    pushdown(si, ss, se);
    int md = ss + (se - ss) / 2, lf = si * 2 + 1, rt = si * 2 + 2;
    return query(qs, qe, lf, ss, md) + query(qs, qe, rt, md + 1, se);
}

int main() {

    //freopen("meciul.in", "r", stdin);
    //freopen("meciul.out", "w", stdout);

    int t, tc = 1;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i)
            scanf("%d", arr + i);

        build();

        printf("Case %d:\n", tc++);
        for (int i = 0; i < m; ++i) {
            int op, st, en, x;
            scanf("%d%d%d", &op, &st, &en);
            if (op == 0) {
                scanf("%d", &x);
                sett(st - 1, en - 1, x);
            } else if (op == 1) {
                scanf("%d", &x);
                add(st - 1, en - 1, x);
            } else {
                printf("%lld\n", query(st - 1, en - 1));
            }
        }
    }


    return 0;
}