#include <stdio.h>

#define N 4   /* number of data points */

double lagrange(double x[], double y[], int n, double xi) {
    double result = 0.0;
    for (int i = 0; i < n; i++) {
        double term = y[i];
        for (int j = 0; j < n; j++) {
            if (j != i)
                term *= (xi - x[j]) / (x[i] - x[j]);
        }
        result += term;
    }
    return result;
}

int main() {
    double x[N] = {0, 1, 2, 3};
    double y[N] = {1, 3, 2, 5};   /* f(x) values at x points */

    double xi = 1.5;              /* interpolate at this x */
    double yi = lagrange(x, y, N, xi);
    printf("Lagrange interpolation at x = %.2f: y = %.6f\n", xi, yi);
    return 0;
}