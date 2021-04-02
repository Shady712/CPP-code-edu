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

struct Vector {
    int sz;
    int cur;
    int* arr;
    void push(int x) {
        cur++;
        if (cur == sz) {
            int* old = arr;
            sz *= 2;
            arr = new int[sz];
            for (int i = 0; i < cur; i++)
                arr[i] = old[i];
        }
        arr[cur] = x;
    }
    void pop() {
        cur--;
        if ((cur + 1) * 2 == sz) {
            int* newArr = new int[sz / 2];
            for (int i = 0; i < cur + 1; i++)
                newArr[i] = arr[i];
            arr = newArr;
            sz /= 2;
        }
    }
    Vector(int x) {
        sz = x;
        cur = -1;
        arr = new int[sz];
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    Vector *v = new Vector(1);
    int q;
    cin >> q;
    for (int iii = 0; iii < q; iii++) {
        char c;
        cin >> c;
        if (c == '+') {
            int x;
            cin >> x;
            v -> push(x);
        } else {
            cout << v -> arr[v -> cur] << "\n";
            v -> pop();
        }
    }
}
