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
int a[300000];
int dp[300000];
int pos[300000];
int p[300000];
int findId(int x) {
    int l = 0, r = n - 1;
    int ans = r;
    while (l <= r) {
        int c = (l + r) / 2;
        if (dp[c] >= x) {
            ans = c;
            r = c - 1;
        } else {
            l = c + 1;
        }
    }
    return ans;
}
bool kek() {
    for (int i = 1; i < n; i++) {
        if (a[i] <= a[i - 1]) {
            return false;
        }
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int szAns = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (kek()) {
        cout << n << "\n";
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        return 0;
    }
    pos[0] = -1;
    dp[0] = -MOD;
    for (int i = 1; i < n; i++) {
        dp[i] = MOD;
    }
    for (int i = 0; i < n; i++) {
        int j = findId(a[i]);
        if (dp[j - 1] < a[i] && a[i] < dp[j]) {
            dp[j] = a[i];
            pos[j] = i;
            p[i] = pos[j - 1];
            szAns = max(szAns, j);
        }
    }
    vector <int> ans;
    int id = pos[szAns];
    while (id != -1) {
        ans.pb(a[id]);
        id = p[id];
    }
    reverse(all(ans));
    cout << sz(ans) << "\n";
    for (int i : ans) {
        cout << i << " ";
    }
}
