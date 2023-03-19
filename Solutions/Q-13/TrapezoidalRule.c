// By - Kaustav Purkayastha ( Gurucharan University, Silchar - @ Department of Computer Science )

// 13. Write a C program to evaluate  Integrate[Divide[x,1+x],{x,0,1}]  using Trapezoidal Rule.


#include <stdio.h>

float f(float x) {
    // Define the function to be integrated
    return x / (1 + x);
}

int main() {
    int n, i;
    float x0, xn, h, sum;

    // Get the values of x0, xn, and the number of subintervals
    printf("Enter the value of x0: ");
    scanf("%f", &x0);
    printf("Enter the value of xn: ");
    scanf("%f", &xn);
    printf("Enter the number of subintervals: ");
    scanf("%d", &n);

    // Calculate the width of each subinterval
    h = (xn - x0) / n;

    // Apply the Trapezoidal Rule
    sum = f(x0) + f(xn);
    for (i = 1; i < n; i++) {
        sum += 2 * f(x0 + i * h);
    }
    sum *= h / 2;

    // Print the result
    printf("The approximate value of the integral is: %f\n", sum);

    return 0;
}


