#include <math.h>
#include <stdint.h>
#include <assert.h>

_Bool is_triangle(double a, double b, double c) {
    if(a+b <= c) return 0;
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

// heavily tuned Qin Jiushao style
double heron_mystyle(double a, double b, double c) {
    double inv_h = 1.0 / c;
    double h2 = c * c;

    a *= inv_h;
    b *= inv_h;
    c = 1.0;

    double a2 = a*a;
    double b2 = b*b;
    // 1.0 * 1.0 == 1.0
    // c2 is not necessary.
    // c2 == c

    double t = 0.25 * (a2 + c - b2);
    // c == 1.0
    double half_ac = a * 0.5;

    double l = half_ac - t;
    double r = half_ac + t;
    double rad = l * r;

    double area = sqrt(rad <= 0.0 ? 0.0 : rad);

    area *= h2;
    return area;
}

double heron_kahan(double a, double b, double c) {
    double term1 = c + (b + a);
    double term2 = a - (c - b);
    double term3 = a + (c - b);
    double term4 = c + (b - a);

    double radicand = term1 * term2 * term3 * term4;
    return 0.25 * sqrt(fmax(0.0, radicand));
}

double heron(double a, double b, double c) {
    sort3(&a, &b, &c);
    if (c > 1e75) {
        return heron_mystyle(a, b, c);
    }
    return heron_kahan(c, b, a);
}
