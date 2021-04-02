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

int n, m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    if (m == 1) {
        cout << "0 1 1\n";
        re 0;
    }
    if (m == 2) {
        cout << "1 1 2\n";
        cout << "0 1 2\n";
        re 0;
    }
    if (m == 3) {
        cout << "1 2 1\n";
        cout << "1 3 1\n";
        cout << "0 2 3\n";
        re 0;
    }
    cout << "1 3 1\n";
    cout << "1 3 2\n";
    m -= 2;
    int apex = 3;
    while (m) {
        cout << 1 << " " << apex + 1 << " " << apex << "\n";
        m--;
        int tmp = apex % 2;
        if (!tmp) {
            tmp += 2;
        }
        while (m) {
            if (tmp >= apex - 1) {
                break;
            }
            cout << 0 << " " << tmp << " " << tmp + 1 << "\n";
            tmp += 2;
            m--;
        }
        apex++;
    }
}
