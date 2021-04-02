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
pair <ll, ll> a[400];
ll dp[400][400];
string ans[400][400];
ll getAns(int i, int j, int k) {
    return a[j].fi * a[k].se * a[i + j].se + dp[j][k] + dp[k + 1][i + j];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].fi >> a[i].se;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                dp[i][j] = 1e18;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        ans[i][i] = "A";
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            for (int k = j; k < i + j; k++) {
                dp[j][i + j] = min(dp[j][i + j], getAns(i, j, k));
                if (dp[j][i + j] == getAns(i, j, k)) {
                    ans[j][i + j] = '(' + ans[j][k] + ans[k + 1][i + j] + ')';
                }
            }
        }
    }
    cout << ans[0][n - 1];
}
