#include <stdio.h>
#include <string.h>
struct Student {
    char name[50];
    char className[20];
    int rollNo;
    char enrolment[30];
    float marks;
};

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    getchar(); 

    struct Student students[n];
    for(int i = 0; i < n; i++) {
        printf("\nEnter details of student %d:\n", i + 1);

        printf("Name: ");
        fgets(students[i].name, sizeof(students[i].name), stdin);
        students[i].name[strcspn(students[i].name, "\n")] = 0; 

        printf("Class: ");
        fgets(students[i].className, sizeof(students[i].className), stdin);
        students[i].className[strcspn(students[i].className, "\n")] = 0;

        printf("Roll No: ");
        scanf("%d", &students[i].rollNo);
        getchar();

        printf("Enrolment: ");
        fgets(students[i].enrolment, sizeof(students[i].enrolment), stdin);
        students[i].enrolment[strcspn(students[i].enrolment, "\n")] = 0;

        printf("Marks: ");
        scanf("%f", &students[i].marks);
        getchar();
    }
    printf("\n------ Student Records ------\n");
    for(int i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Name      : %s\n", students[i].name);
        printf("Class     : %s\n", students[i].className);
        printf("Roll No   : %d\n", students[i].rollNo);
        printf("Enrolment : %s\n", students[i].enrolment);
        printf("Marks     : %.2f\n", students[i].marks);
    }

    return 0;
}
