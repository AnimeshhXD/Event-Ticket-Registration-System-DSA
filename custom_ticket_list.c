#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "custom_ticket_list.h"

TicketNode* head = NULL;

void addTicket(int id, const char* name) {
    TicketNode* newNode = (TicketNode*)malloc(sizeof(TicketNode));
    newNode->ticketID = id;
    strcpy(newNode->ticketName, name);
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        TicketNode* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    printf("Ticket added: %s (ID: %d)\n", name, id);
}

void displayTickets() {
    TicketNode* temp = head;
    printf("Tickets List:\n");
    while (temp != NULL) {
        printf("Ticket ID: %d, Name: %s\n", temp->ticketID, temp->ticketName);
        temp = temp->next;
    }
}
