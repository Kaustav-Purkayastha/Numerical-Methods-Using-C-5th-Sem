// By - Kaustav Purkayastha ( Gurucharan University, Silchar - @ Department of Computer Science )

// 2. Write a C program to compute the Standard Deviation.


#include <stdio.h>
#include <math.h>

#define MAX_SIZE 100

// function prototypes
float calculate_mean(int arr[], int size);
float calculate_standard_deviation(int arr[], int size, float mean);

int main() {
    int arr[MAX_SIZE], size, i;
    float mean, standard_deviation;

    // Prompt user for size of array
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Prompt user for elements of the array
    printf("Enter the elements of the array: \n");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Calculate the mean of the array
    mean = calculate_mean(arr, size);

    // Calculate the standard deviation of the array
    standard_deviation = calculate_standard_deviation(arr, size, mean);

    // Print the mean and standard deviation of the array
    printf("Mean: %f\n", mean);
    printf("Standard Deviation: %f\n", standard_deviation);

    return 0;
}

// Function to calculate the mean of an array
float calculate_mean(int arr[], int size) {
    int i;
    float sum = 0;

    // Sum all elements of the array
    for (i = 0; i < size; i++) {
        sum += arr[i];
    }

    // Divide the sum by the size of the array to get the mean
    return sum / size;
}

// Function to calculate the standard deviation of an array given the mean
float calculate_standard_deviation(int arr[], int size, float mean) {
    int i;
    float sum = 0;

    // Calculate the sum of the squares of the differences between each element of the array and the mean
    for (i = 0; i < size; i++) {
        sum += pow(arr[i] - mean, 2);
    }

    // Divide the sum by the size of the array, and take the square root to get the standard deviation
    return sqrt(sum / size);
}

