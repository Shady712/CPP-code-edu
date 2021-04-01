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
int n;
vector <int> input;
int parse(int& i) {
    int ans = 0;
    while ('0' <= s[i] && s[i] <= '9') {
        ans = ans * 10 + (s[i] - '0');
        i++;
    }
    return ans;
}
void parse() {
    for (int i = 0; i < sz(s); i++) {
        input.pb(parse(i));
    }
}
int main() {
    freopen("nextpartition.in", "r", stdin);
    freopen("nextpartition.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> s;
    parse();
    if (sz(input) == 2) {
        cout << "No solution";
    } else {
        n = input[0];
        vector <int> v;
        for (int i = 1; i < sz(input); i++) {
            v.pb(input[i]);
        }
        v[sz(v) - 1]--;
        v[sz(v) - 2]++;
        if (v[sz(v) - 1] == v[sz(v) - 2]) {
            cout << n << "=";
            for (int i = 0; i < sz(v) - 1; i++) {
                cout << v[i] << "+";
            }
            cout << v[sz(v) - 1];
            return 0;
        }
        if (v[sz(v) - 2] <= v[sz(v) - 1]) {
            while (v[sz(v) - 2] * 2 <= v[sz(v) - 1]) {
                v.pb(v[sz(v) - 1] - v[sz(v) - 2]);
                v[sz(v) - 2] = v[sz(v) - 3];
            }
        } else {
            v[sz(v) - 2] += v[sz(v) - 1];
            v.pop_back();
        }
        cout << n << "=";
        for (int i = 0; i < sz(v) - 1; i++) {
            cout << v[i] << "+";
        }
        cout << v[sz(v) - 1];
    }
}
