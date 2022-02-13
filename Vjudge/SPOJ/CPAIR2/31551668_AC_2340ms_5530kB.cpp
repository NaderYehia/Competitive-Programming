#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 10, M = 1e5 + 10, inf = 0x3f3f3f3f;

int n, m, k, arr[N], qs[N], qe[N], qi[N], sq, st, en, tree[M];
long long ans, qAns[N];

void update(int i, int val) {
    for (; i < M; i += i & -i)
        tree[i] += val;
}

int get(int i) {
    //assert(i <= 100000);
    if (i > 100000) i = 100000;
    int ret = 0;
    for (; i > 0; i -= i & -i)
        ret += tree[i];
    return ret;
}

void add(int val) {
    ans += get(val - k);
    ans += get(100000) - get(val + k - 1);
    update(val, 1);
}

void del(int val) {
    update(val, -1);
    ans -= get(val - k);
    ans -= get(100000) - get(val + k - 1);
}

void updateSE(int idx) {
    while (en < qe[idx] + 1) add(arr[en++]);
    while (en > qe[idx] + 1) del(arr[--en]);
    while (st < qs[idx]) del(arr[st++]);
    while (st > qs[idx]) add(arr[--st]);
}

int main() {

    //freopen("meciul.in", "r", stdin);
    //freopen("meciul.out", "w", stdout);

    scanf("%d%d%d", &n, &m, &k);
    assert(k > 0);
    for (int i = 0; i < n; ++i)
        scanf("%d", arr + i);

    for (int i = 0; i < m; ++i) {
        scanf("%d%d", qs + i, qe + i);
        --qs[i], --qe[i];
        assert(qs[i] <= qe[i]);
        qi[i] = i;
    }

    sq = sqrt(n);
    sort(qi, qi + m, [](int i, int j) {
        return make_pair(qs[i] / sq, qe[i]) < make_pair(qs[j] / sq, qe[j]);
    });

    for (int i = 0; i < m; ++i) {
        updateSE(qi[i]);
        qAns[qi[i]] = ans;
    }

    for (int i = 0; i < m; ++i)
        printf("%lld\n", qAns[i]);

    return 0;
}