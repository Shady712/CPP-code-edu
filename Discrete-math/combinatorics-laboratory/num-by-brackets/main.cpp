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


ll n;
ll cnt[100][100];
string s;
void solve() {
    ll ans = 0;
    ll bal = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (s[i] == '(') {
            bal++;
        } else {
            bal--;
            if (bal + 1 < n) {
                ans += cnt[2 * n - i - 1][bal + 2];
            }
        }
    }
    cout << ans;
}
int main() {
    freopen("brackets2num.in", "r", stdin);
    freopen("brackets2num.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> s;
    n = sz(s) / 2;
    cnt[0][0] = 1;
    for (int i = 0; i < 2 * n; i++) {
        for (int j = 0; j <= n; j++) {
            cnt[i + 1][j] += cnt[i][j + 1];
            if (j < n) {
                cnt[i + 1][j + 1] = cnt[i][j];
            }
        }
    }
    solve();
}
