#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

struct Contact {
    char name[50];
    char phone[20];
    char email[50];
};

struct Contact contacts[MAX_CONTACTS];
int contactCount = 0;

void addContact() {
    if (contactCount >= MAX_CONTACTS) {
        printf("Contact list full!\n");
        return;
    }
    struct Contact c;
    printf("Enter name: ");
    scanf("%s", c.name);
    printf("Enter phone: ");
    scanf("%s", c.phone);
    printf("Enter email: ");
    scanf("%s", c.email);

    contacts[contactCount++] = c;
    printf("Contact added!\n");
}

void viewContacts() {
    if (contactCount == 0) {
        printf("No contacts to display!\n");
        return;
    }
    printf("\n--- Contact List ---\n");
    for (int i = 0; i < contactCount; i++) {
        printf("%d. %s | %s | %s\n", i + 1, contacts[i].name, contacts[i].phone, contacts[i].email);
    }
}

void searchContact() {
    char name[50];
    printf("Enter name to search: ");
    scanf("%s", name);
    for (int i = 0; i < contactCount; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Found: %s | %s | %s\n", contacts[i].name, contacts[i].phone, contacts[i].email);
            return;
        }
    }
    printf("Contact not found!\n");
}

void deleteContact() {
    char name[50];
    printf("Enter name to delete: ");
    scanf("%s", name);
    for (int i = 0; i < contactCount; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            for (int j = i; j < contactCount - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            contactCount--;
            printf("Contact deleted!\n");
            return;
        }
    }
    printf("Contact not found!\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Contact Book ---\n");
        printf("1: Add Contact\n");
        printf("2: View Contacts\n");
        printf("3: Search Contact\n");
        printf("4: Delete Contact\n");
        printf("5: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addContact(); break;
            case 2: viewContacts(); break;
            case 3: searchContact(); break;
            case 4: deleteContact(); break;
            case 5: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}