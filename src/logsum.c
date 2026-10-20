#include <math.h>

double log_sum_exp(const double *x, int n) {
    if (n <= 0) {
        return 0.0;
    }

    double sum_val = 0.0;
    for (int i = 0; i < n; i++) {
        sum_val += x[i];
    }
    double mean_val = sum_val / n;

    double shifted_exp_sum = 0.0;
    for (int i = 0; i < n; i++) {
        shifted_exp_sum += exp(x[i] - mean_val);
    }

    return mean_val + log(shifted_exp_sum);
}
