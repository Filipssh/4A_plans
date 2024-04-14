#ifndef INC_4A_PLANS_PLANS_H
#define INC_4A_PLANS_PLANS_H

struct Line {
    double x1{},x2{},y1{},y2{};
    int cross = 0;
};

class Plans{
private:
    static bool outOfOrder(const double *a);
    static int intersect(Line line1, Line line2);
public:
    static int parsefile(const std::string& filename);
};

#endif //INC_4A_PLANS_PLANS_H
