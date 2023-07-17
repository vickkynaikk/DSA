#include <stdio.h>
#include <stdlib.h>

typedef struct process {
    int id;
    int timecycle;
    struct process* next;
} process;

                                                                            // Create a new process node
process* createprocess(int id, int timecycle) {
    process* newprocess = (process*)malloc(sizeof(process));
    newprocess->id = id;
    newprocess->timecycle = timecycle;
    newprocess->next = NULL;
    return newprocess;
}

// Insert a process into the circular linked list
process* insertprocess(process* head, int id, int timecycle) {
    process* newprocess = createprocess(id, timecycle);

    if (head == NULL) {
        // If the list is empty, make the new process the head
        newprocess->next = newprocess;
        return newprocess;
    }

    process* current = head;
    while (current->next != head) {
        // Traverse to the end of the list
        current = current->next;
    }

    // Insert the new process at the end of the list
    current->next = newprocess;
    newprocess->next = head;
    return head;
}

// Delete a process from the circular linked list
process* deleteprocess(process* head, int id) {
    if (head == NULL) {
        return NULL;
    }
    if (head->id == id) {
        if (head->next == head) {
            // If the head is the only process in the list, free it and return NULL
            free(head);
            return NULL;
        }

        process* last = head;
        while (last->next != head) {
            // Find the last process in the list
            last = last->next;
        }

        // Update the last process's next pointer to skip the head
        last->next = head->next;
        free(head);
        return last->next;
    }

    process* current = head;
    process* prev = NULL;
    while (current->id != id) {
        if (current->next == head) {
            printf("Process with ID %d not found!\n", id);
            return head;
        }
        prev = current;
        current = current->next;
    }

    // Remove the current process from the list
    prev->next = current->next;
    free(current);
    return head;
}

// Display the processes in the circular linked list
void displayprocesses(process* head, FILE* file) {
    if (head == NULL) {
        fprintf(file, "No processes in the list!\n");
        return;
    }

    process* current = head;
    fprintf(file, "Process List: ");
    do {
        // Print the process ID and time cycle
        fprintf(file, "P%d:%d ", current->id, current->timecycle);
        current = current->next;
    } while (current != head);
    fprintf(file, "\n");
}

// Execute one cycle of the processes
void executeCycle(process** headRef, FILE* file) {
    process* head = *headRef;
    if (head == NULL) {
        fprintf(file, "No processes in the list!\n");
        return;
    }

    process* current = head;
    do {
        current->timecycle--;

        if (current->timecycle == 0) {
            // If the time cycle of the current process reaches 0, execute it
            fprintf(file, "Executing process P%d\n", current->id);
            *headRef = deleteprocess(head, current->id);
            head = *headRef;
            current = head;
        }
        else {
            current = current->next;
        }
    } while (current != head);
}

int main() {
    FILE* output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Unable to open the output file.\n");
        return 1;
    }

    process* head = NULL;

    // Insert processes into the circular linked list
    head = insertprocess(head, 1, 1);
    head = insertprocess(head, 2, 2);
    head = insertprocess(head, 3, 3);

    for (int i = 1; i <= 6; i++) {
        // Execute the cycles
        fprintf(output_file, "Cycle %d:\n", i);
        executeCycle(&head, output_file);
        displayprocesses(head, output_file);
        fprintf(output_file, "\n");

        if (head == NULL) {
            fprintf(output_file, "All processes executed!\n");
            break;
        }
    }

    fclose(output_file);

    process* current = head;
    while (current != NULL) {
        // Free the memory used by the processes
        process* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
