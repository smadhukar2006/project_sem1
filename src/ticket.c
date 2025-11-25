#include <stdio.h>
#include "ticket.h"

void showSeats(int seats[]) {
    printf("\nSeats Status (0 = Empty, 1 = Booked):\n");
    for (int i = 0; i < TOTAL_SEATS; i++) {
        printf("Seat %2d : %d\n", i + 1, seats[i]);
    }
}

void bookSeat(int seats[]) {
    int seatNo;
    printf("Enter seat number to book (1-20): ");
    scanf("%d", &seatNo);

    if (seatNo < 1 || seatNo > TOTAL_SEATS) {
        printf("❌ Invalid seat number!\n");
        return;
    }

    if (seats[seatNo - 1] == 1) {
        printf("❌ Seat already booked!\n");
        return;
    }

    seats[seatNo - 1] = 1;
    printf("✅ Seat booked successfully!\n");
}

void cancelSeat(int seats[]) {
    int seatNo;
    printf("Enter seat number to cancel (1-20): ");
    scanf("%d", &seatNo);

    if (seatNo < 1 || seatNo > TOTAL_SEATS) {
        printf("❌ Invalid seat number!\n");
        return;
    }

    if (seats[seatNo - 1] == 0) {
        printf("❌ Seat is already empty!\n");
        return;
    }

    seats[seatNo - 1] = 0;
    printf("✅ Booking canceled!\n");
}