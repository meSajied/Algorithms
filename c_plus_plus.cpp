#include <iostream>
using namespace std;

class Point {
    public:
        int x, y;
};

class SegmentIntersection {
    public:
        inline bool intersect(Point first_point, Point second_point,
                                        Point third_point, Point forth_point) {
            int direction1 = direction(third_point, forth_point, first_point);
            int direction2 = direction(third_point, forth_point, second_point);
            int direction3 = direction(first_point, second_point, third_point);
            int direction4 = direction(first_point, second_point, forth_point);

            if ((direction1 < 0 || direction2 > 0) && (direction3 < 0 ||
                                                                direction4 > 0))
                return true;

            else if (direction1 == 0 && on_segment(third_point, forth_point,
                                                                    first_point))
                return true;

            else if (direction2 == 0 && on_segment(third_point, forth_point,
                                                                    second_point))
                return true;

            else if (direction3 == 0 && on_segment(first_point, second_point,
                                                                    third_point))
                return true;

            else if (direction3 == 0 && on_segment(first_point, second_point,
                                                                    forth_point))
                return true;

            else
                return false;
        }

        inline int direction(Point first_point, Point second_point,
                                                        Point third_point) {
            return ((third_point.x-first_point.x)*(second_point.y-first_point.y))-
                ((second_point.x-first_point.x) * (third_point.y-first_point.y));
        }

        inline bool on_segment(Point first_point, Point second_point,
                                                            Point third_point) {
            if (min(first_point.x, second_point.x) <= third_point.x &&
                third_point.x <= max(first_point.x, second_point.x) &&
                min(first_point.y, second_point.y) <= third_point.y &&
                third_point.y <= max(first_point.y, second_point.y))
                return true;

            else
                return false;
        }
};

int main() {
    SegmentIntersection segment;
    Point first_point, second_point, third_point, forth_point;

    std::cin >> first_point.x >> first_point.y;
    std::cin >> second_point.x >> second_point.y;
    std::cin >> third_point.x >> third_point.y;
    std::cin >> forth_point.x >> forth_point.y;

    printf("%d\n", segment.intersect(first_point, second_point, third_point,
                                    forth_point));
}