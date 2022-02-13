#include <bits/stdc++.h>

using namespace std;

const int N = 3e4 + 10, M = 4 * N + 10;

int n, m;
char s[N];
int pre[N];

struct node {
    int mn, lz;

    void addlazy(int val) {
        mn += val;
        lz += val;
    }
};

node tree[4 * N];

void pushdown(int si, int ss, int se) {
    if (ss == se || tree[si].lz == 0) return;
    int md = ss + (se - ss) / 2, lf = si * 2 + 1, rt = si * 2 + 2;
    tree[lf].addlazy(tree[si].lz);
    tree[rt].addlazy(tree[si].lz);
    tree[si].lz = 0;
}

void build(int si = 0, int ss = 0, int se = n - 1) {
    tree[si].lz = 0;
    if (ss == se) {
        tree[si].mn = pre[ss];
        return;
    }
    int md = ss + (se - ss) / 2, lf = si * 2 + 1, rt = si * 2 + 2;
    build(lf, ss, md);
    build(rt, md + 1, se);
    tree[si].mn = min(tree[lf].mn, tree[rt].mn);
}

void update(int qs, int qe, int val, int si = 0, int ss = 0, int se = n - 1) {
    if (ss > qe || se < qs) return;
    if (ss >= qs && se <= qe) {
        tree[si].addlazy(val);
        return;
    }
    pushdown(si, ss, se);
    int md = ss + (se - ss) / 2, lf = si * 2 + 1, rt = si * 2 + 2;
    update(qs, qe, val, lf, ss, md);
    update(qs, qe, val, rt, md + 1, se);
    tree[si].mn = min(tree[lf].mn, tree[rt].mn);
}

int query(int qs, int qe, int si = 0, int ss = 0, int se = n - 1) {
    if (ss > qe || se < qs) return 1e9;
    if (ss >= qs && se <= qe) return tree[si].mn;
    pushdown(si, ss, se);
    int md = ss + (se - ss) / 2, lf = si * 2 + 1, rt = si * 2 + 2;
    return min(query(qs, qe, lf, ss, md), query(qs, qe, rt, md + 1, se));
}

int main() {

    //freopen("meciul.in", "r", stdin);
    //freopen("meciul.out", "w", stdout);

    int tc = 1;
    while (~scanf("%d", &n)) {
        scanf("%s", s);
        pre[0] = (s[0] == '(' ? 1 : -1);
        for (int i = 1; s[i]; ++i)
            pre[i] = pre[i - 1] + (s[i] == '(' ? 1 : -1);


        build();

        printf("Test %d:\n", tc++);
        scanf("%d", &m);
        while (m--) {
            int x;
            scanf("%d", &x);
            if (x) {
                --x;
                if (query(x, x) - (x ? query(x - 1, x - 1) : 0) == 1) {
                    update(x, n - 1, -2);
                } else {
                    update(x, n - 1, 2);
                }
            } else {
                if (query(n - 1, n - 1) == 0 && query(0, n - 1) >= 0) puts("YES");
                else puts("NO");
            }
        }
    }


    return 0;
}