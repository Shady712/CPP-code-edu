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

string s;
string cycle(int id) {
    string t = s.substr(id);
    for (int i = 0; i < id; i++) {
        t += s[i];
    }
    return t;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> s;
    vector <string> v(sz(s));
    for (int i = 0; i < sz(s); i++) {
        v[i] = cycle(i);
    }
    sort(all(v));
    for (int i = 0; i < sz(s); i++) {
        cout << v[i][sz(s) - 1];
    }
}
