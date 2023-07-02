#include "iostream"
#include "fstream"
#include "random"

std::ofstream ofstream;
int i = 1;
std::string const_path = "../tasks/linear_alghorithms/min_and_max/find2Max/tests/0";
std::random_device rd;
std::mt19937 rng(rd());
std::uniform_int_distribution<int> dis_n(0, 100000);
std::uniform_int_distribution<int> dis_num(-2000000000, 2000000000);

std::pair<int, int> getMinAndMax(int n, const std::vector<int> &nums) {
    int first_max = INT32_MIN, second_max = INT32_MIN;

    int ii = 0, j = n;

    while (ii < j) {
        int m1 = std::max(nums[ii], nums[j]);

        if (m1 > first_max) {
            if (first_max != second_max) {
                second_max = first_max;
            }

            first_max = m1;
        } else if (m1 > second_max && m1 != first_max) {
            second_max = m1;
        }

        ++ii;
    }

    return {first_max, second_max};
}

void fileSimpleTestsWriter(int count_of_tasks) {
    std::vector<int> nums(100000);

    for (int j = 0; j < count_of_tasks; ++j) {
        if (i == 10) {
            const_path.pop_back();
        }

        ofstream.open(const_path + std::to_string(i));

        int n = dis_n(rng);
        ofstream << n << '\n';

        for (int k = 0; k < n; ++k) {
            int num = dis_num(rng);
            ofstream << num << ' ';
            nums[k] = num;
        }

        ofstream.close();

        ofstream.open(const_path + std::to_string(i++) + ".a");
        auto res = getMinAndMax(n, nums);
        ofstream << res.first << ' ' << res.second;
        ofstream.close();

        nums.clear();
    }
}

void limitTest(bool negative) {
    std::vector<int> nums(100000);
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
    ofstream << res.first << ' ' << res.second;
    ofstream.close();
}

int main() {
    /* sample tests */
    // 1
    ofstream.open(const_path + std::to_string(i));
    ofstream << 2 << '\n' << -5 << ' ' << 6;
    ofstream.close();
    ofstream.open(const_path + std::to_string(i++) + ".a");
    auto res = getMinAndMax(2, {-5, 6});
    ofstream << res.first << ' ' << res.second;
    ofstream.close();

    // 2
    ofstream.open(const_path + std::to_string(i));
    ofstream << 4 << '\n' << 1 << ' ' << 2 << ' ' << 3 << ' ' << 4;
    ofstream.close();
    ofstream.open(const_path + std::to_string(i++) + ".a");
    res = getMinAndMax(4, {1, 2, 3, 4});
    ofstream << res.first << ' ' << res.second;
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
    ofstream << res.first << ' ' << res.second;
    ofstream.close();

    // 2
    limitTest(false);

    // 3
    limitTest(true);
}
