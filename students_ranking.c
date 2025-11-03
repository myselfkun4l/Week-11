#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int rollNo;
    float marks;
};

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    getchar(); 

    struct Student students[n], temp;
    for(int i = 0; i < n; i++) {
        printf("\nEnter details of student %d:\n", i + 1);

        printf("Name: ");
        fgets(students[i].name, sizeof(students[i].name), stdin);
        students[i].name[strcspn(students[i].name, "\n")] = 0; 

        printf("Roll No: ");
        scanf("%d", &students[i].rollNo);

        printf("Marks: ");
        scanf("%f", &students[i].marks);
        getchar(); 
    }
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(students[j].marks > students[i].marks) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
    printf("\n------ Student Records (Rank-wise) ------\n");
    printf("Rank\tName\t\tRoll No\tMarks\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t%s\t\t%d\t%.2f\n", i + 1, students[i].name, students[i].rollNo, students[i].marks);
    }

    return 0;
}
