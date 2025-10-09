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
