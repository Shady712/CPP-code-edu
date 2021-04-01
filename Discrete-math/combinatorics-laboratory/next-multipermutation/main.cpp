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
int main() {
    freopen("nextmultiperm.in", "r", stdin);
    freopen("nextmultiperm.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    vector <int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int id = -1;
    for (int i = n - 1; i >= 1; i--) {
        if (v[i] > v[i - 1]) {
            id = i;
            break;
        }
    }
    if (id == -1) {
        for (int i = 0; i < n; i++) {
            cout << 0 << " ";
        }
    } else {
        int t = id;
        for (int i = id; i < n; i++) {
            if (v[i] > v[id - 1]) {
                t = i;
            }
        }
        swap(v[t], v[id - 1]);
        for (int i = 0; i < id; i++) {
            cout << v[i] << " ";
        }
        for (int i = n - 1; i >= id; i--) {
            cout << v[i] << " ";
        }
    }
}
