
/* 3. Write a C program to implement the Least Square Approximation for fitting a Straight line y=mx+c, 
		where "m" is the slope and "c" is the intercept on the y-axis for data points:
    	(-1,10), (0,9), (1,7), (2,5), (3,4), (4,3), (5,0), (6,-1).	*/


#include <stdio.h>

#define MAX_SIZE 100 // maximum size of the data points array

// function to calculate the slope and intercept of the least square approximation
void least_square_approximation(float x[], float y[], int n, float *m, float *c) {
    float sum_x = 0, sum_y = 0, sum_xy = 0, sum_x2 = 0;
    int i;
    for (i = 0; i < n; i++) {
        sum_x += x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        sum_x2 += x[i] * x[i];
    }
    *m = (n * sum_xy - sum_x * sum_y) / (n * sum_x2 - sum_x * sum_x);
    *c = (sum_y - *m * sum_x) / n;
}

int main() {
    float x[MAX_SIZE], y[MAX_SIZE]; // x-coordinates and y-coordinates of data points
    int i, size; // size of the data points array
    float m, c; // slope and intercept of the least square approximation

    // get the size of the data points array from the user
    printf("Enter the number of data points: ");
    scanf("%d", &size);

    // get the x-coordinates and y-coordinates of the data points from the user
    printf("Enter the x-coordinates of the data points:\n");
    for (i = 0; i < size; i++) {
        scanf("%f", &x[i]);
    }
    printf("Enter the y-coordinates of the data points:\n");
    for (i = 0; i < size; i++) {
        scanf("%f", &y[i]);
    }

    // calculate the slope and intercept of the least square approximation
    least_square_approximation(x, y, size, &m, &c);

    // print the equation of the least square approximation
    printf("The equation of the least square approximation is: y = %fx + %f\n", m, c);

    return 0;
}

