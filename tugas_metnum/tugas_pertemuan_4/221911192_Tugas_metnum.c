#include <stdbool.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#define max 999

int fraction[max], integer[max];

void konversidesimalkebinary();
void konversibinarytodesimal();
bool isBinary(float);

int main()
{
    int i, cnum, ch;
    float num, f;

    while (1)
    {
        printf("Pilihan tersedia : \n");
        printf("1. Bilangan Desimal --> Biner\n");
        printf("2. Bilangan Biner --> Desimal\n");
        printf("3. Keluar\n\n");
        printf("Pilih menu(1/2/3) : ");
        scanf("%d", &ch);
        printf("\n");
        switch (ch)
        {
        case 1:
            konversidesimalkebinary();
            break;
        case 2:
            konversibinarytodesimal();
            break;
        case 3:
            exit(1);
        default:
            printf("Pilihan tidak disediakan\n");
        }
        printf("\nTekan tombol random untuk melanjutkan...\n");
        getch();
    }

    getch();
    return 1;
}

bool isBinary(float number)
{
    float duplikat;
    int temp = 0;
    duplikat = number;

    // dibuat integer dulu
    while (duplikat != ((int)duplikat))
    {
        duplikat = duplikat * 10;
    }

    // cek biner dgn modulo
    while (duplikat != 0)
    {
        temp = (int)duplikat % 10;
        if ((temp == 0) || (temp == 1))
        {
            duplikat = duplikat / 10;
            if (duplikat == 0)
            {
                printf("%f adalah bilangan biner.\n\n", number);
                return (1);
                break;
            }
        }
        else
        {
            printf("%f bukanlah bilangan biner. Silahkan mencoba kembali.\n\n", number);
            return (0);
            break;
        }
    }
}

void konversidesimalkebinary()
{
    float number, f;
    int i, cnum, tag;
    printf("Masukkan bilangan desimal : ");
    scanf("%f", &number);
    printf("\n");
    f = number - (int)number;
    for (i = 0; i < max; i++)
    {
        f = f - (int)f;
        fraction[i] = (int)(f * 2);
        f *= 2;
    }

    cnum = (int)number;
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

void konversibinarytodesimal()
{
    double num, fnum, result = 0;
    long inum, i = 0, a = 0;
    printf("Masukkan bilangan biner : ");
    scanf("%lf", &num);
    printf("\n");

    if (isBinary(num))
    {
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
}