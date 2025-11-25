#include <stdio.h>
 int main() {
    int seats[20] = {0};
    int choice, seatNo, seatcn;

    while(1){
        printf("\n---SIMPLE TICKET SYSTEM---\n");
        printf("1. Show Seats\n");
        printf("2. Book Ticket\n");
        printf("3. Cancel Ticket\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice){

            case 1:
            printf("\nSeats Status (0 = Empty, 1 = Booked):\n");
            for(int i = 0; i < 10; i++){
            printf("Seat %d : %d\n", i+1, seats[i]);
            }
            break;

            case 2:
            printf("Enter seat number to book (1-20):");
            scanf("%d", &seatNo);

            if(seatNo < 1 || seatNo > 10)
            printf("Invalid seat number!\n");
            else if(seats[seatNo-1] == 1)
            printf("Seat already booked!\n");
            else{
            seats[seatNo-1] = 1;
            printf("Seat Booked successfully!\n");
            }
            break;

            case 3:
            printf("Enter seat number to cancel (1-20): ");
            scanf("%d", &seatcn);

            if(seatNo < 1 || seatNo > 20){
            printf("Invalid seat number!\n");}
            else if(seats[seatNo-1] == 0){
            printf("Seat is already empty!\n");}
            else{
            seats[seatNo-1] = 0;
            printf("Booking cancelleed!\n");
            }

            break;
    
            case 4:
            printf("Exiting...\n");
            return 0;

            default:
            printf("Invalid choice!\n");
        }
    }
}