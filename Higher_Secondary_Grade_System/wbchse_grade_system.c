#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function prototypes
int get_random_marks();
char get_grade(int marks);
char* get_overall_grade(float percent);

int main() {
    char name[50], school[100];
    long reg_no;
    int roll_no, num_subjects;

    // Random seed
    srand(time(0));

    // Banner
    printf("----------------------------------------\n");
    printf("West Bengal Council of Higher Secondary Education\n");
    printf("----------------------------------------\n\n");

    // Student details
    printf("Enter Student Name: ");
    scanf(" %[^\n]", name);
    printf("Enter Registration Number: ");
    scanf("%ld", &reg_no);
    printf("Enter Roll Number: ");
    scanf("%d", &roll_no);
    printf("Enter School Name: ");
    scanf(" %[^\n]", school);

    // Choose stream
    int stream_choice;
    printf("\nSelect Stream:\n");
    printf("1. Science\n2. Arts\n3. Commerce\n");
    printf("Enter choice: ");
    scanf("%d", &stream_choice);

    printf("\nHow many subjects? (5 or 6): ");
    scanf("%d", &num_subjects);

    char subjects[10][50]; // max 10 subjects
    int marks[10];
    int total = 0;

    // Take subject names
    for (int i = 0; i < num_subjects; i++) {
        printf("Enter name of subject %d: ", i + 1);
        scanf(" %[^\n]", subjects[i]);
    }

    // Generate marks
    for (int i = 0; i < num_subjects; i++) {
        marks[i] = get_random_marks();
        total += marks[i];
    }

    // Best 5 rule (if 6 subjects)
    int best5_total = total;
    int lowest = 101, lowest_index = -1;
    if (num_subjects == 6) {
        for (int i = 0; i < 6; i++) {
            if (marks[i] < lowest) {
                lowest = marks[i];
                lowest_index = i;
            }
        }
        best5_total -= lowest;
    }

    float percent = (best5_total / (num_subjects == 6 ? 500.0 : num_subjects * 100.0)) * 100;

    // Output: Marksheet
    printf("\n----------------------------------------\n");
    printf("              MARKSHEET\n");
    printf("----------------------------------------\n");
    printf("Name: %s\nReg No: %ld\nRoll No: %d\nSchool: %s\n", name, reg_no, roll_no, school);
    printf("Stream: %s\n", (stream_choice==1?"Science":stream_choice==2?"Arts":"Commerce"));
    printf("----------------------------------------\n");
    printf("Subject            Marks   Grade\n");
    printf("----------------------------------------\n");

    for (int i = 0; i < num_subjects; i++) {
        printf("%-18s %3d     %c", subjects[i], marks[i], get_grade(marks[i]));
        if (num_subjects == 6 && i == lowest_index) {
            printf("   <-- Not counted (lowest)\n");
        } else {
            printf("\n");
        }
    }

    printf("----------------------------------------\n");
    if (num_subjects == 6)
        printf("Best 5 Total: %d / 500\n", best5_total);
    else
        printf("Total: %d / %d\n", best5_total, num_subjects*100);

    printf("Percentile: %.2f%%\n", percent);
    printf("Overall Grade: %s\n", get_overall_grade(percent));
    printf("----------------------------------------\n");

    return 0;
}

// Random marks
int get_random_marks() {
    return rand() % 101;
}

// Subject grade
char get_grade(int marks) {
    if (marks >= 90) return 'A';
    else if (marks >= 80) return 'B';
    else if (marks >= 70) return 'C';
    else if (marks >= 60) return 'D';
    else if (marks >= 50) return 'E';
    else return 'F';
}

// Overall grade
char* get_overall_grade(float percent) {
    if (percent >= 90) return "A+";
    else if (percent >= 80) return "A";
    else if (percent >= 70) return "B+";
    else if (percent >= 60) return "B";
    else if (percent >= 50) return "C";
    else return "Fail";
}
