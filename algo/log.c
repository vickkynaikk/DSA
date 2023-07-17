#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int p,q, num;
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
    return 0;
}
