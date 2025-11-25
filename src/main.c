#include <stdio.h>
#include "ticket.h"

int main() {
    int seats[TOTAL_SEATS] = {0};
    int choice;

    while (1) {
        printf("\n--- SIMPLE TICKET SYSTEM ---\n");
        printf("1. Show Seats\n");
        printf("2. Book Ticket\n");
        printf("3. Cancel Ticket\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                showSeats(seats);
                break;

            case 2:
                bookSeat(seats);
                break;

            case 3:
                cancelSeat(seats);
                break;

            case 4:
                printf("Exiting...\n");
                return 0;

            default:
                printf("❌ Invalid choice!\n");
        }
    }
}