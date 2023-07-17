#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int start, end, num_ints;
    printf("Enter the start of the range: ");
    scanf("%d", &start);
    printf("Enter the end of the range: ");
    scanf("%d", &end);
    printf("Enter the number of random integers to generate: ");
    scanf("%d", &num_ints);

    // Initialize random number generator
    srand(time(NULL));

    // Generate random integers within the specified range
    int i;
    int random_ints[num_ints];
    for (i = 0; i < num_ints; i++) {
        random_ints[i] = rand() % (end - start + 1) + start;
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
    for (i = 0; i < num_ints; i++) {
        fprintf(f, "%d\n", random_ints[i]);
    }
    fclose(f);

    printf("%d random integers have been generated and saved to %s.\n", num_ints, file_name);
    return 0;
}
