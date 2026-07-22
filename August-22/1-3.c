#include <stdio.h>

struct Employee {
    int emp_id;
    char name[50];
    char designation[50];
    float basic_salary, hra_percent, da_percent;
};

float calculateGrossSalary(struct Employee emp) {
    return emp.basic_salary + (emp.basic_salary * emp.hra_percent / 100) + (emp.basic_salary * emp.da_percent / 100);
}

int main() {
	int n;
	printf("Enter the no of employee : ");
	scanf("%d",&n);

	struct Employee emp[n];

	for (int i=0; i<n; i++) {
		 printf("\nEnter details for employee %d:\n", i + 1);

	        printf("Employee ID: ");
        	scanf("%d", &emp[i].emp_id);
	        printf("Name: ");
        	scanf("%s", emp[i].name);
	        printf("Designation: ");
        	scanf("%s", emp[i].designation);
        	printf("Basic Salary: ");
	        scanf("%f", &emp[i].basic_salary);
	        printf("HRA Percentage: ");
        	scanf("%f", &emp[i].hra_percent);
	        printf("DA Percentage: ");
        	scanf("%f", &emp[i].da_percent);

	}
	printf("\nEmployee Information:\n");
    	for (int i = 0; i < n; i++) {
        	float gross_salary = calculateGrossSalary(emp[i]);
	        printf("Employee ID: %d\n", emp[i].emp_id);
        	printf("Name: %s\n", emp[i].name);
	        printf("Designation: %s\n", emp[i].designation);
        	printf("Basic Salary: %.2f\n", emp[i].basic_salary);
	        printf("HRA Percentage: %.2f%%\n", emp[i].hra_percent);
        	printf("DA Percentage: %.2f%%\n", emp[i].da_percent);
        	printf("Gross Salary: %.2f\n", gross_salary);
        	printf("\n");
    }
	return 0;
}
