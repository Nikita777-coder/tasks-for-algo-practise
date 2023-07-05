#include "iostream"
#include "vector"

#ifndef PROJ_DECISION_H
#define PROJ_DECISION_H

extern std::vector<int> array;
extern int n;

int getMissedValue() {
    int64_t sum = (n * (n + 1)) / 2;

    for (int i = 0; i < n - 1; ++i) {
        sum -= array[i];
    }

    return sum;
}

#endif //PROJ_DECISION_H
