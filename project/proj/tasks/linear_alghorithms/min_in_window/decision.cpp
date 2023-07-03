#include "iostream"
#include "vector"
#include "deque"

std::deque<int> q;

void pb (int x){
    while (!q.empty() && x < q.back()) {
        q.pop_back();
    }
    q.push_back(x);
}

int main() {
    int n;
    int k;
    std::cin >> n >> k;
    std::vector<int> a(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    for (int i = 0; i < k; ++i) {
        pb(a[i]);
    }
    for (int r = k; r < n; ++r) {
        std::cout << q.front() << '\n';
        if (a[r - k] == q.front())
            q.pop_front();
        pb(a[r]);
    }

    std::cout << q.front();
}
