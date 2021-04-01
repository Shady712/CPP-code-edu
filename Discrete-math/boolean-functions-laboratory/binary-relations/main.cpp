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
bool a[100][100];
bool b[100][100];
bool c[100][100];
void solve(bool a[100][100]) {
    bool check = true;
    for (int i = 0; i < n; i++)
        if (!a[i][i]) {
            check = false;
            break;
        }
    cout << (check ? 1 : 0) << " ";
    check = true;
    for (int i = 0; i < n; i++)
        if (a[i][i]) {
            check = false;
            break;
        }
    cout << (check ? 1 : 0) << " ";
    check = true;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (a[i][j] && !a[j][i]) {
                check = false;
                break;
            }
        }
    cout << (check ? 1 : 0) << " ";
    check = true;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (a[i][j] && a[j][i] && i != j) {
                check = false;
                break;
            }
        }
    cout << (check ? 1 : 0) << " ";
    check = true;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (a[i][j]) {
                for (int k = 0; k < n; k++)
                    if (a[j][k] && !a[i][k]) {
                        check = false;
                        break;
                    }
            }
        }
    cout << (check ? 1 : 0) << "\n";
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> b[i][j];
    solve(a);
    solve(b);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (a[i][j]) {
                for (int k = 0; k < n; k++)
                    if (b[j][k])
                        c[i][k] = true;
            }
        }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << c[i][j] << " ";
        cout << "\n";
    }

}