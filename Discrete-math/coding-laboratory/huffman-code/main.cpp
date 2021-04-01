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
ll a[1000];
string code[1000];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    set < pair <ll, vector <int> > > freq;
    for (int i = 0; i < n; i++) {
        freq.insert({a[i], {i}});
    }
    while (sz(freq) != 1) {
        auto t = *freq.begin();
        freq.erase(freq.begin());
        auto p = *freq.begin();
        freq.erase(freq.begin());
        vector <int> v;
        for (int i : t.se) {
            code[i] += '0';
            v.pb(i);
        }
        for (int i : p.se) {
            code[i] += '1';
            v.pb(i);
        }
        pair <ll, vector <int> > ans;
        ans.fi = t.fi + p.fi;
        ans.se = v;
        freq.insert(ans);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += sz(code[i]) * a[i];
    }
    cout << ans;
}
