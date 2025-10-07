#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct {
    char customerName[50];
    int eventID;
} Ticket;

Ticket queue[MAX];
int front = -1, rear = -1;

void enqueue(Ticket t) {
    if (rear == MAX - 1) {
        printf("Queue Full! Cannot add more bookings.\n");
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = t;
    printf("Booking added for %s, Event ID: %d\n", t.customerName, t.eventID);
}

Ticket dequeue() {
    Ticket t = {"", -1};
    if (front == -1 || front > rear) {
        printf("Queue Empty! No bookings to process.\n");
        return t;
    }
    t = queue[front++];
    printf("Booking processed: %s, Event ID: %d\n", t.customerName, t.eventID);
    return t;
}

int main() {
    int choice;
    while (1) {
        printf("\n Booking Queue \n");
        printf("1. Enqueue Booking\n2. Dequeue Booking\n3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            Ticket t;
            printf("Enter Customer Name: ");
            scanf(" %[^\n]", t.customerName);
            printf("Enter Event ID: ");
            scanf("%d", &t.eventID);
            enqueue(t);
        } else if (choice == 2) {
            dequeue();
        } else if (choice == 3) {
            break;
        } else {
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
