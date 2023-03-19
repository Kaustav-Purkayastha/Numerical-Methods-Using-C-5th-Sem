// By - Kaustav Purkayastha ( Gurucharan University, Silchar - @ Department of Computer Science )

/* 8. Write a C program to solve the following set of equations by Gauss-Seidal Method:
		27x + 6y - z = 85
		6x + 15y + 2z = 72
		x + y + 54z = 110	*/


#include <stdio.h>
#include <math.h>

#define N 3

// Function to solve a system of linear equations using Gauss-Seidel method
void gauss_seidel(double a[][N], double b[], double x[], int n, int max_iterations, double tolerance) {
    int i, j, k, iteration_count = 0;
    double sum, new_solution[N], error = 1.0;

    // Continue iterating until max_iterations or tolerance is reached
    while (iteration_count < max_iterations && error > tolerance) {
        // Calculate new solution for each equation
        for (i = 0; i < n; i++) {
            sum = b[i];
            for (j = 0; j < n; j++) {
                if (i != j) {
                    sum -= a[i][j] * x[j];
                }
            }
            new_solution[i] = sum / a[i][i];
        }

        // Calculate the error between old and new solutions
        error = 0.0;
        for (k = 0; k < n; k++) {
            error += fabs((new_solution[k] - x[k]) / new_solution[k]);
            x[k] = new_solution[k];
        }

        iteration_count++;
    }
}

int main() {
    double a[N][N], b[N], x[N];
    int i, j, max_iterations;
    double tolerance;

    // Get input from the user for the system of equations
    printf("Enter the coefficients of the equations:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("a[%d][%d]: ", i, j);
            scanf("%lf", &a[i][j]);
        }
    }

    printf("Enter the constants on the right-hand side:\n");
    for (i = 0; i < N; i++) {
        printf("b[%d]: ", i);
        scanf("%lf", &b[i]);
    }

    // Get the initial guess and iteration parameters from the user
    printf("Enter the initial guess for the solution:\n");
    for (i = 0; i < N; i++) {
        printf("x[%d]: ", i);
        scanf("%lf", &x[i]);
    }

    printf("Enter the maximum number of iterations: ");
    scanf("%d", &max_iterations);

    printf("Enter the tolerance for convergence: ");
    scanf("%lf", &tolerance);

    // Solve the system using Gauss-Seidel method
    gauss_seidel(a, b, x, N, max_iterations, tolerance);

    // Print the solution
    printf("The solution is:\n");
    for (i = 0; i < N; i++) {
        printf("x[%d] = %lf\n", i, x[i]);
    }

    return 0;
}

