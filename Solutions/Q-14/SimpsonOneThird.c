
/* 14. Write a C program for integrating Simpson's One-Third Rule when the function values are given as:
		x:		0.8			0.9			1.0			1.1			1.2
		f(x):	0.71736		0.78333		0.84147		0.92314		0.96356			*/
		

#include <stdio.h>

double simpson(double a, double b, double fa, double fb, double fc, double h);

int main() {
    int n, i;
    double x[5], f[5], a, b, h, fa, fb, fc, integral;
    
    // Take input from user
    printf("Enter the number of intervals (must be even): ");
    scanf("%d", &n);
    
    printf("Enter the values of x and f(x):\n");
    for (i = 0; i < n+1; i++) {
        scanf("%lf %lf", &x[i], &f[i]);
    }
    
    // Calculate interval width
    h = (x[n] - x[0]) / n;
    
    // Calculate values at end points and mid point
    fa = f[0];
    fb = f[n];
    fc = f[n/2];
    
    // Integrate using Simpson's 1/3 rule
    integral = simpson(x[0], x[n], fa, fb, fc, h);
    
    printf("Integral of f(x) from %lf to %lf is %lf\n", x[0], x[n], integral);
    
    return 0;
}

double simpson(double a, double b, double fa, double fb, double fc, double h) {
    return (h/3) * (fa + 4*fc + fb);
}

