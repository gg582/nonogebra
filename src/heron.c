#include <math.h>
#include <stdint.h>

_Bool is_triangle(double a, double b, double c) {
    if (a + b <= c) return 0;
    return 1;
}

static inline void sort3(double *a, double *b, double *c) {
    double min_ab = fmin(*a, *b);
    double max_ab = fmax(*a, *b);

    double min_bc = fmin(max_ab, *c);
    double max_bc = fmax(max_ab, *c);

    *a = fmin(min_ab, min_bc);
    *b = fmax(min_ab, min_bc);
    *c = max_bc;
}

double heron_mystyle(double a, double b, double c) {
    double scale = 1.0 / c;
    a *= scale;
    b *= scale;

    double diff = a - b;
    double sum = a + b;
    double term_c1 = (1.0 - diff) * (1.0 + diff);
    double term_c2 = (sum - 1.0) * (sum + 1.0);

    double rad = term_c1 * term_c2;
    if (rad <= 0.0) return 0.0;

    return 0.25 * sqrt(rad) * (c * c);
}

double heron_kahan(double a, double b, double c) {
    double term1 = a + (b + c);
    double term2 = c - (a - b);
    double term3 = c + (a - b);
    double term4 = a + (b - c);

    double radicand = term1 * term2 * term3 * term4;
    return 0.25 * sqrt(fmax(0.0, radicand));
}

double heron(double a, double b, double c) {
    sort3(&a, &b, &c);
    if (!is_triangle(a, b, c)) return 0.0;
    if (c > 1e75) {
        return heron_mystyle(a, b, c);
    }
    return heron_kahan(c, b, a);
}
