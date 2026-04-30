#include <stdio.h>

/* ODE: dy/dx = f(x, y)   — change this */
double f(double x, double y) { return x + y; }

void rk4(double x0, double y0, double h, double xn) {
    double x = x0, y = y0;
    printf("  x\t\t  y\n");
    printf("%.4f\t\t%.6f\n", x, y);

    while (x < xn - 1e-10) {
        double k1 = h * f(x,        y);
        double k2 = h * f(x + h/2,  y + k1/2);
        double k3 = h * f(x + h/2,  y + k2/2);
        double k4 = h * f(x + h,    y + k3);

        y += (k1 + 2*k2 + 2*k3 + k4) / 6.0;
        x += h;
        printf("%.4f\t\t%.6f\n", x, y);
    }
}

int main() {
    double x0 = 0.0;   /* initial x */
    double y0 = 1.0;   /* initial y (y(0) = 1) */
    double h  = 0.1;   /* step size */
    double xn = 0.5;   /* solve up to x = xn */

    printf("RK4 solution of dy/dx = x + y, y(0) = 1\n\n");
    rk4(x0, y0, h, xn);
    return 0;
}