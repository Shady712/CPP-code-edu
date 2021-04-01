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
void bracket(string s, int b) {
    if (sz(s) == n * 2) {
        if (!b) {
            cout << s << "\n";
        }
        return;
    }
    if (!b) {
        bracket(s + '(', 1);
    } else {
        bracket(s + '(', b + 1);
        bracket(s + ')', b - 1);
    }
}
int main() {
    freopen("brackets.in", "r", stdin);
    freopen("brackets.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    bracket("", 0);
}
