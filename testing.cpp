//
// Created by kranya on 02.04.2020.
//

#include <iostream>
#include <algorithm>
#include <memory>
#include "lib/lib.h"

inline int64_t stupidDistance(Point *points, const size_t numSize) {
    int64_t ans = MAX_DISTANCE;
    for (size_t i = 0; i < numSize; ++i) {
        for (size_t j = i + 1; j < numSize; ++j) {
            ans = std::min(distance(points[i], points[j]), ans);
        }
    }
    return ans;
}

int main() {
    std::srand(time(nullptr));
    auto points = std::make_unique<Point[]>(2000);
    for (size_t t = 0; t < 1000; ++t) {
        int num = random() % 1000 + 2;
        for (size_t i = 0; i < num; i++) {
            int64_t a = random() % 100000, b = random() % 100000;
            points[i] = Point(a, b);
        }
        std::sort(points.get(), points.get() + num);
        int64_t ans2 = stupidDistance(points.get(), num);
        int64_t ans1 = getMinDistance(points.get(), num);
        if (ans1 != ans2) {
            std::cout << "error\n";
            std::cout << ans1 << " " << ans2 << "\n";
            for (size_t i = 0; i < num; i++) {
                std::cout << points[i].x << " " << points[i].y << "\n";
            }
            return 0;
        }
    }
    std::cout << "ok\n";
    return 0;
}