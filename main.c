#include <stdio.h>
#include "booking_queue.h"
#include "last_minute_booking.h"
#include "custom_ticket_list.h"
#include "venue_selection.h"
#include "ticket_id_lookup.h"
#include "ticket.h"

int main() {
    Ticket t1 = {101, "Animesh"};
    enqueue(t1);
    Ticket t2 = {102, "Vedant"};
    enqueue(t2);
    Ticket processed = dequeue();
    printf("Processed Booking: %s, Ticket ID: %d\n", processed.name, processed.id);

    Ticket lt1 = {201, "Heet"};
    enqueueCircular(lt1);
    Ticket processedLM = dequeueCircular();
    printf("Processed Last Minute Booking: %s, Ticket ID: %d\n", processedLM.name, processedLM.id);

    addTicket(301, "VIP Pass");
    addTicket(302, "Standard Pass");
    displayTickets();

    VenueNode* root = NULL;
    root = insertVenue(root, 401, "Stadium A");
    root = insertVenue(root, 402, "Convention Center");
    root = insertVenue(root, 400, "Open Ground");
    printf("Venue List (Inorder Traversal):\n");
    inorderTraversal(root);

    insertTicket(501, "Gold Circle");
    insertTicket(502, "Silver Zone");
    TicketNodeLL* found = searchTicket(501);
    if (found)
        printf("Ticket Found: ID=%d, Name=%s\n", found->ticket.id, found->ticket.name);
    else
        printf("Ticket ID 501 not found.\n");

    TicketNodeLL* notFound = searchTicket(999);
    if (notFound)
        printf("Ticket Found: ID=%d, Name=%s\n", notFound->ticket.id, notFound->ticket.name);
    else
        printf("Ticket ID 999 not found.\n");

    return 0;
}
