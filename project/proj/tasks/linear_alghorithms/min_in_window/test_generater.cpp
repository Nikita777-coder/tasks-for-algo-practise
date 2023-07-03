#include "iostream"
#include "fstream"
#include "random"
#include "deque"

std::ofstream ofstream;
int i = 1;
int const maxN = 100000;
std::string const_path = "../tasks/linear_alghorithms/min_in_window/tests/0";
std::random_device rd;
std::mt19937 rng(rd());
std::uniform_int_distribution<int> dis_n(1, maxN);
std::uniform_int_distribution<int> dis_num(-10000, 10000);
std::uniform_int_distribution<int> dis_k(2, maxN - 1);
std::deque<int> q;

void pb (int x){
    while (!q.empty() && x < q.back()) {
        q.pop_back();
    }
    q.push_back(x);
}

void getMinInWind(int n, int k, const std::vector<int> &nums) {
    ofstream.open(const_path + std::to_string(i++) + ".a");

    for (int ii = 0; ii < k; ++ii) {
        pb(nums[ii]);
    }
    for (int r = k; r < n; ++r) {
        ofstream << q.front() << '\n';
        if (nums[r - k] == q.front())
            q.pop_front();
        pb(nums[r]);
    }

    ofstream << q.front();
    q.clear();

    ofstream.close();
}

void fileSimpleTestsWriter(int count_of_tasks) {
    std::vector<int> nums(maxN);

    for (int j = 0; j < count_of_tasks; ++j) {
        if (i == 10) {
            const_path.pop_back();
        }

        ofstream.open(const_path + std::to_string(i));

        int n = dis_n(rng);
        ofstream << n << '\n';
        nums.assign(n, 0);

        int k = dis_k(rng);

        for (int p = 0; p < n; ++p) {
            nums[p] = dis_num(rng);
            ofstream << nums[p] << ' ';
        }

        ofstream.close();
        getMinInWind(n, k, nums);
        nums.clear();
    }
}

void limitTest(bool min) {
    std::vector<int> nums(maxN);

    ofstream.open(const_path + std::to_string(i));
    int n = maxN;

    if (min) {
        n = 1;
    }

    int k = dis_k(rng);
    ofstream << n << ' ' << k << '\n';

    for (int p = 0; p < n; ++p) {
        nums[p] = min ? -10000 : 10000;
        ofstream << nums[p] << ' ';
    }

    ofstream.close();
    getMinInWind(n, k, nums);
    nums.clear();
}

int main() {
    /* sample tests */
    // 1
    ofstream.open(const_path + std::to_string(i));
    ofstream << 2 << ' ' << 2 << '\n' << 1 << ' ' << 2;
    ofstream.close();
    getMinInWind(2, 2, {1, 2});

    // 2
    ofstream.open(const_path + std::to_string(i));
    ofstream << 4 << ' '<< 2 << '\n' << 1 << ' ' << 3 << ' ' << 4 << ' ' << 2;
    ofstream.close();
    getMinInWind(4, 2, {1, 3, 4, 2});

    /* random tests */
    fileSimpleTestsWriter(20);

    /* limit tests */
    limitTest(false);
    limitTest(true);
}