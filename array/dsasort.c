#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    // Seed the random number generator
    srand(time(NULL));
    FILE *fp;
    // Generate 100 random numbers between 1 and 100
    int numbers[100];
    int i;
    for (i = 0; i < 100; i++) {
        numbers[i] = rand() % 100 + 1;
    }

    // Save the numbers to a file
    FILE *file = fopen("numbers.txt", "w");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    for (i = 0; i < 100; i++) {
        fprintf(file, "%d ", numbers[i]);
    }
    fclose(file);

    // Sort the numbers using bubble sort
    clock_t start_time = clock();
    bubble_sort(numbers, 100);
    clock_t end_time = clock();

    // Display the sorted numbers and the time taken to sort them
    printf("Sorted numbers:\n");
    for (i = 0; i < 100; i++) {
        printf("%d ", numbers[i]);
        fp= fopen("sort.txt", "w+");
    }

    printf("\nTime taken to sort: %f seconds\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);

    return 0;
}
