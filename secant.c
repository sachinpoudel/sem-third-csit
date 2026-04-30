#include <stdio.h>
#include <math.h>

double f(double x) { return x*x*x - x - 2; }

double secant(double x0, double x1, double tol, int max_iter) {
    double x2, f0, f1;
    for (int i = 0; i < max_iter; i++) {
        f0 = f(x0); f1 = f(x1);
        if (fabs(f1 - f0) < 1e-12) { printf("Division by near-zero.\n"); break; }
        x2 = x1 - f1 * (x1 - x0) / (f1 - f0);
        printf("Iter %2d: x = %.8f\n", i+1, x2);
        if (fabs(x2 - x1) < tol) return x2;
        x0 = x1; x1 = x2;
    }
    return x1;
}

int main() {
    double root = secant(1.0, 2.0, 1e-8, 100);
    printf("\nRoot ≈ %.8f\n", root);
    return 0;
}