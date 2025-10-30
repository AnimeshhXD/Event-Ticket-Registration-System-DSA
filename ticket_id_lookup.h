#ifndef TICKET_ID_LOOKUP_H
#define TICKET_ID_LOOKUP_H

#include "ticket.h"

#define TABLE_SIZE 10

typedef struct TicketNodeLL {
    Ticket ticket;
    struct TicketNodeLL* next;
} TicketNodeLL;

extern TicketNodeLL* hashTable[TABLE_SIZE];

int hash(int ticketID);
void insertTicket(int id, const char* name);
TicketNodeLL* searchTicket(int id);

#endif
