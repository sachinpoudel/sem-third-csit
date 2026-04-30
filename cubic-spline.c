#include <stdio.h>
#include <stdlib.h>

void cubic_spline(double x[], double y[], int n,
                  double xi, double *yi) {
    int m = n - 1;
    double *h   = malloc(m * sizeof(double));
    double *a   = malloc(n * sizeof(double));
    double *b   = malloc(n * sizeof(double));
    double *c   = malloc(n * sizeof(double));
    double *d   = malloc(m * sizeof(double));
    double *alpha = malloc(n * sizeof(double));
    double *l   = malloc(n * sizeof(double));
    double *mu  = malloc(n * sizeof(double));
    double *z   = malloc(n * sizeof(double));

    for (int i = 0; i < m; i++) h[i] = x[i+1] - x[i];
    for (int i = 0; i < n; i++) a[i] = y[i];

    alpha[0] = alpha[m] = 0;
    for (int i = 1; i < m; i++)
        alpha[i] = (3/h[i])*(a[i+1]-a[i]) - (3/h[i-1])*(a[i]-a[i-1]);

    l[0] = 1; mu[0] = z[0] = 0;
    for (int i = 1; i < m; i++) {
        l[i]  = 2*(x[i+1]-x[i-1]) - h[i-1]*mu[i-1];
        mu[i] = h[i] / l[i];
        z[i]  = (alpha[i] - h[i-1]*z[i-1]) / l[i];
    }
    l[m] = 1; z[m] = c[m] = 0;

    for (int j = m-1; j >= 0; j--) {
        c[j] = z[j] - mu[j]*c[j+1];
        b[j] = (a[j+1]-a[j])/h[j] - h[j]*(c[j+1]+2*c[j])/3;
        d[j] = (c[j+1]-c[j]) / (3*h[j]);
    }

    /* evaluate at xi */
    *yi = 0;
    for (int i = 0; i < m; i++) {
        if (xi >= x[i] && xi <= x[i+1]) {
            double t = xi - x[i];
            *yi = a[i] + b[i]*t + c[i]*t*t + d[i]*t*t*t;
            break;
        }
    }
    free(h); free(a); free(b); free(c); free(d);
    free(alpha); free(l); free(mu); free(z);
}

int main() {
    double x[] = {0, 1, 2, 3, 4};
    double y[] = {0, 0.8415, 0.9093, 0.1411, -0.7568}; /* sin(x) */
    int n = 5;
    double xi = 2.5, yi;
    cubic_spline(x, y, n, xi, &yi);
    printf("Cubic spline at x=%.2f: y = %.6f\n", xi, yi);
    printf("Actual sin(2.5)       : y = %.6f\n", 0.5985);
    return 0;
}