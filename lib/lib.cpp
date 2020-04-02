//
// Created by kranya on 02.04.2020.
//

#include <vector>
#include <algorithm>
#include <cmath>
#include "lib.h"

int64_t getMinDistance(Point *points, size_t numSize) {
    if (numSize == 1) return MAX_DISTANCE;
    size_t mid = numSize / 2;
    int64_t xLine = points[mid - 1].x;
    int64_t curDist = std::min(getMinDistance(points, mid), getMinDistance(points + mid, numSize - mid));
    auto rootDist = (int64_t) (std::sqrt(curDist)) + 1;
    std::vector<Point> rightSide;
    std::copy_if(points + mid, points + numSize, std::back_inserter(rightSide),
                 [xLine, rootDist](const Point &a) { return a.x - xLine <= rootDist; });
    size_t p = 0;
    for (auto point = points; point < points + mid; ++point) {
        while (p < rightSide.size() && rightSide[p].y < point->y - rootDist) ++p;
        for (auto j = p; j < rightSide.size() && rightSide[p].y < point->y + rootDist; ++j) {
            curDist = std::min(curDist, distance(*point, rightSide[j]));
        }
    }
    std::inplace_merge(points, points + mid, points + numSize,
                       [](const Point &a, const Point &b) { return a.y <= b.y; });
    return curDist;
}