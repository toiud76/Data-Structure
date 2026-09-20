#include <stdio.h>


int main(void) {
    int i;
    char *ptrArray[4] = { {"Korea"}, {"Seoul"}, {"Mapo"}, {"612"} };

    for (i = 0; i < 4; i++)
        printf("\n%s", ptrArray[i]);

    ptrArray[2] = "Jongno";
    printf("\n\n");

    for (i = 0; i < 4; i++)
        printf("\n%s", ptrArray[i]);

    getchar();
    return 0;
}