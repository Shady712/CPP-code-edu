#include <iostream>

using namespace std;

struct node {
    int key;
    node* left;
    node* right;
    int sz;
    int priority;
    node(int x) {
        key = x;
        left = right = nullptr;
        sz = 1;
        priority = rand() % (int)1e8;
    }
};

node* root = nullptr;

int minimum(node* t) {
    return t -> left == nullptr ? t -> key : minimum(t -> left);
}
int maximum(node* t) {
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
        return p;
    } else {
        node* ans = merge(t -> right, p);
        t -> right = ans;
        t -> sz = newSize(t);
        return t;
    }
}

pair <node*, node*> split(node* t, int x) {
    if (t == nullptr) {
        return {nullptr, nullptr};
    }

    if (t -> key < x) {
        auto ans = split(t -> right, x);
        t -> right = ans.first;
        t -> sz = newSize(t);
        return {t, ans.second};
    } else {
        auto ans = split(t -> left, x);
        t -> left = ans.second;
        t -> sz = newSize(t);
        return {ans.first, t};
    }
}

void insert(int x) {
    node* newNode = new node(x);
    auto tmp = split(root, x);
    node* t = merge(tmp.first, newNode);
    root = merge(t, tmp.second);
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

void solve() {
    string quest;
    int x;
    cin >> quest >> x;
    if (quest == "+1" || quest == "1") {
        insert(x);
    } else if (quest == "0") {
        cout << statistics(root, x - 1) -> key << "\n";
    } else if (quest == "-1") {
        del(x);
    }
}
int main() {
    int quests;
    cin >> quests;
    while (quests--) {
        solve();
    }
}
