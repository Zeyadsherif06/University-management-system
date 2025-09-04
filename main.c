#include "core.h"
#include <ctype.h>

void display() {
    printf("---Welcome to the university management system---\n");
    printf("A- Admit student\n");
    printf("B- Create a new course\n");
    printf("C- Enroll a student to a course\n");
    printf("D- Add a new Grade to an existing student\n");
    printf("E- Check if the student already exist\n");
    printf("F- Check if the course already exist\n");
    printf("G- Display all the students in the university\n");
    printf("H- Display all the courses in the university\n");
    printf("I- Get a specific grade of a student\n");
    printf("J- Get all the grades of a student\n");
    printf("K- Get the grades of all the enrolled students in a specific course\n");
    printf("L- Compute the mean and the median of the grades in a specific course\n");
    printf("M- Sort the students by grade in a course\n");
    printf("Q- Exit and Quit the program\n");
    printf("----------------------------------------------------\n");
    printf("Please enter your choice: ");
}

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

int main() {
    System heads;
    heads.head_student = NULL;
    heads.head_course = NULL;
    System* ptr_heads = &heads;

    char choice;
    int ID;
    int course_code;
    char student_name[100];
    char course_name[100];
    double grade;

    do
    {
        display();
        scanf(" %c", &choice);
        clear_input_buffer();
        choice = toupper(choice);

        if (choice == 'A') {
            printf("Enter Student ID: ");
            scanf("%d", &ID);
            clear_input_buffer();
            printf("Enter student name: ");
            fgets(student_name, sizeof(student_name), stdin);
            student_name[strcspn(student_name, "\n")] = 0;
            admit_student(ID, student_name, ptr_heads);
        }
        else if (choice == 'B') {
            printf("Enter course code: ");
            scanf("%d", &course_code);
            clear_input_buffer();
            printf("Enter course name: ");
            fgets(course_name, sizeof(course_name), stdin);
            course_name[strcspn(course_name, "\n")] = 0;
            create_course(course_code, course_name, ptr_heads);


        }
        else if (choice == 'C') {
            printf("Enter course code: ");
            scanf("%d", &course_code);
            printf("Enter student ID: ");
            scanf("%d", &ID);  
            enroll_student(course_code, ID, ptr_heads);
        }
        else if (choice == 'D') {
            printf("Enter course code: ");
            scanf("%d", &course_code);
            printf("Enter student ID: ");
            scanf("%d", &ID);
            printf("Enter student grade out of 100: ");
            scanf("%lf", &grade);
            add_grade(ID, course_code, grade, ptr_heads);
        }
        else if (choice == 'E') {
            printf("Enter student ID: ");
            scanf("%d", &ID);
            check_student(ptr_heads, ID);
        }
        else if (choice == 'F') {
            printf("Enter course code: ");
            scanf("%d", &course_code);
            check_course(ptr_heads, course_code);
        }
        else if (choice == 'G') {
            traverse_students(ptr_heads);
        }
        else if (choice == 'H') {
            traverse_courses(ptr_heads);
        }
        else if (choice == 'I') {
            printf("Enter course code: ");
            scanf("%d", &course_code);
            printf("Enter student ID: ");
            scanf("%d", &ID);
            get_grade(ID, course_code, ptr_heads);
        }
        else if (choice == 'J') {
            printf("Enter student ID: ");
            scanf("%d", &ID);
            get_grade_student(ID, ptr_heads);
        }
        else if (choice == 'K') {
            printf("Enter course code: ");
            scanf("%d", &course_code);
            Print_students_grades(ptr_heads, course_code);
        }
        else if (choice == 'L') {
                printf("Enter course code: ");
                scanf("%d", &course_code);
                calculate_average(ptr_heads, course_code);
                calculate_median(ptr_heads, course_code);
        }
        else if (choice == 'M') {
                printf("Enter course code: ");
                scanf("%d", &course_code);
                sort_students_by_grade(ptr_heads, course_code);
                Print_students_grades(ptr_heads, course_code);
        }
        else {
            printf("Invalid option. Please enter a valid option and try again.\n");
        }


    }
    while (choice != 'Q');
    cleanup(ptr_heads);
    printf("Goodbye!\n");
    return 0;
}
