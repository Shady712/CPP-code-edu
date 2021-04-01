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
string s;
string bwt[1000], tmp[1000];
void solve() {
    sort(tmp, tmp + n);
    for (int i = 0; i < n; i++) {
        bwt[i] += tmp[i][sz(tmp[i]) - 1];
        tmp[i] = bwt[i][0] + tmp[i];
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> s;
    n = s.size();
    for (int i = 0; i < n; i++) {
        bwt[i] = tmp[i] = s[i];
    }
    for (int i = 0; i < n - 1; i++) {
        solve();
    }
    string ans = bwt[0];
    for (int i = 1; i < n; i++) {
        ans = min(ans, bwt[i]);
    }
    cout << ans;
}
