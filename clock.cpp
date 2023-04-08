#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Contact structure definition
typedef struct Contact {
    char name[50];
    char email[50];
    char phone[15];
    struct Contact *next;
} Contact;

// Function prototypes
Contact *create_contact(char *name, char *email, char *phone);
Contact *add_contact(Contact *head, Contact *new_contact);
void display_contacts(Contact *head);
void free_contacts(Contact *head);

int main() {
    Contact *head = NULL;
    Contact *new_contact = NULL;
    char name[50], email[50], phone[15];
    char choice;

    // Main menu loop
    while (true) {
        printf("\n--- Contact Manager ---\n");
        printf("1. Add contact\n");
        printf("2. Display contacts\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("\nEnter name: ");
                scanf("%s", name);
                printf("Enter email: ");
                scanf("%s", email);
                printf("Enter phone number: ");
                scanf("%s", phone);
                new_contact = create_contact(name, email, phone);
                head = add_contact(head, new_contact);
                break;
            case '2':
                display_contacts(head);
                break;
            case '3':
                free_contacts(head);
                printf("\nGoodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice!\n");
                break;
        }
    }
    return 0;
}

// Function to create a new contact
Contact *create_contact(char *name, char *email, char *phone) {
    Contact *new_contact = (Contact *)malloc(sizeof(Contact));
    strcpy(new_contact->name, name);
    strcpy(new_contact->email, email);
    strcpy(new_contact->phone, phone);
    new_contact->next = NULL;
    return new_contact;
}

// Function to add a new contact to the list
Contact *add_contact(Contact *head, Contact *new_contact) {
    if (head == NULL) {
        head = new_contact;
    } else {
        Contact *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_contact;
    }
    printf("\nContact added successfully!\n");
    return head;
}

// Function to display all contacts in the list
void display_contacts(Contact *head) {
    if (head == NULL) {
        printf("\nNo contacts found!\n");
    } else {
        printf("\nContacts:\n");
        Contact *temp = head;
        while (temp != NULL) {
            printf("%s | %s | %s\n", temp->name, temp->email, temp->phone);
            temp = temp->next;
        }
    }
}

// Function to free memory allocated to contacts
void free_contacts(Contact *head) {
    Contact *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

