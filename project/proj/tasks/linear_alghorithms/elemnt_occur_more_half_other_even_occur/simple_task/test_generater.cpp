#include "iostream"
#include "fstream"
#include "random"

std::ofstream ofstream;
int i = 1;
int const maxN = 1000;
std::string const_path = "../tasks/linear_alghorithms/elemnt_occur_more_half_other_even_occur/simple_task/tests/0";
std::random_device rd;
std::mt19937 rng(rd());
std::uniform_int_distribution<int> dis_n(1, maxN);
std::uniform_int_distribution<int> dis_num(-1000, 1000);
std::uniform_int_distribution<int> dis_count(2, maxN / 2);

void getOddNum(int n, const std::vector<int> &nums) {
    ofstream.open(const_path + std::to_string(i++) + ".a");

    int b = 0;

    for (int ii = 0; ii < n; ++ii) {
        b ^= nums[ii];
    }

    ofstream << b;

    ofstream.close();
}

int getOdd(int num) {
    return num + (1 - num % 2);
}

int getEven(int num) {
    return num + num % 2;
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

        int odd_num = dis_num(rng);
        int odd_count = getOdd(getOdd(dis_count(rng)) % n);

        for (int k = 0; k < odd_count; ++k) {
            nums[k] = odd_num;
            ofstream << odd_num << ' ';
        }

        int last_pos = odd_count;

        while (last_pos < n - 1) {
            int even_num = dis_num(rng);
            int l = (n - last_pos == 2 ? 3 : n - last_pos);
            int even_count = getEven(getEven(dis_count(rng)) % l);
            even_count = (even_count > 0 ? even_count : 0);

            for (int k = 0; k < even_count; ++k) {
                nums[last_pos++] = even_num;
                ofstream << even_num << ' ';
            }
        }

        ofstream.close();
        getOddNum(n, nums);
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

    ofstream << n << '\n';

    int odd_num = min ? -999 : 999;
    int odd_count = getOdd(getOdd(dis_count(rng)) % n);

    for (int k = 0; k < odd_count; ++k) {
        nums[k] = odd_num;
        ofstream << odd_num << ' ';
    }

    int last_pos = odd_count;

    while (last_pos < n - 1) {
        int even_num = min ? -1000 : 1000;
        int l = (n - last_pos == 2 ? 3 : n - last_pos);
        int even_count = getEven(getEven(dis_count(rng)) % l);
        even_count = (even_count > 0 ? even_count : 0);

        for (int k = 0; k < even_count; ++k) {
            nums[last_pos++] = even_num;
            ofstream << even_num << ' ';
        }
    }

    ofstream.close();
    getOddNum(n, nums);
    nums.clear();
}

int main() {
    /* sample tests */
    // 1
    ofstream.open(const_path + std::to_string(i));
    ofstream << 3 << '\n' << 1 << ' ' << 1 << ' ' << 3;
    ofstream.close();
    getOddNum(3, {1, 1, 3});

    // 2
    ofstream.open(const_path + std::to_string(i));
    ofstream << 4 << '\n' << 1 << ' ' << 1 << ' ' << 1 << ' ' << 5;
    ofstream.close();
    getOddNum(4, {1, 1, 1, 5});

    /* random tests */
    fileSimpleTestsWriter(20);

    /* limit tests */
    limitTest(false);
    limitTest(true);
}

