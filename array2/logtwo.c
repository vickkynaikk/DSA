#include <stdio.h>

#define MAX_NUMS 10000 // Maximum number of integers to read from file

void bubble_sort(int arr[], int n) {
    int temp, i, j;
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
    FILE *input_file, *output_file;
    int nums[MAX_NUMS], i, n;

    // Open input file for reading
    input_file = fopen("random.txt", "r");
    if (input_file == NULL) {
        printf("Error: Unable to open input file.\n");
        return 1;
    }

    // Read in numbers from file
    n = 0;
    while (fscanf(input_file, "%d", &nums[n]) == 1) {
        n++;
    }
    fclose(input_file);

    // Sort the numbers using bubble sort
    bubble_sort(nums, n);

    // Open output file for writing
    output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error: Unable to open output file.\n");
        return 1;
    }

    // Write sorted numbers to file
    for (i = 0; i < n; i++) {
        fprintf(output_file, "%d\n", nums[i]);
    }
    fclose(output_file);

    return 0;
}
