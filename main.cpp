#include <iostream>
#include <memory>
#include <algorithm>
#include "lib/lib.h"

int main() {
    size_t n;
    std::cin >> n;
    auto points = std::make_unique<Point[]>(n);
    for (auto i = 0; i < n; i++) {
        int64_t a, b;
        std::cin >> a >> b;
        points[i] = Point(a, b);
    }
    std::sort(points.get(), points.get() + n);
    std::cout << getMinDistance(points.get(), n) << "\n";
    return 0;
}
