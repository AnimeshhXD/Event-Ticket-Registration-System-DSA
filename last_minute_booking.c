#include <stdio.h>
#include <string.h>
#include "last_minute_booking.h"

Ticket cqueue[MAX];
int frontC = -1, rearC = -1;

void enqueueCircular(Ticket t) {
    if ((frontC == 0 && rearC == MAX-1) || (rearC == (frontC -1) % (MAX-1))) {
        printf("Circular Queue Full! Cannot add last minute booking.\n");
        return;
    }
    if (frontC == -1) {
        frontC = rearC = 0;
    } else if (rearC == MAX-1 && frontC != 0) {
        rearC = 0;
    } else {
        rearC++;
    }
    cqueue[rearC] = t;
    printf("Last minute booking added for %s, Ticket ID: %d\n", t.name, t.id);
}

Ticket dequeueCircular() {
    Ticket t = {-1, ""};
    if (frontC == -1) {
        printf("Circular Queue Empty! No last minute bookings.\n");
        return t;
    }
    t = cqueue[frontC];
    if (frontC == rearC) {
        frontC = rearC = -1;
    } else if (frontC == MAX-1) {
        frontC = 0;
    } else {
        frontC++;
    }
    return t;
}
