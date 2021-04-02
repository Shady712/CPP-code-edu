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
int a[10][16];

bool check(int x, int y) {
    re x <= n && y <= n;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    for (int i = 0; i < 16; i++) {
        a[0][i] = i + 1;
    }
    for (int i = 1; i < 10; i++) {
        a[i][0] = 1;
    }
    a[1][2] = a[2][1] = a[3][2] = a[4][2] = a[5][1] =
    a[6][2] = a[7][2] = a[8][2] = a[9][1] = 2;
    a[1][3] = a[2][2] = a[3][4] = a[4][1] = a[5][2] =
    a[6][4] = a[7][4] = a[8][1] = a[9][2] = 3;
    a[1][1] = a[2][3] = a[3][6] = a[4][3] = a[5][3] =
    a[6][6] = a[7][6] = a[8][3] = a[9][3] = 4;
    a[1][4] = a[2][4] = a[3][7] = a[4][4] = a[5][4] =
    a[6][8] = a[7][1] = a[8][4] = a[9][4] = 5;
    a[1][6] = a[2][5] = a[3][5] = a[4][6] = a[5][5] =
    a[6][10] = a[7][3] = a[8][6] = a[9][5] = 6;
    a[1][7] = a[2][6] = a[3][3] = a[4][5] = a[5][6] =
    a[6][12] = a[7][5] = a[8][5] = a[9][6] = 7;
    a[1][5] = a[2][7] = a[3][1] = a[4][7] = a[5][7] =
    a[6][14] = a[7][7] = a[8][7] = a[9][7] = 8;
    a[1][8] = a[2][8] = a[3][8] = a[4][8] = a[5][8] =
    a[6][15] = a[7][8] = a[8][8] = a[9][8] = 9;
    a[1][10] = a[2][9] = a[3][10] = a[4][10] = a[5][9] =
    a[6][13] = a[7][10] = a[8][10] = a[9][9] = 10;
    a[1][11] = a[2][10] = a[3][12] = a[4][9] = a[5][10] =
    a[6][11] = a[7][12] = a[8][9] = a[9][10] = 11;
    a[1][9] = a[2][11] = a[3][14] = a[4][11] = a[5][11] =
    a[6][9] = a[7][14] = a[8][11] = a[9][11] = 12;
    a[1][12] = a[2][12] = a[3][15] = a[4][12] = a[5][12] =
    a[6][7] = a[7][9] = a[8][12] = a[9][12] = 13;
    a[1][14] = a[2][13] = a[3][13] = a[4][14] = a[5][13] =
    a[6][5] = a[7][11] = a[8][14] = a[9][13] = 14;
    a[1][15] = a[2][14] = a[3][11] = a[4][13] = a[5][14] =
    a[6][3] = a[7][13] = a[8][13] = a[9][14] = 15;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 16; j++) {
            if (!a[i][j]) {
                a[i][j] = 16;
            }
        }
    }
    while (true) {
        cin >> n;
        if (!n) {
            re 0;
        }
        int cur[10];
        for (int i = 0; i < n; i++) {
            cin >> cur[i];
        }
        bool kek = true;
        for (int i = 1; i < n; i++) {
            if (cur[i] < cur[i - 1]) {
                kek = false;
                break;
            }
        }
        if (kek) {
            cout << "-1\n";
            continue;
        }
        int id, k = 0;
        for (int i = 0; i < n; i++) {
            if (cur[i]) {
                id = i + 1;
                break;
            }
        }
        for (int i = 0; i < n; i++) {
            k += cur[i];
        }
        vector < pair <int, int> > ans;
        for (int i = id; i < n; i++) {
            if (cur[i]) {
                ans.pb(id, i + 1);
            }
        }
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 16; j += 2) {
                int x = a[i][j], y = a[i][j + 1];
                bool flag = true;
                if (x >= id) {
                    x++;
                    y++;
                    flag = false;
                }
                if (x > n || y > n) {
                    continue;
                }
                if (y >= id && flag) {
                    y++;
                }
                if (x > n || y > n) {
                    continue;
                }
                ans.pb(x, y);
            }
        }
        for (int i = n - k; i > id; i--) {
            ans.pb(id, i);
        }
        for (int i = 1; i < id; i++) {
            ans.pb(i, id);
        }
        cout << sz(ans) << "\n";
        for (pair <int, int> t : ans) {
            cout << t.fi << " " << t.se << "\n";
        }
    }
}
