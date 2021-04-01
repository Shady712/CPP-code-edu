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
bool kek(vector <int> v) {
    for (int i = 1; i < k; i++) {
        if (v[i] != v[i - 1] + 1) {
            return false;
        }
    }
    return v[k - 1] == n;
}
int main() {
    freopen("nextchoose.in", "r", stdin);
    freopen("nextchoose.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    vector <int> v(k);
    for (int i = 0; i < k; i++) {
        cin >> v[i];
    }
    if (kek(v)) {
        cout << -1;
    } else {
        int id;
        for (int i = k - 1; i >= 0; i--) {
            if (v[i] != n - (k - i) + 1) {
                v[i]++;
                id = i;
                break;
            }
        }
        for (int i = id + 1; i < k; i++) {
            v[i] = v[i - 1] + 1;
        }
        for (int i : v) {
            cout << i << " ";
        }
    }
}
