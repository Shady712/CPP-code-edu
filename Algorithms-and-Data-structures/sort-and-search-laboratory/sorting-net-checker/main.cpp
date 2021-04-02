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

int n, m, k;
vector < pair <int, int> > v[150];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        int r;
        cin >> r;
        for (int j = 0; j < r; j++) {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            if (x > y) {
                swap(x, y);
            }
            v[i].pb(x, y);
        }
    }
    for (int X = 0; X < (1 << n); X++) {
        int tmp = X;
        int* a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = tmp % 2;
            tmp /= 2;
        }
        for (int i = 0; i < k; i++) {
            for (pair <int, int> t : v[i]) {
                if (a[t.fi] > a[t.se]) {
                    swap(a[t.fi], a[t.se]);
                }
            }
        }
        for (int i = 1; i < n; i++) {
            if (a[i] < a[i - 1]) {
                cout << "No";
                re 0;
            }
        }
    }
    cout << "Yes";
}
