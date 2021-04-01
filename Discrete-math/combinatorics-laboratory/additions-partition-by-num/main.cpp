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
ll cnt[200][200];
vector <ll> ans;
void additive(vector <int> v, int sum, int last) {
    if (!sum) {
        for (int i = 0; i < sz(v) - 1; i++) {
            cout << v[i] << "+";
        }
        cout << v[sz(v) - 1];
        return;
    }
    if (k < cnt[sum][last]) {
        v.pb(last);
        additive(v, sum - last, last);
    } else {
        k -= cnt[sum][last];
        additive(v, sum, ++last);
    }
}
int main() {
    freopen("num2part.in", "r", stdin);
    freopen("num2part.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cnt[i][i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j) {
                for (int k = j; k <= i; k++) {
                    cnt[i][j] += cnt[i - j][k];
                }
            }
        }
    }
    vector <int> v;
    additive(v, n, 1);
}
