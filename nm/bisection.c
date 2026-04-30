#include <stdio.h>
#include <math.h>

double f(double x) {
    return x*x*x - x - 2;   /* change this function */
}

double bisection(double a, double b, double tol) {
    double mid;
    if (f(a) * f(b) >= 0) {
        printf("Invalid interval: f(a) and f(b) must have opposite signs.\n");
        return -1;
    }
    while ((b - a) / 2.0 > tol) {
        mid = (a + b) / 2.0;
        printf("mid = %.6f, f(mid) = %.6f\n", mid, f(mid));
        if (f(mid) == 0.0)
            break;
        else if (f(a) * f(mid) < 0)
            b = mid;
        else
            a = mid;
    }
    return (a + b) / 2.0;
}

int main() {
    double a = 1.0, b = 2.0, tol = 1e-6;
    double root = bisection(a, b, tol);
    printf("\nRoot ≈ %.6f\n", root);
    return 0;
}