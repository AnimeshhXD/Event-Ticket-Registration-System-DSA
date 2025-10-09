#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TicketNode {
    int ticketID;
    char ticketName[50];
    struct TicketNode* next;
} TicketNode;

TicketNode* head = NULL;

void addTicket(int id, const char* name) {
    TicketNode* newNode = (TicketNode*)malloc(sizeof(TicketNode));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return;
    }
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
    printf("Ticket List:\n");
    while (temp != NULL) {
        printf("Ticket ID: %d, Name: %s\n", temp->ticketID, temp->ticketName);
        temp = temp->next;
    }
}
