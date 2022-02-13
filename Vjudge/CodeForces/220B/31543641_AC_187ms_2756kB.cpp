#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10, M = 1e6 + 10;

int n, m, arr[N], qs[N], qe[N], qi[N], qAns[N], sq, st, en, ans, freq[N], vec[N], sz;

void compress() {
    sort(vec, vec + sz);
    sz = unique(vec, vec + sz) - vec;
    for (int i = 0; i < n; ++i)
        arr[i] = lower_bound(vec, vec + sz, arr[i]) - vec;
}

void add(int val) {
    if (freq[val] == vec[val]) --ans, ++freq[val];
    else ans += (++freq[val] == vec[val]);
}

void del(int val) {
    if (freq[val] == vec[val]) --ans, --freq[val];
    else ans += (--freq[val] == vec[val]);
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
        scanf("%d", arr + i), vec[sz++] = arr[i];

    compress();

    for (int i = 0; i < m; ++i) {
        scanf("%d%d", qs + i, qe + i);
        --qs[i], --qe[i];
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
        printf("%d\n", qAns[i]);

    return 0;
}