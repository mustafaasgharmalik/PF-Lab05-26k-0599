/*
 * Course: CL1002 - Programming Fundamentals
 * Lab 05 Home Tasks - Question 2: University Examination Result Processing System
 * Description: Evaluates examination performance for students across four academic
 *              departments. Uses switch statement, logical operators (&&, ||),
 *              conditional operators (?:), and the modulus operator (%), without loops.
 */

#include <stdio.h>

int main(void) {
    int deptChoice = 0;
    int theoryMarks = 0;
    int practicalMarks = 0;
    float attendance = 0.0f;

    int minTheory = 0;
    int minPractical = 0;
    float minAttendance = 0.0f;
    const char *deptName = "";
    int validDepartment = 1;

    printf("===================================================\n");
    printf("   UNIVERSITY EXAMINATION RESULT PROCESSING SYSTEM \n");
    printf("===================================================\n");

    printf("Select Department:\n");
    printf("1. Computer Science (CS)\n");
    printf("2. Electrical Engineering (EE)\n");
    printf("3. Business Administration (BA)\n");
    printf("4. Mathematics (MATH)\n");
    printf("Enter choice (1-4): ");
    if (scanf("%d", &deptChoice) != 1) {
        printf("Error: Invalid input.\n");
        return 1;
    }

    // Switch statement to set department-specific criteria
    switch (deptChoice) {
        case 1:
            deptName = "Computer Science";
            minTheory = 50;
            minPractical = 40;
            minAttendance = 75.0f;
            break;
        case 2:
            deptName = "Electrical Engineering";
            minTheory = 55;
            minPractical = 45;
            minAttendance = 75.0f;
            break;
        case 3:
            deptName = "Business Administration";
            minTheory = 50;
            minPractical = 35;
            minAttendance = 80.0f;
            break;
        case 4:
            deptName = "Mathematics";
            minTheory = 60;
            minPractical = 40;
            minAttendance = 75.0f;
            break;
        default:
            validDepartment = 0;
            deptName = "Unknown Department";
            break;
    }

    if (!validDepartment) {
        printf("\nError: Invalid department selected. Exiting.\n");
        return 1;
    }

    printf("\nEnter Theory Examination Marks (0-100): ");
    if (scanf("%d", &theoryMarks) != 1) {
        printf("Error: Invalid marks.\n");
        return 1;
    }

    printf("Enter Practical Examination Marks (0-100): ");
    if (scanf("%d", &practicalMarks) != 1) {
        printf("Error: Invalid marks.\n");
        return 1;
    }

    printf("Enter Student Attendance Percentage (0-100): ");
    if (scanf("%f", &attendance) != 1) {
        printf("Error: Invalid attendance.\n");
        return 1;
    }

    // Check department-specific passing conditions using logical operators
    int isPassed = (theoryMarks >= minTheory) &&
                   (practicalMarks >= minPractical) &&
                   (attendance >= minAttendance);

    // Distinction check: Theory >= 85, Practical >= 80, Attendance >= 90%
    int isDistinction = (theoryMarks >= 85) &&
                        (practicalMarks >= 80) &&
                        (attendance >= 90.0f);

    // Seat category calculation using modulus operator (%) on theory marks
    int seatRemainder = theoryMarks % 3;
    char seatCategory = ' ';
    switch (seatRemainder) {
        case 0:
            seatCategory = 'A';
            break;
        case 1:
            seatCategory = 'B';
            break;
        case 2:
            seatCategory = 'C';
            break;
        default:
            seatCategory = 'X';
            break;
    }

    // Display final comprehensive report
    printf("\n===================================================\n");
    printf("           OFFICIAL EXAMINATION REPORT             \n");
    printf("===================================================\n");
    printf("Selected Department       : %s\n", deptName);
    printf("Theory Marks Obtained     : %d\n", theoryMarks);
    printf("Practical Marks Obtained  : %d\n", practicalMarks);
    printf("Attendance Percentage     : %.2f%%\n", attendance);
    printf("---------------------------------------------------\n");
    printf("Applicable Passing Criteria:\n");
    printf("  - Minimum Theory Marks  : %d\n", minTheory);
    printf("  - Minimum Practical     : %d\n", minPractical);
    printf("  - Minimum Attendance    : %.0f%%\n", minAttendance);
    printf("---------------------------------------------------\n");

    // Conditional operators used for concise output formatting
    printf("Seat Category Assigned    : Seat Category %c\n", seatCategory);
    printf("Distinction Eligibility   : %s\n",
           isDistinction ? "Eligible for Distinction" : "Not Eligible for Distinction");
    printf("Final Examination Result  : %s\n",
           isPassed ? "PASSED" : "FAILED");
    printf("===================================================\n");

    return 0;
}
