#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define pb emplace_back
#define all(x) (x).begin(), (x).end()

struct node {
    long long key;
    node* left;
    node* right;
    int sz;
    int priority;
    long long sum;
    node(long long x) {
        key = sum = x;
        left = right = nullptr;
        sz = 1;
        priority = rand() % (int)1e8;
    }
    node(long long x, int y) {
        key = sum = x;
        left = right = nullptr;
        sz = 1;
        priority = y;
    }
};

struct decomposition {
    int parent;
    int left;
    int right;
};

node* root = nullptr;

long long minimum(node* t) {
    return t -> left == nullptr ? t -> key : minimum(t -> left);
}
long long maximum(node* t) {
    return t -> right == nullptr ? t -> key : maximum(t -> right);
}

node* next(int x) {
    node* cur = root;
    node* ans = nullptr;
    while (cur != nullptr) {
        if (cur -> key <= x) {
            cur = cur -> right;
        } else {
            ans = cur;
            cur = cur -> left;
        }
    }
    return ans;
}
node* prev(int x) {
    node* cur = root;
    node* ans = nullptr;
    while (cur != nullptr) {
        if (cur -> key < x) {
            ans = cur;
            cur = cur -> right;
        } else {
            cur = cur -> left;
        }
    }
    return ans;
}
bool exists(node* cur, int x) {
    if (cur == nullptr) {
        return false;
    }

    if (cur -> key == x) {
        return true;
    }

    if (cur -> key < x) {
        return exists(cur -> right, x);
    } else {
        return exists(cur -> left, x);
    }
}

int newSize(node* t) {
    if (t == nullptr) {
        return 0;
    }
    int ans = 1;
    if (t -> left != nullptr) {
        ans += t -> left -> sz;
    }
    if (t -> right != nullptr) {
        ans += t -> right -> sz;
    }
    return ans;
}
long long newSum(node* t) {
    if (t == nullptr) {
        return 0;
    }
    long long ans = t -> key;
    if (t -> left != nullptr) {
        ans += t -> left -> sum;
    }
    if (t -> right != nullptr) {
        ans += t -> right -> sum;
    }
    return ans;
}

node* merge(node* t, node* p) {
    if (t == nullptr || p == nullptr) {
        if (t == nullptr && p == nullptr) {
            return nullptr;
        } else if (t == nullptr) {
            return p;
        } else {
            return t;
        }
    }

    if (t -> priority <= p -> priority) {
        node* ans = merge(t, p -> left);
        p -> left = ans;
        p -> sz = newSize(p);
        p -> sum = newSum(p);
        return p;
    } else {
        node* ans = merge(t -> right, p);
        t -> right = ans;
        t -> sz = newSize(t);
        t -> sum = newSum(t);
        return t;
    }
}

pair <node*, node*> split(node* t, long long x) {
    if (t == nullptr) {
        return {nullptr, nullptr};
    }

    if (t -> key < x) {
        auto ans = split(t -> right, x);
        t -> right = ans.first;
        t -> sz = newSize(t);
        t -> sum = newSum(t);
        if (ans.first != nullptr) {
            ans.first -> sum = newSum(ans.first);
        }
        if (ans.second != nullptr) {
            ans.second -> sum = newSum(ans.second);
        }
        return {t, ans.second};
    } else {
        auto ans = split(t -> left, x);
        t -> left = ans.second;
        t -> sz = newSize(t);
        t -> sum = newSum(t);
        if (ans.first != nullptr) {
            ans.first -> sum = newSum(ans.first);
        }
        if (ans.second != nullptr) {
            ans.second -> sum = newSum(ans.second);
        }
        return {ans.first, t};
    }
}

void insert(int x) {
    node* newNode = new node(x);
    auto tmp = split(root, x);
    node* t = merge(tmp.first, newNode);
    root = merge(t, tmp.second);
}

void insert(long long x) {
    auto newTree = split(root, x);
    x++;
    auto checker = split(newTree.second, x);
    x--;
    if (checker.first == nullptr) {
        root = merge(newTree.first, checker.second);
        auto finalTree = split(root, x);
        node* t = new node(x);
        auto unite = merge(finalTree.first, t);
        root = merge(unite, finalTree.second);
    } else {
        auto unite = merge(newTree.first, checker.first);
        root = merge(unite, checker.second);
    }
}

void del(int x) {
    auto t = split(root, x), p = split(t.second, ++x);
    root = merge(t.first, p.second);
}

node* statistics(node* t, int x) {
    int sz = (t -> right == nullptr) ? 0 : t -> right -> sz;

    if (sz == x) {
        return t;
    }

    if (sz < x) {
        return statistics(t -> left, x - sz - 1);
    } else {
        return statistics(t -> right, x);
    }
}

long long getAns(int l, int r) {
    long long ans = 0ll;

    auto leftDiv = split(root, l);
    auto rightDiv = split(leftDiv.second, r);

    ans = (rightDiv.first == nullptr) ? 0 : rightDiv.first -> sum;

    auto newNode = merge(leftDiv.first, rightDiv.first);
    root = merge(newNode, rightDiv.second);

    return ans;
}

long long ans = -1;

void solve() {
    string quest;
    cin >> quest;
    if (quest == "+") {
        long long x;
        cin >> x;
        if (ans != -1) {
            x = (x + ans) % (long long) 1e9;
            ans = -1;
        }
        insert(x);
    } else if (quest == "?") {
        int l, r;
        cin >> l >> r;
        ans = getAns(l, r + 1);
        cout << ans << "\n";
    }
}
int main() {
    int quests;
    cin >> quests;
    while (quests--) {
        solve();
    }
}
