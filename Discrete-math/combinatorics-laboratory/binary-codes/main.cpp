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
vector <int> decompose(int x) {
    vector <int> ans;
    for (int i = 0; i < n; i++) {
        ans.pb(x % 2);
        x /= 2;
    }
    reverse(all(ans));
    re ans;
}
int main() {
    freopen("allvectors.in", "r", stdin);
    freopen("allvectors.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < (1 << n); i++) {
        vector <int> v = decompose(i);
        for (int j : v) {
            cout << j;
        }
        cout << "\n";
    }
}
