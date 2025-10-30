#include <stdio.h>
#include "booking_queue.h"
#include "last_minute_booking.h"
#include "custom_ticket_list.h"
#include "venue_selection.h"
#include "ticket_id_lookup.h"

int main() {
  
    Ticket t1 = {"Animesh", 101};
    enqueue(t1);
    Ticket t2 = {"Vedant", 102};
    enqueue(t2);
    Ticket processed = dequeue();
    printf("Processed Booking: %s, Event ID: %d\n", processed.customerName, processed.eventID);

    
    Ticket lt1 = {"Heet", 201};
    enqueueCircular(lt1);
    Ticket processedLM = dequeueCircular();
    printf("Processed Last Minute Booking: %s, Event ID: %d\n", processedLM.customerName, processedLM.eventID);

   
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
    Ticket* found = searchTicket(501);
    if (found)
        printf("Ticket Found: ID=%d, Name=%s\n", found->id, found->name);
    else
        printf("Ticket ID 501 not found.\n");

    Ticket* notFound = searchTicket(999);
    if (notFound)
        printf("Ticket Found: ID=%d, Name=%s\n", notFound->id, notFound->name);
    else
        printf("Ticket ID 999 not found.\n");

    return 0;
}
