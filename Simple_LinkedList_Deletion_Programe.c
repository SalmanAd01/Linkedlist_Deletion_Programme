#include <stdio.h>
int LINK[20];         //lt represent the data in the node
int LIST[20];         //represent the pointer which gonna point to another node
int PTR;              //to track the pointer
int START;            //where to start the list
int location(int num) //to get the position of that number in link
{
    PTR = START;
    int l = -2;
    while (PTR != -1)
    {
        if (num == LIST[PTR])
        {
            l = PTR;
            break;
        }
        else
        {
            PTR = LINK[PTR];
        }
    }

    return (l);
}
int findk(int num) //to find which pointer was pointing to inputed number
{
    int loc;
    PTR = START;
    while (PTR != -1)
    {
        if (LINK[PTR] == num)
        {
            loc = PTR;
            return (loc);
        }
        else
        {

            PTR = LINK[PTR];
        }
    }

    return (loc);
}
int checkitsemptyorfull(int num) //to check if the position entered by the user contain any element or not
{
    int check;
    PTR = START;

    while (PTR != -1)
    {

        if (LINK[num] && (LINK[0] || LINK[2] || LINK[3] || LINK[5] || LINK[7] || LINK[8] || LINK[9] || LINK[11] || LINK[13] || LINK[14] || LINK[16] || LINK[18]))
        {

            check = 1;
            break;
        }
        else
        {
            check = -1;
        }
        PTR = LINK[PTR];
    }

    return (check);
}
int main()
{
    int num;      //to get the number from the user for which the opretions are gonna performed
    int loc;      //to store the location
    int l;        //to store the old link which we gonna need to perform case number 1
    int choice;   //to store the choice of the store which we gonna use in switch case statements
    int new;      //to store the number present in the list which we gonna use in replace case
    int present;  //for checking if number is present in the list or not (replace case)
    int previous; //to store pointer position which was pointed befor the inputed number which gonna furthr use for deletion
    LIST[0] = 22;
    LIST[2] = 5;
    LIST[3] = 19;
    LIST[5] = 87;
    LIST[7] = 29;
    LIST[8] = 79;
    LIST[9] = 33;
    LIST[11] = 2;
    LIST[13] = 50;
    LIST[14] = 8;
    LIST[16] = 55;
    LIST[18] = 99;
    LINK[0] = 3;
    LINK[2] = 13;
    LINK[3] = 2;
    LINK[5] = 8;
    LINK[7] = 14;
    LINK[8] = 9;
    LINK[9] = 18;
    LINK[11] = 16;
    LINK[13] = 5;
    LINK[14] = -1;
    LINK[16] = 0;
    LINK[18] = 7;
    START = 11;
    PTR = START;
    printf("\nTHE LIST IS GIVEN BY\n"); //to print the originoal link list
    while (PTR != -1)
    {
        printf("%d\t", LIST[PTR]);
        PTR = LINK[PTR];
    }
    PTR = START;
    printf("WELCOME TO THE DELETION OF THE LINKED LIST PRORAMME\n");
    printf("ENTER 1 IF YOU WANTED TO DELETE BY TYPING NUMBER FROM THE LIST\n");
    printf("ENTER 2 IF YOU WANTED TO DELETE BY TYPING IT'S POSITION\n");
    scanf("%d", &choice);
    switch (choice) //to execute the cndition
    {
    case 1:
        printf("Enter the number that you wanted to delete from the given linked list\n");
        scanf("%d", &num);
        present = location(num);
        if (present == -2)
        {
            printf("The number that you have entered is not on the list\n");
            loc = -1;
        }
        else
        {
            l = LINK[present];
            previous = findk(present);
            LINK[previous] = l;
            PTR = START;
            loc = 1;
        }

        break;
    case 2:
        printf("ENTER THE POSITION THAT YOU WANTED TO DELETE FROM THE LIST\n");
        scanf("%d", &num);
        present = checkitsemptyorfull(num);
        if (present == -1)
        {
            printf("THE POSITION IS INVALID\n");
            loc = -1;
        }
        else
        {
            l = LINK[num];
            previous = findk(num);
            LINK[previous] = l;
            PTR = START;
            loc = 1;
        }

        break;

    default:
        printf("YOU HAVE ENTERD THE INVALID OPTION\n");
        loc = -1;
        break;
    }
    if (loc != -1)
    {
        printf("THE LIST AFTER DELETING A NUMER IS GIVEN BY\n");
        while (PTR != -1)
        {
            printf("%d\t", LIST[PTR]);
            PTR = LINK[PTR];
        }
    }

    return 0;
}