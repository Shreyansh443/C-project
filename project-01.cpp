//Bus Reservation System
#include <stdio.h>
#include <string.h>
//function to display the available seats
void displayseats(int seats[], int size){
    printf("                  SEAT AVAILABILITY                \n");
    for (int i = 0; i < 20 ; i++ ){
        if (seats[i] == 0){
            printf("Seat %2d : Available\n", i+1);
        }
        else {
            printf("Seat %2d : Unavailable\n", i+1);

        }
    
    }
    
}
//function to book a seat
void bookseat(int seats[], char names[][30], int size){
    int seatnum;
    char name[30];
    printf("Enter seat number to book (1-%d)\n", size);
    scanf("%d", &seatnum);
    
    if (seatnum < 1 || seatnum > 20){
        printf("Invalid seat number!\n");
        return;
    }
    if (seats[seatnum-1]==1){
        printf("seat %d is already booked, please choose a different seat\n", seatnum);
        return;
    }
    printf("Enter your name : ");
    scanf("%s", &name);
    seats[seatnum-1] = 1;
    strcpy(names[seatnum-1], name);
    printf("Seat %d booked successfully by %s\n", seatnum, name);
    
    }
//function to cancel a booking
void cancelseat(int seats[], char names[][30], int size){
    int seatnum;
    char name[30];
    printf("Enter seat number to cancel (1-20)\n", seatnum);
    scanf("%d", &seatnum);

    if (seatnum < 1 || seatnum > 20){
        printf("Invalid seat number!\n");
        return;
    }
    if (seats[seatnum - 1] == 0){
        printf("Seat %d is not booked yet\n", seatnum);
        return;
    }

    printf("Enter the name you used to book the seat, to confirm cancellation : ");
    scanf("%s", &name);
    if (strcmp(name, names[seatnum - 1]) == 0){
        seats[seatnum -1] = 0;
        strcpy(names[seatnum -1], "");
        printf("Seat %d booking canceled successfully.\n", seatnum);
    }
    else {
        printf("Invalid Name!. Seat was booked by someone else you cannot cancel its booking");
    }
}

int main(){
    int seats[20] = {0};
    char names[20][30] = {""};
    int choice;

    while (1){
        printf("\n      BUS RESERVATION SYSTEM        \n");
        printf("press 1. To view seat map\n");
        printf("Press 2. To bokk a seat\n");
        printf("Press 3. To cancel a booking\n");
        printf("Press 4. To exit\n");
        printf("======ENTER YOUR CHOICE=======\n");
        scanf("%d", &choice);

        switch (choice){
            case 1:
                displayseats(seats, 20);
                break;
            case 2:
                bookseat(seats, names, 20);
                printf("updated seat map :\n");
                displayseats(seats, 20);
                break;
            case 3:
                cancelseat(seats, names, 20);
                printf("Updated seat map :\n");
                displayseats(seats, 20);
                break;
            case 4:
                printf("Final seat map before exit\n");
                displayseats(seats, 20);
                printf("Thanks for using our Bus Reservation service\n");
                return 0;
            default:
                printf("Invalid choice! please enter number (1-4)\n");
        }
    }
}