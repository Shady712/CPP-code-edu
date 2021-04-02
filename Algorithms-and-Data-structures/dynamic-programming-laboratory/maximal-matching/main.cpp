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
bool was[100000];
ll a[100000];
ll b[100000];
ll c[100000];
vector <pair <int, ll> > paths[100000];
vector <pair <int, ll> > children[100000];
void findChildren(int apex) {
    was[apex] = true;
    for (pair <int, int> t : paths[apex]) {
        if (!was[t.first]) {
            children[apex].pb(t);
            findChildren(t.first);
        }
    }
}
void matching(int apex) {
    for (pair <int, ll> t : children[apex]) {
        matching(t.first);
        a[apex] = max(a[apex], b[t.first] + t.second - c[t.first]);
        b[apex] += c[t.first];
    }
    a[apex] += b[apex];
    c[apex] = max(a[apex], b[apex]);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        ll w;
        cin >> x >> y >> w;
        x--;
        y--;
        paths[x].pb(y, w);
        paths[y].pb(x, w);
    }
    findChildren(0);
    matching(0);
    cout << c[0];
}
