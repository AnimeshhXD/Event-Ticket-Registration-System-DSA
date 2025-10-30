#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ticket_id_lookup.h"

Ticket* hashTable[TABLE_SIZE] = {NULL};

int hash(int ticketID) {
    return ticketID % TABLE_SIZE;
}

void insertTicket(int id, const char* name) {
    int idx = hash(id);
    Ticket* newTicket = (Ticket*)malloc(sizeof(Ticket));
    if (newTicket == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newTicket->id = id;
    strcpy(newTicket->name, name);
    newTicket->next = hashTable[idx];
    hashTable[idx] = newTicket;
    printf("Inserted ticket: ID=%d, Name=%s\n", id, name);
}


Ticket* searchTicket(int id) {
    int idx = hash(id);
    Ticket* temp = hashTable[idx];
    while (temp) {
        if (temp->id == id)
            return temp;
        temp = temp->next;
    }
    return NULL;
}
