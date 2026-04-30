#include <stdio.h>
#include <math.h>

double f(double x)  { return x*x*x - x - 2; }
double df(double x) { return 3*x*x - 1; }   /* derivative of f */

double newton_raphson(double x0, double tol, int max_iter) {
    double x = x0, fx, dfx;
    for (int i = 0; i < max_iter; i++) {
        fx  = f(x);
        dfx = df(x);
        if (fabs(dfx) < 1e-12) {
            printf("Derivative near zero, stopping.\n");
            break;
        }
        double x_new = x - fx / dfx;
        printf("Iter %2d: x = %.8f, f(x) = %.2e\n", i+1, x_new, f(x_new));
        if (fabs(x_new - x) < tol) { x = x_new; break; }
        x = x_new;
    }
    return x;
}

int main() {
    double root = newton_raphson(1.5, 1e-8, 100);
    printf("\nRoot ≈ %.8f\n", root);
    return 0;
}