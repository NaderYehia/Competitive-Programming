#include <bits/stdc++.h>

using namespace std;

const int N = (1 << 17) + 10, M = 4 * N + 10;

int n, m;
int arr[N], lg[N];
int tree[M];


void build(int si = 0, int ss = 0, int se = n - 1) {
    if (ss == se) {
        tree[si] = arr[ss];
        return;
    }
    int md = ss + (se - ss) / 2, lf = si * 2 + 1, rt = si * 2 + 2;
    build(lf, ss, md);
    build(rt, md + 1, se);
    tree[si] = (lg[se - ss + 1] & 1) ? (tree[lf] | tree[rt]) : (tree[lf] ^ tree[rt]);
}

void update(int qi, int qv, int si = 0, int ss = 0, int se = n - 1) {
    if (ss > qi || se < qi) return;
    if (ss == se) {
        tree[si] = arr[ss] = qv;
        return;
    }
    int md = ss + (se - ss) / 2, lf = si * 2 + 1, rt = si * 2 + 2;
    update(qi, qv, lf, ss, md);
    update(qi, qv, rt, md + 1, se);
    tree[si] = (lg[se - ss + 1] & 1) ? (tree[lf] | tree[rt]) : (tree[lf] ^ tree[rt]);
}

int main() {

    //freopen("meciul.in", "r", stdin);
    //freopen("meciul.out", "w", stdout);

    scanf("%d%d", &n, &m);
    n = (1 << n);
    lg[0] = -1;
    for (int i = 0; i < n; ++i) {
        scanf("%d", arr + i);
        lg[i + 1] = lg[i] + !(i & (i + 1));
    }

    build();

    for (int i = 0; i < m; ++i) {
        int idx, v;
        scanf("%d%d", &idx, &v);
        update(idx - 1, v);
        printf("%d\n", tree[0]);
    }

    return 0;
}