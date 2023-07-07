#include "iostream"
#include "fstream"
#include "random"
#include "iomanip"

union ToString {
    int val;
    double v;

    [[nodiscard]] std::string intToString() const {
        return "int_value = " + std::to_string(val);
    }

    std::string doubleToString() const {
        return "double_value = ";
    }
};

std::ofstream ofstream;
int i = 1;
int const maxN = 5000;
std::string const_path = "../tasks/union/classify_the_value/tests/0";
std::random_device rd;
std::mt19937 rng(rd());
std::uniform_int_distribution<int> dis_n(1, 5000);
std::uniform_int_distribution<int> dis_num(-2*1000000000, 2*1000000000);
std::uniform_real_distribution<double> dis_d(-2*10e18, 2*10e18);
std::uniform_int_distribution<int> dis_r(0, 1);

void getStringPres(int n, const std::vector<double> &nums) {
    ofstream.open(const_path + std::to_string(i++) + ".a");

    ToString toString {};

    for (int ii = 0; ii < n; ++ii) {
        double num = nums[ii];

        if (num == static_cast<int>(num)) {
            toString.val = static_cast<int>(num);
            ofstream << toString.intToString();
        } else {
            toString.v = num;
            ofstream << toString.doubleToString() << std::fixed << std::setprecision(7) << toString.v;
        }

        ofstream << '\n';
    }

    ofstream.close();
}

void fileSimpleTestsWriter(int count_of_tasks) {
    std::vector<double> nums(maxN);

    for (int j = 0; j < count_of_tasks; ++j) {
        if (i == 10) {
            const_path.pop_back();
        }

        ofstream.open(const_path + std::to_string(i));

        int n = dis_n(rng);
        ofstream << n << '\n';
        nums.assign(n, 0);

        for (int p = 1; p <= n; ++p) {
            int h = dis_r(rng);

            if (h == 0) {
                nums[p - 1] = static_cast<double>(dis_num(rng));
            } else {
                nums[p - 1] = dis_d(rng);
            }

            ofstream << nums[p - 1] << '\n';
        }

        ofstream.close();
        getStringPres(n, nums);
        nums.clear();
    }
}

void limitTest(bool min) {
    std::vector<double> nums(maxN);
    ofstream.open(const_path + std::to_string(i));
    int n = maxN;

    if (min) {
        n = 1;
    }

    ofstream << n << '\n';

    for (int p = 1; p <= n; ++p) {
        int h = dis_r(rng);

        if (h == 0) {
            if (min) {
                nums[p - 1] = static_cast<double>(-2*1000000000);
            } else {
                nums[p - 1] = static_cast<double>(2*1000000000);
            }
        } else {
            if (min) {
                nums[p - 1] = static_cast<double>(-2*10e18);
            } else {
                nums[p - 1] = static_cast<double>(2*10e18);
            }
        }

        ofstream << nums[p - 1] << '\n';
    }

    ofstream.close();
    getStringPres(n, nums);
    nums.clear();
}

int main() {
    /* sample tests */
    // 1
    ofstream.open(const_path + std::to_string(i));
    ofstream << 2 << '\n' << 1 << '\n' << -383.38;
    ofstream.close();
    getStringPres(2, {1, -383.38});

    // 2
    ofstream.open(const_path + std::to_string(i));
    ofstream << 4 << '\n' << 1 << '\n' << 3 << '\n' << 4 << '\n' << 38338.3883;
    ofstream.close();
    getStringPres(4, {1, 3, 4, 38338.3883});

    /* random tests */
    fileSimpleTestsWriter(20);

    /* limit tests */
    limitTest(false);
    limitTest(true);
}