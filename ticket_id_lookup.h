#ifndef TICKET_ID_LOOKUP_H
#define TICKET_ID_LOOKUP_H

#define TABLE_SIZE 10

typedef struct Ticket {
    int id;
    char name[50];
    struct Ticket* next;
} Ticket;

extern Ticket* hashTable[TABLE_SIZE];

int hash(int ticketID);
void insertTicket(int id, const char* name);
Ticket* searchTicket(int id);

#endif 
