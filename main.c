/*Project Title: Address Book Management System
Name: Ravi Sangammanavar
Ad_id:25044_021
Date: 01-03-2026

Address Book Menu:
1. Create contact
2. Search contact
3. Edit contact
4. Delete contact
5. Display contacts
6. Exit

Enter your choice: 1
Enter Name: Ravi
Enter Phone: 8497064092
Enter Email: ravi@gmail.com

Contact added successfully!

Enter your choice: 5

Contact List:
Name: Ravi Phone: 8497064092 Email: ravi@gmail.com

Total Contacts: 1*/
#include <stdio.h>
#include "contact.h"
#include<unistd.h>

int main() {
    int choice,sortChoice,res;
    AddressBook addressBook;
    initialize(&addressBook); // Initialize the address book

    do {
        printf("\nAddress Book Menu:\n");
        printf("1. Create contact\n");
        printf("2. Search contact\n");
        printf("3. Edit contact\n");
        printf("4. Delete contact\n");
        printf("5. List all contacts\n");
    	printf("6. Save contacts\n");		
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                createContact(&addressBook);
                break;
            case 2:
                res=searchContact(&addressBook);
                break;
            case 3:
                res=searchContact(&addressBook);
                if(res==1)
                {
                    printf("contact not found\n");

                }
                else
                {
                    editContact(&addressBook);
                }
                break;
            case 4:
                res=searchContact(&addressBook);
                if(res==1)
                {
                    printf("contact not found\n");

                }
                else
                {
                    deleteContact(&addressBook);
                }
                break;
            case 5:          
                listContacts(&addressBook, sortChoice);
                break;
            case 6:
                printf("Saving and Exiting...\n");
                saveContactsToFile(&addressBook);
                break;
            case 7:
                for(int i = 0; i<= 100; i++)
                {
                    printf("Existing...%d%%\r",i);
                    fflush(stdout);
                    usleep(5000);
                }
                printf("\rExited successfully...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice <= 7);
    
       return 0;
}
