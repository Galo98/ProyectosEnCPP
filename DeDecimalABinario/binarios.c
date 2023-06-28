
int num, binaryNumbers[8];

int main()
{
    int num, binaryNumbers[8];

    printf("Vamos a transformar un numero decimal a binario \n");
    printf("Ingresa un numero del 0 al 255 ");
    scanf("%d", &num);

    if (num > 255)
    {
        printf("Numero no valido \n");
    }
    else
    {
        for (int i = 7; i >= 0; i--)
        {
            binaryNumbers[i] = num % 2;
            num = num / 2;
        }
    }

    for (int j = 0; j < 8; j++)
    {
        printf("%d ", binaryNumbers[j]);
    }

    printf("\n");

    return 0;
}