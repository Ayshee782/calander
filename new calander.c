#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>  // For setenv

// Checks if a year is a leap year
int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Returns the number of days in a month for a given year
int getDaysInMonth(int month, int year) {
    switch (month) {
        case 1: return 31;   // January
        case 2: return isLeapYear(year) ? 29 : 28; // February
        case 3: return 31;   // March
        case 4: return 30;   // April
        case 5: return 31;   // May
        case 6: return 30;   // June
        case 7: return 31;   // July
        case 8: return 31;   // August
        case 9: return 30;   // September
        case 10: return 31;  // October
        case 11: return 30;  // November
        case 12: return 31;  // December
        default: return 0;   // Invalid month
    }
}

// Calculates the starting day of the week for the 1st day of the month
int getStartDay(int month, int year) {
    int d = 1; // 1st day of the month
    int y = year - (14 - month) / 12;
    int m = month + 12 * ((14 - month) / 12) - 2;
    return (d + y + y/4 - y/100 + y/400 + (31*m)/12) % 7;
}

// Prints the calendar for a specified month and year
void printCalendar(int month, int year) {
    int daysInMonth = getDaysInMonth(month, year);
    int startDay = getStartDay(month, year);

    printf("\n  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    for (int i = 0; i < startDay; i++) {
        printf("     ");
    }

    for (int day = 1; day <= daysInMonth; day++) {
        printf("%4d", day);
        if ((startDay + day) % 7 == 0) {
            printf("\n");
        }
    }

    if ((startDay + daysInMonth) % 7 != 0) {
        printf("\n");
    }
}

int main() {
    int month, year;

    // Input month and year
    printf("Enter month (1-12): ");
    if (scanf("%d", &month) != 1 || month < 1 || month > 12) {
        fprintf(stderr, "Invalid month entered. Exiting.\n");
        return 1;
    }

    printf("Enter year: ");
    if (scanf("%d", &year) != 1 || year < 1) {
        fprintf(stderr, "Invalid year entered. Exiting.\n");
        return 1;
    }

    printCalendar(month, year);

    setenv("TZ", "Asia/Dhaka", 1);  // Set time zone
    tzset();

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &tm);
    printf("Current Date and Time in Bangladesh: %s\n", buffer);

    return 0;
}
