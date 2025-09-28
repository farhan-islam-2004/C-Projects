#include <stdio.h>
#include <math.h>

// Function declarations
void menu_list(); 
double division(double, double);
int modulus(int, int);
long long factorial(int n);

int main() {
    int choice;
    double first, second, result;

    while (1) {
        menu_list();
        scanf("%d", &choice);

        if (choice == 12) {
            printf("\nExiting Calculator... Goodbye!\n");
            break;
        }

        if (choice < 1 || choice > 12) {
            fprintf(stderr, "Invalid Menu Choice.\n");
            continue;
        }

        switch (choice) {
            case 1: // Add
            case 2: // Subtract
            case 3: // Multiply
            case 4: // Divide
            case 6: // Power
                printf("Enter first number: ");
                scanf("%lf", &first);
                printf("Enter second number: ");
                scanf("%lf", &second);
                if (choice == 1) result = first + second;
                else if (choice == 2) result = first - second;
                else if (choice == 3) result = first * second;
                else if (choice == 4) result = division(first, second);
                else if (choice == 6) result = pow(first, second);
                printf("Result = %.4lf\n", result);
                break;

            case 5: { // Modulus
                int a, b;
                printf("Enter first integer: ");
                scanf("%d", &a);
                printf("Enter second integer: ");
                scanf("%d", &b);
                printf("Result = %d\n", modulus(a, b));
                break;
            }

            case 7: // Square Root
                printf("Enter a number: ");
                scanf("%lf", &first);
                if (first < 0) fprintf(stderr, "Error: Negative number!\n");
                else printf("Result = %.4lf\n", sqrt(first));
                break;

            case 8: // Logarithm
                printf("Enter a number: ");
                scanf("%lf", &first);
                if (first <= 0) fprintf(stderr, "Error: Non-positive input for log!\n");
                else {
                    printf("log(x) base e = %.4lf\n", log(first));
                    printf("log(x) base 10 = %.4lf\n", log10(first));
                }
                break;

            case 9: // Trigonometry
                printf("Enter angle in radians: ");
                scanf("%lf", &first);
                printf("sin(%.2lf) = %.4lf\n", first, sin(first));
                printf("cos(%.2lf) = %.4lf\n", first, cos(first));
                printf("tan(%.2lf) = %.4lf\n", first, tan(first));
                break;

            case 10: { // Factorial
                int n;
                printf("Enter an integer: ");
                scanf("%d", &n);
                if (n < 0) fprintf(stderr, "Error: Factorial of negative number not defined!\n");
                else printf("%d! = %lld\n", n, factorial(n));
                break;
            }

            case 11: // Exponential
                printf("Enter a number: ");
                scanf("%lf", &first);
                printf("e^%.2lf = %.4lf\n", first, exp(first));
                break;
        }
    }

    return 0;
}

// Function definitions
double division(double a, double b) {
    if (b == 0) {
        fprintf(stderr, "Error: Division by zero!\n");
        return NAN;
    }
    return a / b;
}

int modulus(int a, int b) {
    if (b == 0) {
        fprintf(stderr, "Error: Modulus by zero!\n");
        return 0;
    }
    return a % b;
}

long long factorial(int n) {
    long long fact = 1;
    for (int i = 1; i <= n; i++)
        fact *= i;
    return fact;
}

void menu_list() {
    printf("\n\n=========== SCIENTIFIC CALCULATOR ===========");
    printf("\n1. Add");
    printf("\n2. Subtract");
    printf("\n3. Multiply");
    printf("\n4. Divide");
    printf("\n5. Modulus");
    printf("\n6. Power");
    printf("\n7. Square Root");
    printf("\n8. Logarithm");
    printf("\n9. Trigonometric Functions");
    printf("\n10. Factorial");
    printf("\n11. Exponential (e^x)");
    printf("\n12. Exit");
    printf("\nEnter your choice: ");
}
