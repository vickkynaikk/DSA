#include <stdio.h>
#include <stdlib.h>

typedef struct Process {
    int id;
    int timeCycle;
    struct Process* next;
} Process;

Process* createProcess(int id, int timeCycle) {
    Process* newProcess = (Process*)malloc(sizeof(Process));
    newProcess->id = id;
    newProcess->timeCycle = timeCycle;
    newProcess->next = NULL;
    return newProcess;
}

Process* insertProcess(Process* head, int id, int timeCycle) {
    Process* newProcess = createProcess(id, timeCycle);

    if (head == NULL) {
        newProcess->next = newProcess;
        return newProcess;
    }

    Process* current = head;
    while (current->next != head) {
        current = current->next;
    }

    current->next = newProcess;
    newProcess->next = head;
    return head;
}

Process* deleteProcess(Process* head, int id) {
    if (head == NULL) {
        return NULL;
    }

    if (head->id == id) {
        if (head->next == head) {
            free(head);
            return NULL;
        }

        Process* last = head;
        while (last->next != head) {
            last = last->next;
        }

        last->next = head->next;
        free(head);
        return last->next;
    }

    Process* current = head;
    Process* prev = NULL;
    while (current->id != id) {
        if (current->next == head) {
            printf("Process with ID %d not found!\n", id);
            return head;
        }
        prev = current;
        current = current->next;
    }

    prev->next = current->next;
    free(current);
    return head;
}

void displayProcesses(Process* head) {
    if (head == NULL) {
        printf("No processes in the list!\n");
        return;
    }

    Process* current = head;
    printf("Process List: ");
    do {
        printf("P%d:%d ", current->id, current->timeCycle);
        current = current->next;
    } while (current != head);
    printf("\n");
}

void executeCycle(Process** headRef) {
    Process* head = *headRef;
    if (head == NULL) {
        printf("No processes in the list!\n");
        return;
    }

    Process* current = head;
    do {
        current->timeCycle--;

        if (current->timeCycle == 0) {
            printf("Executing process P%d\n", current->id);
            *headRef = deleteProcess(head, current->id);
            head = *headRef;
            current = head;
        } else {
            current = current->next;
        }
    } while (current != head);

    printf("End of cycle\n");
}

int main() {
    Process* head = NULL;

    // Insert processes into the circular linked list
    head = insertProcess(head, 1, 1);
    head = insertProcess(head, 2, 2);
    head = insertProcess(head, 3, 3);

    // Execute the cycles
    for (int i = 1; i <= 6; i++) {
        printf("Cycle %d:\n", i);
        executeCycle(&head);
        displayProcesses(head);
        printf("\n");

        if (head == NULL) {
            printf("All processes executed!\n");
            break;
        }
    }

    // Free the memory
    Process* current = head;
    while (current != NULL) {
        Process* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
