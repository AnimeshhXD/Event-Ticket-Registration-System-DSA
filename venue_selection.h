#ifndef VENUE_SELECTION_H
#define VENUE_SELECTION_H

typedef struct VenueNode {
    int venueID;
    char venueName[50];
    struct VenueNode* left;
    struct VenueNode* right;
} VenueNode;

VenueNode* insertVenue(VenueNode* root, int id, const char* name);
void inorderTraversal(VenueNode* root);

#endif 
