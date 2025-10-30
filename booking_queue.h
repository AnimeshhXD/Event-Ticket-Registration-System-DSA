#ifndef BOOKING_QUEUE_H
#define BOOKING_QUEUE_H

#define MAX 100

typedef struct {
    char customerName[50];
    int eventID;
} Ticket;

void enqueue(Ticket t);
Ticket dequeue();

#endif 
