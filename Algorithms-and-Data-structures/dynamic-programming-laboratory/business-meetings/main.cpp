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

int n, k;
int a[20], b[20], c[20];
int dp[3000000];
int getIndex(int x) {
    int ans = -1;
    while (x > 0) {
        ans++;
        x /= 2;
    }
    return ans;
}
bool kek() {
    for (int i = 0; i < n; i++) {
        if (a[i] <= k && k <= b[i]) {
            return false;
        }
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    if (kek()) {
        cout << 0;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        if (a[i] <= k && k <= b[i]) {
            dp[(1 << i)] = MOD;
        }
    }
    int sum = 0, ansMask = MOD;
    for (int mask = 1; mask < (1 << n); mask++) {
        if (dp[mask] != 0) {
            if (__builtin_popcount(mask) > sum) {
                sum = __builtin_popcount(mask);
                ansMask = mask;
            }
            int t = k;
            for (int i = 1; i < (1 << n); i *= 2) {
                if (i & mask) {
                    t += c[getIndex(i)];
                }
            }
            for (int i = 1; i < (1 << n); i *= 2) {
                int id = getIndex(i);
                if ((mask & i) == 0 && a[id] <= t && t <= b[id]) {
                    dp[mask ^ i] = mask;
                }
            }
        }
    }
    vector <int> ans;
    while (dp[ansMask] != MOD) {
        int tmp = ansMask ^ dp[ansMask];
        for (int i = 1; i < (1 << n); i *= 2) {
            if (i & tmp) {
                ans.pb(getIndex(i) + 1);
                ansMask = dp[ansMask];
                break;
            }
        }
    }
    for (int i = 1; i < (1 << n); i *= 2) {
        if (i & ansMask) {
            ans.pb(getIndex(i) + 1);
            break;
        }
    }
    reverse(all(ans));
    cout << sz(ans) << "\n";
    for (int i : ans) {
        cout << i << " ";
    }
}
