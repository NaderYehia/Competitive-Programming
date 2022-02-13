#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int n, m, arr[N], vec[N], sz, sq, qs[N], qe[N], qi[N], st, en, id, freq[N];
long long ans, qAns[N];


struct DS {
    int first[N], last[N];

    void init() {
        memset(first, 0, sizeof first);
        memset(last, -1, sizeof last);
    }

    void push_back(int f, int id) {
        if (first[f] > last[f]) first[f] = last[f] = id;
        else ++last[f];
        assert(last[f] == id);
    }

    void push_front(int f, int id) {
        if (first[f] > last[f]) first[f] = last[f] = id;
        else --first[f];
        assert(first[f] == id);
    }

    void pop_back(int f) {
        --last[f];
    }

    void pop_front(int f) {
        ++first[f];
    }
} ds;

void compress() {
    sort(vec, vec + sz);
    sz = unique(vec, vec + sz) - vec;

    for (int i = 0; i < n; ++i)
        arr[i] = lower_bound(vec, vec + sz, arr[i]) - vec;
}

void add(int val) {
    if (freq[val] == 0) {
        ans += id;
        ++freq[val];
        ds.push_back(1, id++);
    } else {
        int small = ds.first[freq[val]];
        ds.pop_front(freq[val]);
        ++freq[val];
        ds.push_back(freq[val], small);
        ans += small;
    }
}

void del(int val) {
    if (freq[val] == 1) {
        ds.pop_back(freq[val]--);
        ans -= --id;
    } else {
        int big = ds.last[freq[val]];
        ds.pop_back(freq[val]);
        --freq[val];
        ds.push_front(freq[val], big);
        ans -= big;
    }
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

    ds.init();

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf("%d", arr + i), vec[sz++] = arr[i];

    compress();

    for (int i = 0; i < m; ++i) {
        scanf("%d%d", qs + i, qe + i);
        --qs[i], --qe[i];
        qi[i] = i;
    }

    sq = sqrtl((n * 1ll * n) / m);
    sort(qi, qi + m, [](int i, int j) {
        return make_pair(qs[i] / sq, qe[i]) < make_pair(qs[j] / sq, qe[j]);
    });

    id = 1;
    for (int i = 0; i < m; ++i) {
        updateSE(qi[i]);
        qAns[qi[i]] = ans;
    }

    for (int i = 0; i < m; ++i)
        printf("%lld\n", qAns[i]);

    return 0;
}