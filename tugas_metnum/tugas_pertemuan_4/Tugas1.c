#include <stdio.h>
#include <conio.h>
#include <math.h>
#define max 999

int fraction[max], integer[max];

void dectobin();
void bintodec();

int main()
{
    int i, cnum, ch;
    float num, f;

    while (1)
    {
        printf("Berikut menu yang tersedia : \n");
        printf("1. Konversi Bilangan Desimal ke Biner\n");
        printf("2. Konversi Bilangan Biner ke Desimal\n");
        printf("3. Keluar\n\n");
        printf("Pilih menu : ");
        scanf("%d", &ch);
        printf("\n");
        switch (ch)
        {
        case 1:
            dectobin();
            break;
        case 2:
            bintodec();
            break;
        case 3:
            exit(1);
        default:
            printf("Menu pilihan tidak disediakan\n");
        }
        printf("\nTekan tombol apapun untuk melanjutkan...\n");
        getch();
    }

    getch();
    return 1;
}

void dectobin()
{
    float num, f;
    int i, cnum, tag;
    printf("Masukkan bilangan desimal : ");
    scanf("%f", &num);
    printf("\n");
    f = num - (int)num;
    for (i = 0; i < max; i++)
    {
        f = f - (int)f;
        fraction[i] = (int)(f * 2);
        f *= 2;
    }

    cnum = (int)num;
    for (i = max - 1; i >= 0; i--)
    {
        if (cnum % 2 == 0)
        {
            integer[i] = 0;
        }
        else
            integer[i] = 1;
        cnum /= 2;
    }

    printf("Konversi binernya = ");
    tag = 0;

    for (i = 0; i < max; i++)
    {
        if (integer[i] || tag)
        {
            tag = 1;
            printf("%d", integer[i]);
        }
    }
    printf(".");

    for (i = 0; i < 7; i++)
        printf("%d", fraction[i]);

    printf("\n");
}

void bintodec()
{
    double num, fnum, result = 0;
    long inum, i = 0, a = 0;
    printf("Masukkan bilangan biner : ");
    scanf("%lf", &num);
    printf("\n");

    inum = num;
    fnum = num - (long)num;
    printf("%ld\t%lf\n", inum, fnum);

    while (inum)
    {
        result += (inum % 10) * pow(2, i++);
        inum /= 10;
    }

    for (i = 0; i < max; i++)
    {
        a--;
        fnum *= 10;
        if (fnum >= 1)
        {
            fnum -= 1;
            result += pow(2, a);
        }
    }
    printf("Konversi desimalnya = %lf\n", result);
}