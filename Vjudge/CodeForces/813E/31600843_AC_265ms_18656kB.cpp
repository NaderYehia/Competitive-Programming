#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n, m, k, arr[N], nxt[N], ptr[N], cnt[N], kthPrv[N];
vector<int> tree[4 * N];

void build(int si = 0, int ss = 0, int se = n - 1) {
    if (ss == se) {
        tree[si] = {kthPrv[ss]};
        return;
    }
    int md = ss + (se - ss) / 2, lf = si * 2 + 1, rt = si * 2 + 2;
    build(lf, ss, md);
    build(rt, md + 1, se);
    merge(tree[lf].begin(), tree[lf].end(), tree[rt].begin(), tree[rt].end(), inserter(tree[si], tree[si].begin()));
}

int query(int qs, int qe, int si = 0, int ss = 0, int se = n - 1) {
    if (ss > qe || se < qs) return 0;
    if (ss >= qs && se <= qe) return lower_bound(tree[si].begin(), tree[si].end(), qs) - tree[si].begin();
    int md = ss + (se - ss) / 2, lf = si * 2 + 1, rt = si * 2 + 2;
    return query(qs, qe, lf, ss, md) + query(qs, qe, rt, md + 1, se);
}

int main() {

    //freopen("meciul.in", "r", stdin);
    //freopen("meciul.out", "w", stdout);

    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i)
        scanf("%d", arr + i);

    memset(ptr, -1, sizeof ptr);
    for (int i = n - 1; ~i; --i) {
        nxt[i] = ptr[arr[i]];
        ptr[arr[i]] = i;
    }

    memset(kthPrv, -1, sizeof kthPrv);
    for (int i = 0; i < n; ++i) {
        if (++cnt[arr[i]] > k) {
            kthPrv[i] = ptr[arr[i]];
            ptr[arr[i]] = nxt[ptr[arr[i]]];
        }
    }

    build();

    scanf("%d", &m);
    int last = 0;
    while (m--) {
        int st, en;
        scanf("%d%d", &st, &en);
        st = (st + last) % n + 1;
        en = (en + last) % n + 1;
        if (st > en) swap(st, en);
        --st, --en;
        printf("%d\n", last = query(st, en));
    }

    return 0;
}