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


ll n, k, m;
ll C[100][100];
void solve() {
    ll next = 1;
    vector <ll> ans;
    while (k) {
        if (m < C[n - 1][k - 1]) {
            ans.pb(next);
            k--;
        } else {
            m -= C[n - 1][k - 1];
        }
        n--;
        next++;
    }
    for (ll i : ans) {
        cout << i << " ";
    }
}
int main() {
    freopen("num2choose.in", "r", stdin);
    freopen("num2choose.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k >> m;
    for (int i = 0; i < 100; i++) {
        C[i][0] = 1;
    }
    for (int i = 1; i < 40; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        }
    }
    solve();
}
