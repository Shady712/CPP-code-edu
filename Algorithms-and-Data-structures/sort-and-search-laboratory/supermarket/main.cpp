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

ll n, m, p;
pair <ll, ll> a[100050];

bool check(ll aim) {
    for (int i = 0; i < m; i++) {
        if (a[i].fi * p + a[i].se <= aim) {
            re true;
        }
    }
    ll tmp[100050];
    memset(tmp, 0, sizeof(tmp));
    for (int i = 0; i < m; i++) {
        if (!a[i].fi) {
            continue;
        }
        if (aim - a[i].se < 0) {
            continue;
        }
        if ((aim - a[i].se) / a[i].fi >= p) {
            re true;
        }
        tmp[(aim - a[i].se) / a[i].fi]++;
    }
    ll guys = n, buys = p, ans = 0;
    while (true) {
        buys--;
        if (!buys || !guys) {
            re ans >= p;
        }
        while (guys && tmp[buys]) {
            guys--;
            tmp[buys]--;
            ans += buys;
            if (ans >= p) {
                re true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        a[i].fi = x;
        a[i].se = y + z;
    }
    cin >> n >> p;
    if (!p) {
        cout << 0;
        re 0;
    }
    ll l = 0, r = 1e18, ans = r;
    while (l <= r) {
        ll c = (l + r) / 2;
        if (check(c)) {
            ans = c;
            r = c - 1;
        } else {
            l = c + 1;
        }
    }
    cout << ans;
}
