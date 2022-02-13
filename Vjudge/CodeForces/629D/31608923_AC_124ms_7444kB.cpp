#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
long double vol[N], vec[N];
int n, sz, arr[N];

void compress() {
    sort(vec, vec + sz);
    sz = unique(vec, vec + sz) - vec;
    for (int i = 0; i < n; ++i)
        arr[i] = lower_bound(vec, vec + sz, vol[i]) - vec;
}

long double tree[4 * N];

void update(int qi, long double qv, int si = 0, int ss = 0, int se = n - 1) {
    if (ss > qi || se < qi) return;
    if (ss == se) {
        tree[si] = max(tree[si], qv);
        return;
    }
    int md = ss + (se - ss) / 2, lf = si * 2 + 1, rt = si * 2 + 2;
    update(qi, qv, lf, ss, md);
    update(qi, qv, rt, md + 1, se);
    tree[si] = max(tree[lf], tree[rt]);
}

long double query(int qs, int qe, int si = 0, int ss = 0, int se = n - 1) {
    if (ss > qe || se < qs) return 0;
    if (ss >= qs && se <= qe) return tree[si];
    int md = ss + (se - ss) / 2, lf = si * 2 + 1, rt = si * 2 + 2;
    return max(query(qs, qe, lf, ss, md), query(qs, qe, rt, md + 1, se));
}

int main() {

    //freopen("meciul.in", "r", stdin);
    //freopen("meciul.out", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int r, h;
        scanf("%d%d", &r, &h);
        vol[i] = 1ll * r * r * h * acos(-1);
        vec[sz++] = vol[i];
    }

    compress();


    long double best = 0;
    for (int i = 0; i < n; ++i) {
        long double cur = query(0, arr[i] - 1);
        best = max(best, cur + vol[i]);
        update(arr[i], cur + vol[i]);
    }
    cout << fixed << setprecision(6) << best << endl;

    return 0;
}