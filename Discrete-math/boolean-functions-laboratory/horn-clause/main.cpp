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


int n, k;
int a[100][100];
bool done[100];
int value[100];
int lit(int id) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[id][i] == 1 && value[i] == -1) {
            ans++;
        }
        if (a[id][i] == -1 && value[i] == -1) {
            ans++;
        }
    }
    re ans;
}
int check() {
    int ans = -1;
    for (int i = 0; i < k; i++){
        if (!done[i] && lit(i) == 1) {
            ans = i;
            break;
        }
    }
    re ans;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (!a[i][j]) {
                a[i][j] = -1;
            } else {
                if (a[i][j] == -1) {
                    a[i][j] = 0;
                }
            }
        }
    }
    memset(value, -1, sizeof(value));
    int cnt = check();
    while (cnt != -1) {
        int id = 0;
        for (int i = 0; i < n; i++) {
            if (a[cnt][i] && value[i] == -1) {
                id = i;
                break;
            }
        }
        if (a[cnt][id] == 1) {
            value[id] = 1;
        } else {
            value[id] = 0;
        }
        done[cnt] = true;
        for (int i = 0; i < k; i++) {
            if (done[i]) {
                continue;
            }
            if (value[id]) {
                if (a[i][id] == 1) {
                    done[i] = true;
                } else {
                    if (a[i][id] == -1 && !lit(i)) {
                        cout << "YES";
                        re 0;
                    }
                }
            } else {
                if (a[i][id] == -1) {
                    done[i] = true;
                } else {
                    if (a[i][id] == 1 && !lit(i)) {
                        cout << "YES";
                        re 0;
                    }
                }
            }
        }
        cnt = check();
    }
    cout << "NO";
}
