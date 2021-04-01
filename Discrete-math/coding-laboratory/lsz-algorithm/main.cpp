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

string s, t = "";
map <string, int> voc;
int code = 26;
void solve(int id) {
    if (sz(t) == 0 || voc[t + s[id]] != 0) {
        t += s[id];
    } else {
        cout << voc[t] << " ";
        voc[t + s[id]] = code++;
        t = s[id];
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> s;
    for (char i = 'a'; i <= 'z'; i++) {
        string cur;
        cur += i;
        voc[cur] = i - 'a';
    }
    for (int i = 0; i < sz(s); i++) {
        solve(i);
    }
    cout << voc[t];
}
