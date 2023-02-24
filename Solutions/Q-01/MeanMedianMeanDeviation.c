
// 1. Write a C program to calculate the Mean, Median and Mean Deviation of a simple distribution.


#include <stdio.h>
#include <math.h>

// Function to sort the array
void sortArray(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = i+1; j < n; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Function to calculate the mean
float calculateMean(int arr[], int n) {
    float sum = 0;
    int i;
    for (i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum / n;
}

// Function to calculate the median
float calculateMedian(int arr[], int n) {
    sortArray(arr, n);
    if (n % 2 == 0) {
        return (arr[n/2 - 1] + arr[n/2]) / 2.0;
    } else {
        return arr[n/2];
    }
}

// Function to calculate the mean deviation
float calculateMeanDeviation(int arr[], int n) {
    float mean = calculateMean(arr, n);
    int i;
    float sum = 0;
    for (i = 0; i < n; i++) {
        sum += fabs(arr[i] - mean);
    }
    return sum / n;
}

// Main function
int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n], i;
    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Calculate and print the mean
    float mean = calculateMean(arr, n);
    printf("Mean = %f\n", mean);

    // Calculate and print the median
    float median = calculateMedian(arr, n);
    printf("Median = %f\n", median);

    // Calculate and print the mean deviation
    float mean_deviation = calculateMeanDeviation(arr, n);
    printf("Mean Deviation = %f\n", mean_deviation);

    return 0;
}

