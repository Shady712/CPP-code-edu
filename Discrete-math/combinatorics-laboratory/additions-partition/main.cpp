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
void additive(vector <int> v, int sum, int last) {
    if (sum >= n) {
        if (sum == n) {
            for (int i = 0; i < sz(v) - 1; i++) {
                cout << v[i] << "+";
            }
            cout << v[sz(v) - 1] << "\n";
        }
        return;
    }
    for (int next = last; next <= n - sum; next++) {
        v.pb(next);
        additive(v, sum + next, next);
        v.pop_back();
    }
}
int main() {
    freopen("partition.in", "r", stdin);
    freopen("partition.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    vector <int> v;
    additive(v, 0, 1);
}
