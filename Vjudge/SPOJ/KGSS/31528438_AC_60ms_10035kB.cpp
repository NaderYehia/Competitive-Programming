#include <bits/stdc++.h>

using namespace std;

const int N = (1 << 17) + 10, M = 4 * N + 10;

int n, m;
long long arr[N];
pair<long long, long long> tree[M];


void build(int si = 0, int ss = 0, int se = n - 1) {
    if (ss == se) {
        tree[si] = {arr[ss], -1};
        return;
    }
    int md = ss + (se - ss) / 2, lf = si * 2 + 1, rt = si * 2 + 2;
    build(lf, ss, md);
    build(rt, md + 1, se);
    if (tree[lf].first > tree[rt].first) {
        tree[si] = {tree[lf].first, max(tree[lf].second, tree[rt].first)};
    } else {
        tree[si] = {tree[rt].first, max(tree[rt].second, tree[lf].first)};
    }
}

void update(int qi, long long qv, int si = 0, int ss = 0, int se = n - 1) {
    if (ss > qi || se < qi) return;
    if (ss == se) {
        tree[si] = {qv, -1};
        return;
    }
    int md = ss + (se - ss) / 2, lf = si * 2 + 1, rt = si * 2 + 2;
    update(qi, qv, lf, ss, md);
    update(qi, qv, rt, md + 1, se);
    if (tree[lf].first > tree[rt].first) {
        tree[si] = {tree[lf].first, max(tree[lf].second, tree[rt].first)};
    } else {
        tree[si] = {tree[rt].first, max(tree[rt].second, tree[lf].first)};
    }
}

pair<long long, long long> query(int qs, int qe, int si = 0, int ss = 0, int se = n - 1) {
    if (ss > qe || se < qs) return {-1, -1};
    if (ss >= qs && se <= qe) return tree[si];
    int md = ss + (se - ss) / 2, lf = si * 2 + 1, rt = si * 2 + 2;
    pair<long long, long long> lft = query(qs, qe, lf, ss, md);
    pair<long long, long long> rit = query(qs, qe, rt, md + 1, se);
    if (lft.first > rit.first) {
        return {lft.first, max(lft.second, rit.first)};
    } else {
        return {rit.first, max(rit.second, lft.first)};
    }
}

int main() {

    //freopen("meciul.in", "r", stdin);
    //freopen("meciul.out", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%lld", arr + i);

    build();

    scanf("%d", &m);
    while (m--) {
        char op;
        long long x, y;
        scanf(" %c%lld%lld", &op, &x, &y);
        if (op == 'U') {
            update(x - 1, y);
        } else {
            pair<long long, long long> ans = query(x - 1, y - 1);
            printf("%lld\n", ans.first + ans.second);
        }
    }

    return 0;
}