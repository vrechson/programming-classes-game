#include <stdio.h>
#include <string.h>

void inverter (char a[])
{
    int i = 0, n;

    while (*(a + i) != '\0')
        i++;

    for (n = 0; n < i; n++){
        if (*(a + n) >= 65 && *(a + n) < 97)
            *(a + n) += 32;
        else
            if (*(a + n) >= 97)
                *(a + n) -= 32;
    }
    printf("%d\n", i);
    printf("%c", *a);
}

int main()
{
    char frase[100];
    printf("Digite uma frase:\n");
    fgets(frase, 100, stdin);
    strtok(frase, "\n");
    inverter(frase);

    return 0;
}
