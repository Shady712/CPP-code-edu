#include <iostream>
#include <vector>

using namespace std;

const int N = 1e7 + 7;

struct element {
    string key;
    string value;
    element* previous{};
    element* next{};
};
vector <element*> hashSet[N];
element* last = nullptr;
string key, value;
int hashFunction() {
    int id = 0;
    for (char i : key) {
        id = id * 239 + (int) i;
    }
    return abs(id + 17) % N;
}

int indexOf(int id) {
    for (int i = 0; i < (int) hashSet[id].size(); i++) {
        if (hashSet[id][i] -> key == key) {
            return i;
        }
    }
    return -1;
}

string get() {
    int hf = hashFunction();
    int id = indexOf(hf);
    return id == -1 ? "none" : hashSet[hf][id] -> value;
}

void insert() {
    int hf = hashFunction();
    int id = indexOf(hf);
    if (id == -1) {
        auto e = new element();
        e -> key = key;
        e -> value = value;
        e -> previous = last;
        e -> next = nullptr;
        if (last != nullptr) {
            last -> next = e;
        }
        last = e;
        hashSet[hf].emplace_back(e);
    } else {
        hashSet[hf][id] -> value = value;
    }
}

void del() {
    int hf = hashFunction();
    int id = indexOf(hf);
    if (id != -1) {
        auto previous = hashSet[hf][id] -> previous;
        auto next = hashSet[hf][id] -> next;
        if (previous != nullptr) {
            previous -> next = next;
        }
        if (next != nullptr) {
            next -> previous = previous;
        } else {
            last = previous;
        }
        swap(hashSet[hf][id], hashSet[hf][(int) hashSet[hf].size() - 1]);
        hashSet[hf].pop_back();
    }
}

string prev() {
    int hf = hashFunction();
    int id = indexOf(hf);
    if (id == -1 || hashSet[hf][id] -> previous == nullptr) {
        return "none";
    } else {
        return hashSet[hf][id] -> previous -> value;
    }
}

string next() {
    int hf = hashFunction();
    int id = indexOf(hf);
    if (id == -1 || hashSet[hf][id] -> next == nullptr) {
        return "none";
    } else {
        return hashSet[hf][id] -> next -> value;
    }
}

string quest;
void solve() {
    cin >> key;
    if (quest == "put") {
        cin >> value;
        insert();
    } else if (quest == "delete") {
        del();
    } else if (quest == "get") {
        cout << get() << "\n";
    } else if (quest == "prev") {
        cout << prev() << "\n";
    } else if (quest == "next") {
        cout << next() << "\n";
    } else {
        throw invalid_argument("Unsupported operation");
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    while (cin >> quest) {
        solve();
    }
}
