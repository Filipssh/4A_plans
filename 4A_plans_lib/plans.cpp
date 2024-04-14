#include <string>
#include <fstream>
#include "plans.h"

// Finds the index of the two smallest elements in array and outputs true, if they are not in the same half
// Used to check if two collinear lines are overlapping by looking at the order of points on projections to X and Y axes.
bool Plans::outOfOrder(const double *a){
    int id1=0,id2=1 - (a[1] < a[0]);
    for(int i=1;i<4;i++){
        if(a[i] < a[id1]) {
            id2 = id1;
            id1 = i;
        }else if(a[i] < a[id2])
            id2 = i;
    }
    return (id1<=1 != id2<=1);
}

int Plans::intersect(Line line1, Line line2) {
    // Get dot products to determine how the lines are oriented to each other
    double p0 = (line2.y2-line2.y1)*(line2.x2-line1.x1) - (line2.x2-line2.x1)*(line2.y2-line1.y1);
    double p1 = (line2.y2-line2.y1)*(line2.x2-line1.x2) - (line2.x2-line2.x1)*(line2.y2-line1.y2);
    double p2 = (line1.y2-line1.y1)*(line1.x2-line2.x1) - (line1.x2-line1.x1)*(line1.y2-line2.y1);
    double p3 = (line1.y2-line1.y1)*(line1.x2-line2.x2) - (line1.x2-line1.x1)*(line1.y2-line2.y2);

    // If lines are collinear
    if(p0 == 0 && p1 == 0 && p2 == 0 && p3 == 0){
        double X[4] = {line1.x1,line1.x2,line2.x1,line2.x2};
        double Y[4] = {line1.y1,line1.y2,line2.y1,line2.y2};
        // Check for overlap, throw an error if there is one
        if (outOfOrder(X) || outOfOrder(Y)) return -1;
    }
    return (p0*p1 <= 0) && (p2*p3 <= 0);
}


int Plans::parsefile(const std::string& filename){
    int n;
    double x1,y1,x2,y2;
    std::ifstream fin(filename);
    if (!fin.is_open()) return 4;
    // Set up
    fin >> n >> x1 >> y1;
    if(n < 3) return 1;
    Line lines[n];
    int i = 0;
    // Read n points line-by-line
    while(i++ < n){
        if (i<n) {
            if (fin.eof()) return 1;
            fin >> x2 >> y2;
        }
        else {x2 = lines[0].x1; y2 = lines[0].y1;} // On last input, connect last and first point of all input
        if (x1 == x2 && y1 == y2) return 2; // Deny lines starting and ending at the same point
        lines[i-1] = {x1,x2,y1,y2};
        for (int j=0; j<i-1;j++){
            // Check for crossing lines
            const int intersected = intersect(lines[j], lines[i-1]);
            if(intersected == -1) return 5;
            if(intersected == 1) {
                lines[j].cross++;
                lines[i-1].cross++;
                // Two lines connecting at the endpoints is detected as them crossing, but allowed for max 2 times per line
                if (lines[j].cross > 2 || lines[i-1].cross > 2) return 3;
            }
        }
        x1 = x2;
        y1 = y2;
    }
    fin.close();
    return 0;
}