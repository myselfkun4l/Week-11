#include <stdio.h>
#include <string.h>

struct Employee {
    char name[25];
    int age;
    int basic;
    float totalSalary; 
};

int main() {
    struct Employee emp[5], temp;

    for(int i = 0; i < 5; i++) {
        printf("\nEnter details of employee %d:\n", i + 1);

        printf("Name: ");
        getchar(); 
        fgets(emp[i].name, sizeof(emp[i].name), stdin);
        emp[i].name[strcspn(emp[i].name, "\n")] = 0;

        printf("Age: ");
        scanf("%d", &emp[i].age);

        printf("Basic Salary: ");
        scanf("%d", &emp[i].basic);
        
        float DA = 0.10 * emp[i].basic;  
        float HRA = 0.05 * emp[i].basic; 
        emp[i].totalSalary = emp[i].basic + DA + HRA;
    }
    for(int i = 0; i < 5 - 1; i++) {
        for(int j = i + 1; j < 5; j++) {
            if(emp[j].totalSalary > emp[i].totalSalary) {
                temp = emp[i];
                emp[i] = emp[j];
                emp[j] = temp;
            }
        }
    }
    printf("\n------ Employee Records (Descending Salary) ------\n");
    printf("Name\t\tAge\tTotal Salary\n");
    for(int i = 0; i < 5; i++) {
        printf("%-15s\t%d\t%.2f\n", emp[i].name, emp[i].age, emp[i].totalSalary);
    }

    return 0;
}
