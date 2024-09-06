#include <stdio.h>
int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
int getDaysInMonth(int month, int year) {
    switch (month) {
        case 1: return 31;
        case 2: return isLeapYear(year) ? 29 : 28;
        case 3: return 31;
        case 4: return 30;
        case 5: return 31;
        case 6: return 30;
        case 7: return 31;
        case 8: return 31;
        case 9: return 30;
        case 10: return 31;
        case 11: return 30;
        case 12: return 31;
        default: return 0;
    }
}
int getStartDay(int month, int year) {
    int d = 1; // Day of the month (1st day)
    int y = year - (14 - month) / 12;
    int m = month + 12 * ((14 - month) / 12) - 2;
    int startDay = (d + y + y/4 - y/100 + y/400 + (31*m)/12) % 7;
    return startDay;
}

void printCalendar(int month, int year) {
    int daysInMonth = getDaysInMonth(month, year);
    int startDay = getStartDay(month, year);

    printf("\n  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    for (int i = 0; i < startDay; i++) {
        printf("     ");
    }

    for (int day = 1; day <= daysInMonth; day++) {
        printf("%5d", day);
        if ((startDay + day) % 7 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}
int main() {
    int month, year;
    printf("Enter month (1-12): ");
    scanf("%d", &month);
    printf("Enter year: ");
    scanf("%d", &year);
    printCalendar(month, year);

    return 0;
}


