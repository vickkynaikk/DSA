#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMS 1000 // Maximum number of integers to read from file

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }

    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void selectionSort(int arr[], int n) {
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

int main() {
    int p, q, num;
    printf("Enter the start of the range: ");
    scanf("%d", &p);
    printf("Enter the end of the range: ");
    scanf("%d", &q);
    printf("Enter the number of random integers to generate: ");
    scanf("%d", &num);

    // Initialize random number generator
    srand(time(NULL));

    // Generate random integers within the specified range
    int i;
    int random_ints[num];
    for (i = 0; i < num; i++) {
        random_ints[i] = rand() % (q - p + 1) + p;
    }

    // Get user input for file name to save the list of random integers
    char file_name[50];
    printf("Enter the name of the file to save: ");
    scanf("%s", file_name);

    // Save the list of random integers to the specified file
    FILE *f = fopen(file_name, "w");
    if (f == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    for (i = 0; i < num; i++) {
        fprintf(f, "%d\n", random_ints[i]);
    }
    fclose(f);

    printf("%d random integers have been generated and saved to %s.\n", num, file_name);

    FILE *input_file, *output_file;
    int nums[MAX_NUMS], n;

    // Open input file for reading
    input_file = fopen(file_name, "r");
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
    bubbleSort(nums, n);

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

    FILE *inputFile;
    FILE *logFile;

    char *inputFileName = file_name;
    char *logFileName = "logfile.txt";

    logFile = fopen(logFileName, "w");

    for (n = 100; n <= 1000; n += 100) {
        int arr[n];

        inputFile = fopen(inputFileName, "r");
        for (i = 0; i < n; i++) {
            fscanf(inputFile, "%d", &arr[i]);
        }
        fclose(inputFile);

        clock_t start, end;
        double cpu_time_used;

        start = clock();
        bubbleSort(arr, n);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        fprintf(logFile, "Bubble Sort\t\t, n = %d\t, Time taken = %f\n", n, cpu_time_used);

        start = clock();
        mergeSort(arr, 0, n - 1);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        fprintf(logFile, "Merge Sort\t\t, n = %d\t, Time taken = %f\n", n, cpu_time_used);

        start = clock();
        selectionSort(arr, n);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        fprintf(logFile, "Selection Sort\t\t, n = %d\t, Time taken = %f\n", n, cpu_time_used);
    }

    fclose(logFile);

    return 0;
}
