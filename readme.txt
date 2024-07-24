
Welcome to Student Management System

This code is a C application that manages a student record.

To compile this code, execute the command gcc main.c in our terminal, followed by./a.out. The software will then print the data and the command.


The application allows users to add, remove, modify, and display student information from a list.


1. Add a student
2. Remove a student
3. Display a student
4. Modify a student
5. Print all students
6. Exit

If the user chooses 1, they will be required to provide the student's id, name, and grade point average. The student will be added to the list by the program. 
If the user chooses option 2, they will be asked to input the student's id. If the id is found, the software will remove the student from the list.
If the user selects 3, they will be prompted to enter the student's id. The program will display the student's information if the id is found.
If the user chooses 4, he or she will be required to input the student's id. The program will prompt the user to enter the information they wish to modify. The user has the option of keeping the existing data or entering new information. If the ID is found, the software will update the student's information.
If the user chooses option 5, the application will print all of the student's data to the screen.
If the user selects 6, the program will exit.

Example:

Enter option (1=add, 2=remove, 3=display, 4=modify, 5=print, 6=exit):  1

Enter student ID: 1
Enter student name: John
Enter student GPA: 3.5
Student added successfully

Enter option (1=add, 2=remove, 3=display, 4=modify, 5=print, 6=exit):  3

Enter student ID: 1
ID: 1
Name: John 
GPA: 3.50

Enter option (1=add, 2=remove, 3=display, 4=modify, 5=print, 6=exit): 4

Enter ID of student to modify: 1
Enter new student name (press / to keep existing name): /
Enter new student GPA (press / to keep existing GPA): 3.7
Updated Student Information
ID: 1
Name: John
GPA: 3.70
Student modified successfully

Enter option (1=add, 2=remove, 3=display, 4=modify, 5=print, 6=exit): 5

ID: 1
Name: John