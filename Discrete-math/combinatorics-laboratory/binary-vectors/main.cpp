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
vector <bool> code[1000000];
vector <bool> kek(int x) {
    vector <bool> ans;
    while (x) {
        ans.pb(x % 2);
        x /= 2;
    }
    while (sz(ans) < n) {
        ans.pb(0);
    }
    reverse(all(ans));
    re ans;
}
bool check(int id) {
    for (int i = 1; i < n; i++) {
        if (code[id][i] && code[id][i - 1]) {
            re false;
        }
    }
    re true;
}
int main() {
    freopen("vectors.in", "r", stdin);
    freopen("vectors.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < (1 << n); i++) {
        code[i] = kek(i);
    }
    vector < vector <bool> > ans;
    for (int i = 0; i < (1 << n); i++) {
        if (check(i)) {
            ans.pb(code[i]);
        }
    }
    cout << sz(ans) << "\n";
    for (int i = 0; i < sz(ans); i++) {
        for (bool j : ans[i]) {
            cout << j;
        }
        cout << "\n";
    }
}
