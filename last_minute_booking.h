#ifndef LAST_MINUTE_BOOKING_H
#define LAST_MINUTE_BOOKING_H

#include "ticket.h"

#define MAX 100

void enqueueCircular(Ticket t);
Ticket dequeueCircular();

#endif 

