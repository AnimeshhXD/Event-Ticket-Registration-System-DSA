#ifndef LAST_MINUTE_BOOKING_H
#define LAST_MINUTE_BOOKING_H

#define MAX 100

typedef struct {
    char customerName[50];
    int eventID;
} Ticket;

void enqueueCircular(Ticket t);
Ticket dequeueCircular();

#endif 
