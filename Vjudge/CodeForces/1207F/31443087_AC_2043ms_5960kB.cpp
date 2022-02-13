#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10, M = 1e3 + 10;

int arr[N];
int dp[M][M];

int main() {

    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int q;
    scanf("%d", &q);
    while (q--) {
        int t, x, y;
        scanf("%d%d%d", &t, &x, &y);
        if (t == 1) {
            arr[x] += y;
            for (int i = 1; i <= 1000; ++i) {
                dp[i][x % i] += y;
            }
        } else {
            if (x > 1000) {
                int ans = 0;
                for (int i = y; i < N; i += x)
                    ans += arr[i];
                printf("%d\n", ans);
            } else {
                printf("%d\n", dp[x][y]);
            }
        }
    }

    return 0;
}
