#include <math.h>

/**
 * @brief solver for x^2 + p*x = q
 */

double solve_quadratic(double p, double q) {
    double half_p = p * 0.5;
    double abs_half_p = fabs(half_p);

    double root_term;
    if (q >= 0.0) {
        root_term = hypot(abs_half_p, sqrt(q));
    } else {
        root_term = sqrt(half_p * half_p + q);
    }

    double w = root_term + abs_half_p;

    if (p >= 0.0) {
        return (w != 0.0) ? (q / w) : 0.0;
    } else {
        return w;
    }
}
