#include <iostream>
#include <set>
#include <vector>
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
pair <string, bool> a[2000];
bool dominate(string s, string t) {
    for (int i = 0; i < sz(s); i++) {
        if (s[i] < t[i]) {
            re false;
        }
    }
    re true;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < (1 << n); i++) {
        cin >> a[i].fi >> a[i].se;
    }
    for (int i = 0; i < (1 << n); i++) {
        bool ans = false;
        for (int j = 0; j < (1 << n); j++) {
            if (dominate(a[i].fi, a[j].fi)) {
                ans ^= a[j].se;
            }
        }
        cout << a[i].fi << " " << ans << "\n";
    }
}
