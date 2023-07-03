#include "iostream"
#include "fstream"
#include "random"

std::ofstream ofstream;
int i = 1;
int const maxN = 1000000;
std::string const_path = "../tasks/linear_alghorithms/prefix_sums/part_sums/tests/0";
std::random_device rd;
std::mt19937 rng(rd());
std::uniform_int_distribution<int> dis_n(1, maxN);
std::uniform_int_distribution<int> dis_num(-10000, 10000);

void getPartSums(int n, const std::vector<int> &nums, const std::vector<std::pair<int, int>> &requests) {
    ofstream.open(const_path + std::to_string(i++) + ".a");

    int partsum[n];
    partsum[0] = 0;
    for (int ii = 1; ii <= n; ++ii) {
        partsum[ii] = partsum[ii - 1] + nums[ii - 1];
    }

    for (auto pair : requests) {
        ofstream << partsum[pair.second] - partsum[pair.first - 1] << '\n';
    }

    ofstream.close();
}

std::pair<int, int> getPair(int n) {
    int l = dis_n(rng) % n;
    l = l == 0 ? 1 : l;

    if (l == n) {
        return {n - 1, n};
    }

    int r = l + dis_n(rng) % (n - l);

    return {l, r};
}

void fileSimpleTestsWriter(int count_of_tasks) {
    std::vector<int> nums(maxN);
    std::vector<std::pair<int, int>> requests(maxN);

    for (int j = 0; j < count_of_tasks; ++j) {
        if (i == 10) {
            const_path.pop_back();
        }

        ofstream.open(const_path + std::to_string(i));

        int n = dis_n(rng);
        ofstream << n << '\n';
        nums.assign(n, 0);

        for (int p = 0; p < n; ++p) {
            nums[p] = dis_num(rng);
            ofstream << nums[p] << ' ';
        }

        ofstream << '\n';

        int count = dis_n(rng) % n;
        count = count == 0 ? 1 : count;
        requests.assign(count, {0, 0});

        ofstream << count << '\n';

        for (int k = 0; k < count; ++k) {
            auto pair = getPair(n);
            requests[k] = pair;
            ofstream << pair.first << ' ' << pair.second << '\n';
        }

        ofstream.close();
        getPartSums(n, nums, requests);
        nums.clear();
    }
}

void limitTest(bool min) {
    std::vector<int> nums(maxN);
    std::vector<std::pair<int, int>> requests(maxN);

    ofstream.open(const_path + std::to_string(i));
    int n = maxN;

    if (min) {
        n = 1;
    }

    for (int p = 0; p < n; ++p) {
        nums[p] = min ? -10000 : 10000;
        ofstream << nums[p] << ' ';
    }

    ofstream << '\n';

    int count = min ? 1 : maxN;
    requests.assign(count, {0, 0});

    ofstream << count << '\n';

    for (int k = 0; k < count; ++k) {
        auto pair = getPair(n);
        requests[k] = pair;
        ofstream << pair.first << ' ' << pair.second << '\n';
    }

    ofstream.close();
    getPartSums(n, nums, requests);
    nums.clear();
}

int main() {
    /* sample tests */
    // 1
    ofstream.open(const_path + std::to_string(i));
    ofstream << 2 << '\n' << 1 << ' ' << 2 << '\n' << 1 << '\n' << 1 << ' ' << 2;
    ofstream.close();
    getPartSums(2, {1, 2}, {{1, 2}});

    // 2
    ofstream.open(const_path + std::to_string(i));
    ofstream << 4 << '\n' << 1 << ' ' << 3 << ' ' << 4 << ' ' << 2 << '\n' << 2 << '\n' << 1 << ' ' << 4 << '\n' << 2 << ' ' << 3;
    ofstream.close();
    getPartSums(4, {1, 3, 4, 2}, {{1, 4}, {2, 3}});

    /* random tests */
    fileSimpleTestsWriter(20);

    /* limit tests */
    limitTest(false);
    limitTest(true);
}

