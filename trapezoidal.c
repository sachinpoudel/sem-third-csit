#include <stdio.h>
#include <math.h>

double f(double x) { return x * x; }   /* integrate x² from 0 to 1 = 1/3 */

/* Trapezoidal rule */
double trapezoidal(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    for (int i = 1; i < n; i++)
        sum += 2.0 * f(a + i * h);
    return (h / 2.0) * sum;
}

/* Simpson's 1/3 rule (n must be even) */
double simpsons(double a, double b, int n) {
    if (n % 2 != 0) { printf("n must be even for Simpson's rule\n"); return 0; }
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    for (int i = 1; i < n; i++)
        sum += (i % 2 == 0 ? 2.0 : 4.0) * f(a + i * h);
    return (h / 3.0) * sum;
}

int main() {
    double a = 0.0, b = 1.0;
    int n = 1000;
    printf("Trapezoidal (n=%d): %.8f\n", n, trapezoidal(a, b, n));
    printf("Simpson's   (n=%d): %.8f\n", n, simpsons(a, b, n));
    printf("Exact answer      : %.8f\n", 1.0/3.0);
    return 0;
}