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
bool was[100];
ll fact(ll x) {
    ll ans = 1;
    for (ll i = 2; i <= x; i++) {
        ans *= i;
    }
    return ans;
}
void solve() {
    vector <int> ans;
    for (int i = 0; i < n; i++) {
        ll factorial = fact(n - i - 1);
        ll alreadyWas = k / factorial;
        k %= factorial;
        ll curFree = 0;
        for (int j = 1; j <= n; j++) {
            if (!was[j]) {
                curFree++;
                if (curFree == alreadyWas + 1) {
                    ans.pb(j);
                    was[j] = true;
                }
            }
        }
    }
    for (int i : ans) {
        cout << i << " ";
    }
}
int main() {
    freopen("num2perm.in", "r", stdin);
    freopen("num2perm.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    solve();
}
