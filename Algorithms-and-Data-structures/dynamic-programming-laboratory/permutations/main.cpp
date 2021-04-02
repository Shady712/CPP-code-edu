#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <cstdlib>
#include <queue>
#include <stack>
#include <cstring>
#include <ctime>
#include <cassert>

#define pb emplace_back
#define pf emplace_front
#define re return
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()

using namespace std;
using namespace __gnu_cxx;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <long long> vll;
typedef long double LD;

const ll MOD = 1e9 + 7;
const double pi = 3.14159265359;

ll n, m, k;
ll a[20], dp[100000][20];
void reboot(ll newN) {
    vector <ll> divs[20];
    memset(dp, 0, sizeof(dp));
    sort(a, a + newN);
    for (int i = 0; i < newN; i++) {
        dp[1 << i][i] = 1;
        for (int j = i + 1; j < newN; j++) {
            if (k <= __gcd(a[i], a[j])) {
                divs[i].pb(j);
                divs[j].pb(i);
            }
        }
    }
    for (int mask = 1; mask < (1 << newN); mask++) {
        for (int i = 0; i < newN; i++) {
            for (ll j : divs[i]) {
                if ((mask & (1 << j)) == 0) {
                    dp[(1 << j) ^ mask][j] = dp[(1 << j) ^ mask][j] + dp[mask][i];
                }
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m >> k;
    ll N = n - 1;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    reboot(n);
    ll p = 0;
    bool check = true;
    while (check) {
        if (n == 0) {
            break;
        }
        check = false;
        for (ll i = 0; i < n; i++) {
            if (k <= __gcd(p, a[i]) || p == 0) {
                if (m > dp[(1 << n) - 1][i]) {
                    m -= dp[(1 << n) - 1][i];
                } else {
                    p = a[i];
                    swap(a[i], a[n - 1]);
                    n--;
                    reboot(n);
                    check = true;
                    break;
                }
            }
        }
    }
    if (n > 0) {
        cout << -1;
        return 0;
    }
    for (ll i = N; i >= 0; i--) {
        cout << a[i] << " ";
    }
}
