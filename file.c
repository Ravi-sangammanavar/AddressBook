#include <stdio.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook) {
  FILE *fptr = fopen("contacts.csv", "w");  // file open in write mode

    //checking file opened or not
    if (fptr == NULL)
    {
        printf("File not opened for writing\n");
        return;
    }

    fprintf(fptr, "%d\n", addressBook->contactCount);

    // Save each contact
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        fprintf(fptr, "%s,%s,%s\n",
                addressBook->contacts[i].name,
                addressBook->contacts[i].phone,
                addressBook->contacts[i].email);
    }

    fclose(fptr);  //closing file
    printf("Contacts saved successfully.\n");
}

void loadContactsFromFile(AddressBook *addressBook) {
    FILE *fptr;
    fptr=fopen("contacts.csv","r");
    if(fptr==NULL)
    {
        printf("not opened file");
        return ;
    }

    fscanf(fptr,"%d\n",&addressBook->contactCount);

    //reading contacts from file
    for(int i=0;i<addressBook->contactCount;i++)
    {
        fscanf(fptr,"%[^,],%[^,],%[^\n]\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }

    fclose(fptr);
    printf("Contacts loaded successfully.\n");
    
}
