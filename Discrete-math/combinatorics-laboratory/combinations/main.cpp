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
void choose(vector <int> v, int t) {
    if (sz(v) == k) {
        for (int i : v) {
            cout << i << " ";
        }
        cout << "\n";
        return;
    }
    for (int next = t + 1; next <= n - (k - sz(v)) + 1; next++) {
        v.pb(next);
        choose(v, next);
        v.pop_back();
    }
}
int main() {
    freopen("choose.in", "r", stdin);
    freopen("choose.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    vector <int> v;
    choose(v, 0);
}
