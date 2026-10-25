#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"
#include <ctype.h>

void listContacts(AddressBook *addressBook, int sortCriteria) 
{
    // Sort contacts based on alphabet
    Contact temp;
    for(int i=0; i<addressBook->contactCount-1; i++)
    {
        for(int j=0; j<addressBook->contactCount-i-1; j++)
        {
            if(strcmp(addressBook->contacts[j].name,addressBook->contacts[j+1].name)>0)
            {
                temp=addressBook->contacts[j];
                addressBook->contacts[j]=addressBook->contacts[j+1];
                addressBook->contacts[j+1]=temp;
            }
        }
    }

    printf("----------------------------------------------------------------\n");
    printf("|%-5s| %-10s | %-18s | %-18s \n",
       "SL.NO", "NAME", "PHONE", "EMAIL");
    printf("----------------------------------------------------------------\n");

    for(int i = 0; i < addressBook->contactCount; i++)
    {
        printf("|%d| ",i+1);
        printf("%-10s ", addressBook->contacts[i].name);
        printf("%-15s ", addressBook->contacts[i].phone);
        printf("%s\n", addressBook->contacts[i].email);
        printf("----------------------------------------------------------------\n");
    }
}

void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    ///populateAddressBook(addressBook);
    
    //Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}


void createContact(AddressBook *addressBook)
{
	/* Define the logic to create a Contacts */
    Contact temp;

    // Clear input buffer
    while (getchar() != '\n');

    int i=1;
    do{
        printf("Enter the name : ");
        scanf(" %[^\n]",temp.name);
        if(validate_name(temp.name))
        {
            i=0;
        }
        else
        printf("Invalid name\n");;
    }while(i);

    i=1;
    do{
        printf("Enter the phone : ");
        scanf("%s",temp.phone);
        if(validate_phone(temp.phone))
        {
            i=0;
        }
        else
        printf("Invalid phone\n");;
    }while(i);

    i=1;
    do{
        printf("Enter the emil address : ");
        scanf("%s",temp.email);
        if(validate_email(temp.email))
        {
            i=0;
        }
        else
        printf("Invalid email\n");
    }while(i);

    addressBook->contacts[addressBook->contactCount]=temp;
    addressBook->contactCount++;

    printf("---------------------------------\n");
    printf("contact created successfully\n");
    printf("---------------------------------\n");

    while (getchar() != '\n');

}

int searchContact(AddressBook *addressBook)
{
    /* Define the logic for search */
    int option,found=0;

    printf("1.name\n");
    printf("2.phone\n");
    printf("3.email\n");
    printf("search contact using\n");

    while (getchar() != '\n');
    scanf("%d",&option);

    switch(option)
    {
        case 1:
        char searchname[10];
        while (getchar() != '\n');
        printf("Enter the name : ");
        scanf("%[^\n]",searchname);

        //checking name already present contacts
        for(int i=0; i<addressBook->contactCount; i++)
        {
            if (strstr(addressBook->contacts[i].name, searchname)!=NULL)
            {
                printf("------------------------------------------------------------\n");
                printf("%d. Name  : %s", i+1,addressBook->contacts[i].name);
                printf(" Phone : %s", addressBook->contacts[i].phone);
                printf(" Email : %s\n", addressBook->contacts[i].email);
                printf("------------------------------------------------------------\n");

                found = 1; 
            }
        }
        if(found==0){
        printf("---------------------------------\n");
        printf("Contact not found\n");
        printf("---------------------------------\n");
        return 1;
        }
        else
        return 0;

        break;

        case 2:
        char phone[10];
        while (getchar() != '\n');

        printf("Enter the phone : ");
        scanf("%[^\n]",phone);

        //checking phone number already present in contacts
        for(int i=0; i<addressBook->contactCount; i++)
        {
            if (strcmp(addressBook->contacts[i].phone, phone) == 0)
            {
                printf("-------------------------------------------\n");
                printf("%d. Name  : %s ", i+1,addressBook->contacts[i].name);
                printf("Phone : %s ", addressBook->contacts[i].phone);
                printf("Email : %s\n", addressBook->contacts[i].email);
                printf("--------------------------------------------\n");

                found = 1;
                break; 
            }
        }
        if(found==0){
        printf("---------------------------------\n");
        printf("Contact not found\n");
        printf("---------------------------------\n");
        return 1;
        }
        else
        {
            return 0;
        }
        break;

        case 3:
        char email[20];
        while (getchar() != '\n');

        printf("Enter the email : ");
        scanf("%[^\n]",email);

        //checking email already present in email
        for(int i=0; i<addressBook->contactCount; i++)
        {
            if (strcmp(addressBook->contacts[i].email, email) == 0)
            {
                printf("----------------------------------------\n");
                printf("%d. Name  : %s ", i+1,addressBook->contacts[i].name);
                printf("Phone : %s ", addressBook->contacts[i].phone);
                printf("Email : %s\n", addressBook->contacts[i].email);
                printf("----------------------------------------\n");

                found = 1;
                break;
            }
        }
        if(found==0){
        printf("---------------------------------\n");
        printf("Contact not found\n");
        printf("---------------------------------\n");
        return 1;
        }
        else
        return 0;

        default:
        printf("---------------------------------\n");
        printf("invalid input\n");
        printf("---------------------------------\n");
        return 1;

    }
}

void editContact(AddressBook *addressBook)
{
	/* Define the logic for Editcontact */
    printf("enter the index which you want to edit\n");

    int index;
    scanf("%d",&index);

    printf("---------------------------------\n");
    printf("what you want to edit\n");
    printf("1.name\n");
    printf("2.phone\n");
    printf("3.email\n");
    printf("---------------------------------\n");

    int option;
    scanf("%d",&option);


    switch(option)
    {
        case 1:
        int i=1;
        while (getchar() != '\n');
        do{
            printf("Enter the name\n");
            scanf(" %[^\n]",addressBook->contacts[index-1].name);
            if(validate_name(addressBook->contacts[index-1].name))
            {
                i=0;
                printf("---------------------------------\n");
                printf("contact edited successfully\n");
                printf("---------------------------------\n");
                break;
            }
            else
            printf("---------------------------------\n");
            printf("Invalid name\n");
            printf("---------------------------------\n");
        }while(i);
        break;

        case 2:
        i=1;
        while (getchar() != '\n');
        do{
            printf("Enter the phone number\n");
            scanf("%s",addressBook->contacts[index-1].phone);
            if(validate_phone(addressBook->contacts[index-1].phone))
            {
                i=0;
                printf("---------------------------------\n");
                printf("contact edited successfully\n");
                printf("---------------------------------\n");
                break;
            }
            else
            printf("---------------------------------\n");
            printf("Invalid phone\n");
            printf("---------------------------------\n");
        }while(i);
        break;

        case 3:
        i=1;
        while (getchar() != '\n');
        do{
            printf("enter the email address\n");
            scanf("%s",addressBook->contacts[index-1].email);
            if(validate_email(addressBook->contacts[index-1].email))
            {
                i=0;
                printf("---------------------------------\n");
                printf("contact edited successfully\n");
                printf("---------------------------------\n");
                break;
            }
            else
            printf("---------------------------------\n");
            printf("Invalid name\n");
            printf("---------------------------------\n");
        }while(i);
        break;

        default:
        printf("---------------------------------\n");
        printf("Invalid input\n");
        printf("---------------------------------\n");

    }
    
}

void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */
    printf("enter which you want to delet\n");

    int index;
    scanf("%d",&index);

    for(int i=index-1; i<addressBook->contactCount; i++)
    {
        addressBook->contacts[i]=addressBook->contacts[i+1];
    }
    addressBook->contactCount--;
    printf("---------------------------------\n");
    printf("contact deleted successfully\n");
    printf("---------------------------------\n");
   
}
int validate_name(char temp[])
{
    //checking all character is alphabet is there or not
    for(int i=0; temp[i]!='\0'; i++)
    {
        if(!isalpha(temp[i]) && temp[i] != ' ') 
            return 0;

    }
    return 1;
}
int validate_phone(char temp[])
{
    if (strlen(temp) != 10)   //checking lenth is equal to 10
        return 0;

    for(int i=0; temp[i]!='\0'; i++) //checking all character is digit or not
    {
        if(!isdigit(temp[i]))
            return 0;

    }
    
    return 1;
}
int validate_email(char temp[])
{
    int at=0, dot=0, at_count=0;

    for (int i=0; temp[i]!='\0';i++)
    {
        if (temp[i]=='@')
        {   at=i;
            at_count++;  
        }

        if (temp[i]=='.')
            dot = i;     
    }
    if (at == 0 || at_count!=1)     //checking @ & more than 1 @ is present at first character          
        return 0;

    if (dot == 0 )    //checking . is present at first character  
        return 0;

    if (dot < at)   // checking . is present before @             
        return 0;

    if (temp[dot+1] == '\0' || temp[at + 1] == '.')  //after @ character is present or not  
        return 0;
    
    return 1;   
}

