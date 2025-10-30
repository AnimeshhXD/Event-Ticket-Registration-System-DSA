#ifndef CUSTOM_TICKET_LIST_H
#define CUSTOM_TICKET_LIST_H

typedef struct TicketNode {
    int ticketID;
    char ticketName[50];
    struct TicketNode* next;
} TicketNode;

void addTicket(int id, const char* name);
void displayTickets();

#endif 
