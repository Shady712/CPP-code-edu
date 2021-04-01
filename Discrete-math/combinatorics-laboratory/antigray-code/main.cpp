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
        ans.pb(x % 3);
        x /= 3;
    }
    reverse(all(ans));
    re ans;
}
int main() {
    freopen("antigray.in", "r", stdin);
    freopen("antigray.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    int st = 1;
    for (int i = 0; i < n; i++) {
        st *= 3;
    }
    for (int i = 0; i < st / 3; i++) {
        vector <int> v = decompose(i);
        for (int j = 0; j < 3; j++) {
            for (int k : v) {
                cout << k;
            }
            cout << "\n";
            for (int &k : v) {
                k++;
                k %= 3;
            }
        }
    }
}
