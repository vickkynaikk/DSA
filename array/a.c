// main.c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_random_ints(int p, int q, int num, int *random_ints) {
    srand(time(NULL));
    int i;
    for (i = 0; i < num; i++) {
        random_ints[i] = rand() % (q - p + 1) + p;
    }
}

int write_to_file(char *file_name, int *random_ints, int num) {
    FILE *f = fopen(file_name, "w");
    if (f == NULL) {
        return 1;
    }
    int i;
    for (i = 0; i < num; i++) {
        fprintf(f, "%d\n", random_ints[i]);
    }
    fclose(f);
    return 0;
}

int main() {
    int p, q, num;
    printf("Enter the start of the range: ");
    scanf("%d", &p);
    printf("Enter the end of the range: ");
    scanf("%d", &q);
    printf("Enter the number of random integers to generate: ");
    scanf("%d", &num);

    int random_ints[num];
    generate_random_ints(p, q, num, random_ints);

    char file_name[50];
    printf("Enter the name of the file to save: ");
    scanf("%s", file_name);

    if (write_to_file(file_name, random_ints, num)) {
        printf("Error opening file.\n");
        return 1;
    }

    printf("%d random integers have been generated and saved to %s.\n", num, file_name);
    return 0;
}
