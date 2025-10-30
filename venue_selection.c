#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "venue_selection.h"

VenueNode* insertVenue(VenueNode* root, int id, const char* name) {
    if (root == NULL) {
        VenueNode* newNode = (VenueNode*)malloc(sizeof(VenueNode));
        newNode->venueID = id;
        strcpy(newNode->venueName, name);
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    if (id < root->venueID)
        root->left = insertVenue(root->left, id, name);
    else if (id > root->venueID)
        root->right = insertVenue(root->right, id, name);
    return root;
}

void inorderTraversal(VenueNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("Venue ID: %d, Name: %s\n", root->venueID, root->venueName);
        inorderTraversal(root->right);
    }
}
