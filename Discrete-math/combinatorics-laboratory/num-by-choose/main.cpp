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


ll n, k;
ll a[100];
ll C[100][100];
void solve() {
    ll ans = 0;
    for (ll i = 1; i <= k; i++) {
        for (ll j = a[i - 1] + 1; j < a[i]; j++) {
            ans += C[n - j][k - i];
        }
    }
    cout << ans;
}
int main() {
    freopen("choose2num.in", "r", stdin);
    freopen("choose2num.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    a[0] = 0;
    for (int i = 1; i <= k; i++) {
        cin >> a[i];
    }
    C[1][0] = C[1][1] = 1;
    for (int i = 2; i < n + 10; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        }
    }
    solve();
}
