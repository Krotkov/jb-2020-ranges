//
// Created by kranya on 02.04.2020.
//

#ifndef JB_2020_RANGES_LIB_H
#define JB_2020_RANGES_LIB_H

constexpr int64_t MAX_DISTANCE = (int64_t) (1e18);

struct Point {
    int64_t x, y;

    Point() = default;

    Point(int64_t _x, int64_t _y) : x(_x), y(_y) {}

    bool operator<(const Point &other) {
        if (this->x < other.x) return true;
        return this->x == other.x && this->y < other.y;
    }
};

inline int64_t distance(const Point &a, const Point &b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int64_t getMinDistance(Point *points, size_t numSize);

#endif //JB_2020_RANGES_LIB_H
