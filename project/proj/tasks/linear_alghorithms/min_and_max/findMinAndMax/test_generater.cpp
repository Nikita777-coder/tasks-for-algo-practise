#include "iostream"
#include "fstream"
#include "random"

std::ofstream ofstream;
int i = 1;
std::string const_path = "../tasks/linear_alghorithms/min_and_max/findMinAndMax/tests/0";
std::random_device rd;
std::mt19937 rng(rd());
std::uniform_int_distribution<int> dis_n(0, 100000);
std::uniform_real_distribution<double> dis_num(-1000000000, 1000000000);

std::pair<double, double> getMinAndMax(int n, const std::vector<double> &nums) {
    double min = INT64_MAX, max = INT64_MIN;
    double num;

    for (int j = 0; j < n; ++j) {
        num = nums[j];

        if (num < min) {
            min = num;
        }

        if (num > max) {
            max = num;
        }
    }

    if (min == INT64_MAX && max == INT64_MIN) {
        min = 0;
        max = 0;
    }

     return {min, max};
}

void fileSimpleTestsWriter(int count_of_tasks) {
    std::vector<double> nums(100000);

    for (int j = 0; j < count_of_tasks; ++j) {
        if (i == 10) {
            const_path.pop_back();
        }

        ofstream.open(const_path + std::to_string(i));

        int n = dis_n(rng);

        for (int k = 0; k < n; ++k) {
            double num = dis_num(rng);
            ofstream << num << ' ';
            nums[k] = num;
        }

        ofstream.close();

        ofstream.open(const_path + std::to_string(i++) + ".a");
        auto res = getMinAndMax(n, nums);
        ofstream << std::fixed << std::setprecision(3) << res.first << ' ' << res.second;
        ofstream.close();

        nums.clear();
    }
}

void limitTest(bool negative) {
    std::vector<double> nums(100000);
    ofstream.open(const_path + std::to_string(i));

    int n = 100000;

    for (int k = 0; k < n; ++k) {
        int num;

        if (!negative) {
            num = 1000000000;
        } else {
            num = -1000000000;
        }

        ofstream << num << ' ';
        nums[k] = num;
    }

    ofstream.close();

    ofstream.open(const_path + std::to_string(i++) + ".a");
    auto res = getMinAndMax(n, nums);
    ofstream << std::fixed << std::setprecision(3) << res.first << ' ' << res.second;
    ofstream.close();
}

int main() {
    /* sample tests */
    // 1
    ofstream.open(const_path + std::to_string(i));
    ofstream << -5.0138 << ' ' << 6.244;
    ofstream.close();
    ofstream.open(const_path + std::to_string(i++) + ".a");
    auto res = getMinAndMax(2, {-5.0138, 6.244});
    ofstream << std::fixed << std::setprecision(3) << res.first << ' ' << res.second;
    ofstream.close();

    // 2
    ofstream.open(const_path + std::to_string(i));
    ofstream << 1.348 << ' ' << 2.594939 << ' ' << 3.3434 << ' ' << 4.3434;
    ofstream.close();
    ofstream.open(const_path + std::to_string(i++) + ".a");
    res = getMinAndMax(4, {1.348, 2.594939, 3.3434, 4.3434});
    ofstream << std::fixed << std::setprecision(3) << res.first << ' ' << res.second;
    ofstream.close();

    /* random tests */
    fileSimpleTestsWriter(20);

    /* limit tests */
    // 1
    ofstream.open(const_path + std::to_string(i));
    ofstream << 0 << '\n';
    ofstream.close();
    ofstream.open(const_path + std::to_string(i++) + ".a");
    res = getMinAndMax(0, {});
    ofstream << std::fixed << std::setprecision(3) << res.first << ' ' << res.second;
    ofstream.close();

    // 2
    limitTest(false);

    // 3
    limitTest(true);
}