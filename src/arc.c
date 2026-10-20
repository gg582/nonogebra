#include <math.h>

double arc_length(double c, double s, double r) {
    if (r <= 0.0) {
        return 0.0;
    }

    if (s > 0.0) {
        double sin_quarter = sqrt(s / (2.0 * r));
        if (sin_quarter > 1.0) {
            sin_quarter = 1.0;
        }
        return 4.0 * r * asin(sin_quarter);
    }

    double sin_half = (c * 0.5) / r;
    if (sin_half > 1.0) {
        sin_half = 1.0;
    }
    return 2.0 * r * asin(sin_half);
}
