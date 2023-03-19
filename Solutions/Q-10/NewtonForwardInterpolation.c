// By - Kaustav Purkayastha ( Gurucharan University, Silchar - @ Department of Computer Science )

/* 10. Write a C program to interpolate using Newton's Forward Interpolation Method.
		Use it to find the value of y when x = 1.05. Given:
		x:		1.0			1.1			1.2			1.3			1.4			1.5
		y:		0.24197		0.21785		0.19419		0.17137		0.14973		0.12952		*/


#include <stdio.h>

int main() {
    int n, i, j;
    printf("Enter the number of data points: ");
    scanf("%d", &n);
    double x[n], y[n];

    // read in data points for x and y
    printf("Enter the data points for x and y:\n");
    for (i = 0; i < n; i++) {
        scanf("%lf %lf", &x[i], &y[i]);
    }

    double xi;
    printf("Enter the value of x to interpolate: ");
    scanf("%lf", &xi);

    double h = x[1] - x[0]; // assume equally spaced values of x
    double p = (xi - x[0]) / h; // forward difference parameter
    double y_interp = y[0]; // initial value of y for forward interpolation

    // compute forward differences and interpolate y
    for (i = 1; i < n; i++) {
        for (j = 0; j < n-i; j++) {
            y[j] = y[j+1] - y[j];
        }
        y_interp = y_interp + p*y[i]/i;
    }

    printf("Interpolated value of y at x = %f is %f\n", xi, y_interp);

    return 0;
}

