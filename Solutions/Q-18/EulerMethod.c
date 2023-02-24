
// 18. Write a C program for solving a differential equation D[y=Power[x,3]+y,x], y(0)=1.Find y(0,2) when h=0.01 by Euler's Method.


#include <stdio.h>
#include <math.h>

// Define the function f(x, y) that we will use in the Euler's method
double f(double x, double y) {
    return x*x*x + y;
}

int main() {
    // Declare the initial values of x, y, and the step size h
    double x0, y0, x, y, h;
    
    // Prompt the user to enter the initial values of x and y
    printf("Enter the initial condition (x0, y0): ");
    scanf("%lf %lf", &x0, &y0);
    
    // Prompt the user to enter the step size h
    printf("Enter the step size h: ");
    scanf("%lf", &h);
    
    // Set the initial values of x and y
    x = x0;
    y = y0;
    
    // Use the Euler's method to approximate y at x=2
    while (x < 2) {
        y = y + h * f(x, y);
        x = x + h;
    }
    
    // Print the approximate value of y at x=2
    printf("y(%lf) = %lf\n", x, y);
    
    // End the program
    return 0;
}

