#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10, M = 1e6 + 10;

int n, m, arr[N], qs[N], qe[N], qi[N], sq, st, en, freq[M];
long long qAns[N], ans;

void add(int val) {
    ans -= 1ll * val * freq[val] * freq[val];
    ++freq[val];
    ans += 1ll * val * freq[val] * freq[val];
}

void del(int val) {
    ans -= 1ll * val * freq[val] * freq[val];
    --freq[val];
    ans += 1ll * val * freq[val] * freq[val];
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

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf("%d", arr + i);

    for (int i = 0; i < m; ++i) {
        scanf("%d%d", qs + i, qe + i);
        --qs[i], --qe[i];
        qi[i] = i;
    }

    sq = sqrtl((n * 1ll * n) / m) + 10;
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