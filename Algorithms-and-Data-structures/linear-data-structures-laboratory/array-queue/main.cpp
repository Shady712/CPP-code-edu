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
struct Vector {
    int first;
    int last;
    int sz;
    int* arr;
    void push(int x) {
        if (first == -1) {
            arr[0] = x;
            first = last = 0;
            re;
        }
        if (last == sz) {
            last = 0;
        }
        if (last == first) {
            int* newArr = new int[sz * 2];
            for (int i = first; i < sz; i++)
                newArr[i - first] = arr[i];
            for (int i = 0; i < last; i++)
                newArr[sz - first + i] = arr[i];
            delete arr;
            arr = newArr;
            first = 0;
            last = sz;
            sz *= 2;
        }
        arr[last] = x;
        last++;
        if (last == sz)
            last = 0;
    }
    void pop() {
        first++;
        if (first == sz)
            first = 0;
        if (first == last) {
            first = last = -1;
            delete arr;
            arr = new int[1];
            sz = 1;
        }
    }
    Vector() {
        first = last = -1;
        sz = 1;
        arr = new int[1];
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    Vector* v = new Vector();
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (c == '+') {
            int x;
            cin >> x;
            v -> push(x);
        } else {
            cout << v -> arr[v -> first] << "\n";
            v -> pop();
        }
    }
}
