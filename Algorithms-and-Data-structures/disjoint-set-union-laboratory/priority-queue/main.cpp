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

struct heapster {
    int value;
    int pos;
    heapster(int x, int y) {
        value = x;
        pos = y;
    }
};

vector <heapster*> heap;
vector <int> position;

void siftUp(int id) {
    while (heap[id] -> value < heap[(id - 1) / 2] -> value) {
        swap(heap[id], heap[(id - 1) / 2]);
        position[heap[id] -> pos] = id;
        id = (id - 1) / 2;
        position[heap[id] -> pos] = id;
    }
}
void siftDown(int id) {
    while (2 * id + 1 < sz(heap)) {
        int left = 2 * id + 1;
        int right = 2 * id + 2;
        int j = left;
        if (right < sz(heap) && heap[right] -> value < heap[left] -> value) {
            j = right;
        }
        if (heap[id] -> value <= heap[j] -> value) {
            break;
        }
        swap(heap[id], heap[j]);
        position[heap[id] -> pos] = id;
        position[heap[j] -> pos] = j;
        id = j;
    }
}
heapster* extractMin() {
    if (!sz(heap)) {
        return NULL;
    }
    heapster* ans = heap[0];
    swap(heap[0], heap[sz(heap) - 1]);
    position[heap[0] -> pos] = 0;
    position[heap[sz(heap) - 1] -> pos] = sz(heap) - 1;
    heap.pop_back();
    siftDown(0);
    ans -> pos++;
    return ans;
}
void decreaseKey(int pos, int d) {
    if (position[pos] < sz(heap)) {
        heap[position[pos]] -> value = d;
        siftUp(position[pos]);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string quest;
    while (cin >> quest) {
        if (quest == "push") {
            int x;
            cin >> x;
            heap.pb(new heapster(x, sz(position)));
            position.pb(sz(heap) - 1);
            siftUp(position[sz(position) - 1]);
        }
        if (quest == "extract-min") {
            heapster* ans = extractMin();
            if (ans == NULL) {
                cout << "*\n";
            } else {
                cout << ans -> value << " " << ans -> pos << "\n";
            }
        }
        if (quest == "decrease-key") {
            int x, y;
            cin >> x >> y;
            x--;
            decreaseKey(x, y);
        }
        if (quest != "push") {
            position.pb(MOD);
        }
    }
}
