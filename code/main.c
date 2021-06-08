#include <stdio.h>

typedef double F(double, double);

const double alpha = 0.76, gamma = 0.76;
const double beta = 0.62, delta = 0.62;

void euler(
    F f1, F f2, double t, double t0, 
    double x, double y, double n
) {
    FILE *fp = fopen("results.txt", "w");
    fprintf(fp, "%f %f\n", x, y);
    double h = (t - t0) / (n + 1);
    for (int i = 0; i < n; i++) {
        double _x = x;
        x = x + h * f1(x, y);
        y = y + h * f2(_x, y);
        fprintf(fp, "%f %f\n", x, y);
    }
    fclose(fp);
}

double f1(double x, double y) {
    return (alpha - beta * y) * x;
}

double f2(double x, double y) {
    return (delta * x - gamma) * y;
}

int main() {
    const double x = 1, y = 1;
    const double t0 = 0, t = 100;
    euler(f1, f2, t, t0, x, y, 2000);
    return 0;
}

