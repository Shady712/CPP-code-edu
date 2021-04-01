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
int index[26];
void solve(int id) {
    int symbol = s[id] - 'a';
    cout << index[symbol] << " ";
    for (int i = 0; i < 26; i++) {
        index[i] < index[symbol] ? index[i]++ : index[i];
        /*if (index[i] < index[symbol]) {
            index[i]++;
        }*/
    }
    index[symbol] = 1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    for (int i = 0; i < 26; i++) {
        index[i] = (++i)--;
    }
    cin >> s;
    n = sz(s);
    for (int i = 0; i < n; i++) {
        solve(i);
    }
}
