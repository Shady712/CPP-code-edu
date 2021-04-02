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

const ll MOD = 1e18;
const double pi = 3.14159265359;

int n, m;
ll dp[1000000][20];
vector <pair <int, ll> > paths[20];
void preparation() {
    for (auto& i : dp) {
        for (ll& j : i) {
            j = MOD;
        }
    }
    int j = 0;
    for (int i = 1; i < (1 << n); i *= 2) {
        dp[i][j++] = 0;
    }
}
void update(ll& x, ll y) {
    x = min(x, y);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        ll w;
        cin >> x >> y >> w;
        x--;
        y--;
        paths[x].pb(y, w);
        paths[y].pb(x, w);
    }
    preparation();
    int mask = 0;
    for ( ; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (((1 << i) & mask) == 0) {
                continue;
            }
            for (pair <int, int> j : paths[i]) {
                ll length = dp[mask][i] + j.second;
                if (((1 << j.first) & mask) == 0) {
                    update(dp[(1 << j.first) ^ mask][j.first], length);
                }
            }
        }
    }
    mask--;
    ll ans = -1;
    for (int i = 0; i < n; i++) {
        if (dp[mask][i] == MOD) {
            continue;
        }
        if (ans == -1) {
            ans = dp[mask][i];
        } else {
            ans = min(ans, dp[mask][i]);
        }
    }
    cout << ans;
}
