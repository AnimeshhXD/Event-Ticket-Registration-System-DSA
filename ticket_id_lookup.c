#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ticket_id_lookup.h"

TicketNodeLL* hashTable[TABLE_SIZE] = {NULL};

int hash(int ticketID) {
    return ticketID % TABLE_SIZE;
}

void insertTicket(int id, const char* name) {
    int idx = hash(id);
    TicketNodeLL* newTicket = (TicketNodeLL*)malloc(sizeof(TicketNodeLL));
    newTicket->ticket.id = id;
    strcpy(newTicket->ticket.name, name);
    newTicket->next = hashTable[idx];
    hashTable[idx] = newTicket;
    printf("Inserted ticket: ID=%d, Name=%s\n", id, name);
}

TicketNodeLL* searchTicket(int id) {
    int idx = hash(id);
    TicketNodeLL* temp = hashTable[idx];
    while (temp) {
        if (temp->ticket.id == id)
            return temp;
        temp = temp->next;
    }
    return NULL;
}
