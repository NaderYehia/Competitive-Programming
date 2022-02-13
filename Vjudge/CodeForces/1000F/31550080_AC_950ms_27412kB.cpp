#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10, M = 2e6 + 10, inf = 0x3f3f3f3f;

int n, m, arr[N], qs[N], qe[N], qi[N], qAns[N], prv[N];
pair<int, int> tree[4 * N];

void update(int qi, int qv, int si = 0, int ss = 0, int se = n - 1) {
    if (ss > qi || se < qi) return;
    if (ss == se) {
        tree[si] = {qv, ss};
        return;
    }
    int md = ss + (se - ss) / 2, lf = si * 2 + 1, rt = si * 2 + 2;
    update(qi, qv, lf, ss, md);
    update(qi, qv, rt, md + 1, se);
    tree[si] = min(tree[lf], tree[rt]);
}

pair<int, int> query(int qs, int qe, int si = 0, int ss = 0, int se = n - 1) {
    if (ss > qe || se < qs) return {inf, inf};
    if (ss >= qs && se <= qe) return tree[si];
    int md = ss + (se - ss) / 2, lf = si * 2 + 1, rt = si * 2 + 2;
    return min(query(qs, qe, lf, ss, md), query(qs, qe, rt, md + 1, se));
}


int main() {

    //freopen("meciul.in", "r", stdin);
    //freopen("meciul.out", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", arr + i);

    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", qs + i, qe + i);
        --qs[i], --qe[i];
        qi[i] = i;
    }

    sort(qi, qi + m, [](int i, int j) {
        return qe[i] < qe[j];
    });

    memset(prv, -1, sizeof prv);
    int idx = 0;
    for (int i = 0; i < m; ++i) {
        while (idx <= qe[qi[i]]) {
            update(prv[arr[idx]], inf);
            update(idx, prv[arr[idx]]);
            prv[arr[idx]] = idx;
            idx++;
        }
        pair<int, int> cur = query(qs[qi[i]], qe[qi[i]]);
        if (cur.first < qs[qi[i]]) {
            qAns[qi[i]] = arr[cur.second];
        } else {
            qAns[qi[i]] = 0;
        }
    }

    for (int i = 0; i < m; ++i)
        printf("%d\n", qAns[i]);

    return 0;
}