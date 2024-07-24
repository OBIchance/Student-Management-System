#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100 // Defines the max number of students

// creates a student struct with an id, name, and gpa
struct student
{
    int id;
    char name[50];
    float gpa;
};

// Global Varibles
struct student students[MAX_STUDENTS]; // initializes a list of students
int num_students = 0;

// This function adds a student to the student list
void add_student()
{
    // checks if number of students in the array is more than or equal to the max number of students
    if (num_students >= MAX_STUDENTS)
    {
        // if true display error message
        printf("Maximum number of students reached\n");
        return;
    }

    // else add new student to the array
    struct student new_student; // create new student

    printf("Enter student ID: ");
    scanf("%d", &new_student.id); // read in student id

    printf("Enter student name: ");
    scanf("%s", new_student.name); // read in students name from user

    printf("Enter student GPA: ");
    scanf("%f", &new_student.gpa); // reads in student gpa from user

    students[num_students] = new_student; // saves the student to the student array
    num_students++;                       // increases the number of students

    printf("Student added successfully\n");
}

// This function removes a student for the student array
void remove_student()
{
    int id;
    printf("Enter ID of student to remove: ");
    scanf("%d", &id); // reads the student id from the user

    // searchs the student array for the student id
    int found = 0;
    for (int i = 0; i < num_students; i++)
    {
        // if student id is found remove student from the array
        if (students[i].id == id)
        {
            found = 1;
            num_students--; // decrease the number of students
            for (int j = i; j < num_students; j++)
            {
                students[j] = students[j + 1]; // replaces student information with the next students information
            }
            printf("Student removed successfully\n");
            break;
        }
    }

    // if not found display error message
    if (found == 0)
    {
        printf("Student not found\n");
    }
}

// this function displays an individual students information
void display_student()
{
    int id;
    printf("Enter ID of student to display: ");
    scanf("%d", &id); // reads the student id from the user

    // searchs the student array for the student id
    int found = 0;
    for (int i = 0; i < num_students; i++)
    {
        // if student id is found print the student information to the screen
        if (students[i].id == id)
        {
            found = 1;
            printf("ID: %d\nName: %s\nGPA: %.2f\n", students[i].id, students[i].name, students[i].gpa);
            break;
        }
    }

    // if student id is not found print error message
    if (found == 0)
    {
        printf("Student not found\n");
    }
}

// this function changes an individual students information
void modify_student()
{
    int id;
    printf("Enter ID of student to modify: ");
    scanf("%d", &id); // reads student id from the user

    // searchs the student array for the student id
    int found = 0;
    for (int i = 0; i < num_students; i++)
    {
        // if student id is found ask user what information they want to change
        if (students[i].id == id)
        {
            char input[50];
            found = 1;

            printf("Enter new student name (press / to keep existing name): ");
            scanf("\n%[^\n]", input); // reads student name from the user

            // comapares user input to see if user wants to keep existing data
            if (strcmp(input, "/") == 0)
            {
                // skips changing the name
            }
            // changes to name of the student
            else
            {
                for (int j = 0; j < strlen(input); j++)
                {
                    students[i].name[j] = input[j];
                }
            }

            printf("Enter new student GPA (press / to keep existing GPA): ");
            scanf("\n%[^\n]", input);

            // comapares user input to see if user wants to keep existing data
            if (strcmp(input, "/") == 0)
            {
                // skips changing the gpa
            }
            else
            {
                students[i].gpa = atof(input);
            }

            // prints the updated information of the student
            printf("Updated Student Information");
            printf("ID: %d\nName: %s\nGPA: %.2f\n", students[i].id, students[i].name, students[i].gpa);
            printf("Student modified successfully\n");
            break;
        }
    }

    // if student not found display error message
    if (found == 0)
    {
        printf("Student not found\n");
    }
}

// the function prints all the students to the screen
void print_students()
{
    for (int i = 0; i < num_students; i++)
    {
        printf("ID: %d\nName: %s\nGPA: %.2f\n\n", students[i].id, students[i].name, students[i].gpa);
    }
}

// This function loads the data for the output file to the program
void load_data()
{
    FILE *fp;
    fp = fopen("data.txt", "r");

    // if file can not open print error message
    if (fp == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    fscanf(fp, "%d\n", &num_students); // reads the number of students from the file

    // stores the student information from the output file to the program
    for (int i = 0; i < num_students; i++)
    {
        fscanf(fp, "%d,%[^,],%f\n", &students[i].id, students[i].name, &students[i].gpa);
    }

    printf("Data loaded successfully\n");

    // prints the student information to the screen
    print_students();
    fclose(fp);
}

// This function saves the student array to the output file
void save_data()
{
    FILE *fp;
    fp = fopen("data.txt", "w");

    // if file can not open print error message
    if (fp == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    fprintf(fp, "%d\n", num_students);

    // saves the student information from the program to the output file
    for (int i = 0; i < num_students; i++)
    {
        fprintf(fp, "%d,%s,%.2f\n", students[i].id, students[i].name, students[i].gpa);
    }

    printf("Data saved successfully\n");

    fclose(fp);
}

int main()
{
    load_data();

    while (1)
    {
        printf("\nEnter option (1=add, 2=remove, 3=display, 4=modify, 5=print, 6=exit): ");
        int option;
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            add_student();
            save_data();
            break;
        case 2:
            remove_student();
            save_data();
            break;
        case 3:
            display_student();
            break;
        case 4:
            modify_student();
            save_data();
            break;
        case 5:
            print_students();
            break;
        case 6:
            save_data();
            return 0;
        default:
            printf("Invalid option\n");
            break;
        }
    }

    return 0;
}
