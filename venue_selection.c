#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct VenueNode {
    int venueID;
    char venueName[50];
    struct VenueNode* left;
    struct VenueNode* right;
} VenueNode;

VenueNode* insertVenue(VenueNode* root, int id, const char* name) {
    if (root == NULL) {
        VenueNode* newNode = (VenueNode*)malloc(sizeof(VenueNode));
        if (!newNode) {
            printf("Memory allocation failed\n");
            return NULL;
        }
        newNode->venueID = id;
        strcpy(newNode->venueName, name);
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    if (id < root->venueID)
        root->left = insertVenue(root->left, id, name);
    else if (id > root->venueID)
        root->right = insertVenue(root->right, id, name);
    else
        printf("Venue ID %d already exists.\n", id);
    return root;
}

void inorderTraversal(VenueNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("Venue ID: %d, Name: %s\n", root->venueID, root->venueName);
        inorderTraversal(root->right);
    }
}
