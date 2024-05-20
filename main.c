#include <stdio.h>
#include "mymath.h"
#include "mylower.h"
#include "myupper.h"


#define FLUSH_STDIN while (getchar() != '\n');

char checkout()
{
    char choice;

    printf("Hey, user! Which lib you want: text or math? (t/m) > ");
    while (scanf("%c", &choice) != 1 || (choice != 't' && choice != 'm' && choice != 'T' && choice != 'M')) {
        printf("Ha-ha-ha, now seriously: text or math? (t/m) > ");
        FLUSH_STDIN
    }
    FLUSH_STDIN

    printf("Nice choice! Running ...\n");

    return choice;
}

int check_textlib ()
{
    char userstr[256];
    char action;

    do {
        printf("\n---\n > Choose the action (u, l, x): ");
        while(scanf("%c", &action) != 1) {
            printf("Waiting for action, by the way: ");
            FLUSH_STDIN
        }
        FLUSH_STDIN

        if (action == 'x' || action == 'X') {
            break;
        }

        printf("Gimme some letters (at most %ld): ", sizeof(userstr));
        if (!fgets(userstr, sizeof(userstr), stdin)) {
            printf("Some shit happened. Lets try again.\n");
            continue;
        }

        switch(action) {
            case 'u':
                if (str_to_upper(userstr)) {
                    printf("Can't do that, sorry man.\n");
                    break;
                }

                printf("[ upped ] %s ", userstr);
                break;
            case 'l':
                if (str_to_lower(userstr)) {
                    printf("Can't do that, sorry man.\n");
                    break;
                }

                printf("[ lowed ] %s ", userstr);
                break;
            default:
                printf("Surprise, unsupported action by the way.\n");
                break;
        }
    } while (1);

    return 0;
}

int check_mathlib()
{
    int a, b, c;
    unsigned long long cf;
    float cr;
    char action;

    do {
        printf("\n---\n > Choose the action (+, -, *, /, !, r, x): ");
        while(scanf("%c", &action) != 1) {
            printf("Waiting for action, by the way: ");
            FLUSH_STDIN
        }
        FLUSH_STDIN

        if (action == 'x' || action == 'X') {
            break;
        }

        printf("Gimme A: ");
        while(scanf("%d", &a) != 1) {
            printf("Don't worry, I will wait till you gimme a number.\nSo, gimme an A: ");
            FLUSH_STDIN
        }
        FLUSH_STDIN

        if (action == '+' || action == '-' || action == '*' || action == '/') {
            printf("Gimme B: ");
            while(scanf("%d", &b) != 1) {
                printf("Don't worry, I will wait till you gimme a number.\nSo, gimme a B: ");
                FLUSH_STDIN
            }
            FLUSH_STDIN
        }

        switch(action) {
            case '+':
                c = add(a, b);

                printf("[ result ] %d %c %d = %d", a, action, b, c);
                break;
            case '-':
                c = substract(a, b);

                printf("[ result ] %d %c %d = %d", a, action, b, c);
                break;
            case '*':
                c = multiply(a, b);

                printf("[ result ] %d %c %d = %d", a, action, b, c);
                break;
            case '/':
                if (b == 0) {
                    printf("Why would you ever divide by 0 ?\n");
                    break;
                }

                c = divide(a, b);

                printf("[ result ] %d %c %d = %d", a, action, b, c);
                break;
            case '!':
                if (a < 0) {
                    printf("Have you ever heard of Gamma function? I heaven't.\n");
                    break;
                }

                if (a > 20) {
                    printf("It's too much for me, sorry.\n");
                    break;
                }

                cf = factorial(a);

                printf("[ result ] %d %c = %llu", a, action, cf);
                break;
            case 'r':
                if (a < 0) {
                    printf("Sorry, but complex numbers are too complex for me :(\n");
                    break;
                }

                cr = sqroot(a);

                printf("[ result ] sq.root of %d = %f", a, cr);
                break;
            default:
                printf("Surprise, unsupported action by the way.\n");
                break;
        }
    } while (1);

    return 0;
}

int main (int argc, char *argv[])
{
    printf("Salute, world!\n");

    switch (checkout()) {
        case 't':
            check_textlib();
            break;
        case 'm':
            check_mathlib();
            break;
        default:
            break;
    }

    printf("Chiao!\n");

    return 0;
}
