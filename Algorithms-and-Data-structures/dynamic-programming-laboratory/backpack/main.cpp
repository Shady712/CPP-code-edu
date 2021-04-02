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

int n, mass;
int m[1000], c[1000];
int dp[1050][10050];
vector <int> ans;
void getAns(int i, int j) {
    if (dp[i][j] == 0) {
        return;
    }
    if (dp[i - 1][j] == dp[i][j]) {
        getAns(i - 1, j);
    } else {
        getAns(i - 1, j - m[i - 1]);
        ans.pb(i);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> mass;
    for (int i = 0; i < n; i++) {
        cin >> m[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    for (int i = 0; i <= mass; i++) {
        dp[0][i]=  0;
    }
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= mass; j++) {
            if (j >= m[i - 1]) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - m[i - 1]] + c[i - 1]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    getAns(n, mass);
    cout << sz(ans) << "\n";
    for (int i : ans) {
        cout << i << " ";
    }
}
