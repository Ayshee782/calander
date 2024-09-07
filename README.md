# Calendar Program
## Overview
This project is a simple calendar program written in C. It allows users to input a month and a year to print the calendar for that month, and also displays the current date and time in the "Asia/Dhaka" time zone.

## Features
- Print a calendar for a specified month and year.
- Display the current date and time in the "Asia/Dhaka" time zone.

## How to Use
1. **Compile the Program:**
```console
gcc new\ calander.c -o calendar
```
2. **Run the Program:**
```
./calendar
```
3. **Enter the Month and Year:**
- Enter the month as an integer between 1 and 12.
- Enter the year as a positive integer.

## Example Output
```console
User@Github:~$ ./calendar
Enter month (1-12): 1
Enter year: 2040

  Sun  Mon  Tue  Wed  Thu  Fri  Sat
    1    2    3    4    5    6    7
    8    9   10   11   12   13   14
   15   16   17   18   19   20   21
   22   23   24   25   26   27   28
   29   30   31
Current Date and Time in Bangladesh: 2024-09-08 03:37:23
```

## To-Do List
1. **Enhance Input Validation:** [DONE]
- Ensure proper error handling for invalid month and year inputs.
2. **Improve Calendar Display:** [DONE]
- Adjust spacing and alignment for better visual presentation.
3. **Add Command-Line Arguments:**
- Allow users to specify the month and year via command-line arguments instead of interactive input.
4. **Time Zone Configuration:**
- Add functionality to allow users to specify a different time zone.
5. **Localization:**
- Support for different locales and languages for displaying the calendar.
6. **Documentation:** [DONE]
Add detailed comments and documentation to the code.

## Contributing
Feel free to fork this repository, make improvements, and submit pull requests. Your contributions are welcome!
