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


int n;
int a[100];
bool was[100];
ll fact(int x) {
    ll ans = 1;
    for (ll i = 2; i <= x; i++) {
        ans *= i;
    }
    return ans;
}
void solve() {
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll t = fact(n - i - 1);
        for (int j = 1; j < a[i]; j++) {
            if (!was[j]) {
                ans += t;
            }
        }
        was[a[i]] = true;
    }
    cout << ans;
}
int main() {
    freopen("perm2num.in", "r", stdin);
    freopen("perm2num.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    solve();
}
