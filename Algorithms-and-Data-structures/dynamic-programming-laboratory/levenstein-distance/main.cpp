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

string a, b;
ll dp[5050][5050];
int cnt(int i, int j) {
    return a[i] != b[j];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> a >> b;
    for (int i = 1; i <= sz(a); i++) {
        dp[i][0] = i;
    }
    for (int i = 1; i <= sz(b); i++) {
        dp[0][i] = i;
    }
    for (int i = 1; i <= sz(a); i++) {
        for (int j = 1; j <= sz(b); j++) {
            dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + 1;
            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + cnt(i - 1, j - 1));
        }
    }
    cout << dp[sz(a)][sz(b)];
}
