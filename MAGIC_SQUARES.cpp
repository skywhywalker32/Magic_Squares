#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <time.h>
#include <random>
#define N 100

///////////////////
void PrintMatrix(int arr[N][N],const int &n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            printf("%d\t",arr[i][j]);
        printf("\n");
    }
}
///////////////////
void MagicSquare_Odd_N(int arr[N][N],const int &n)
{
    int square_const=n*(n*n+1)/2;
    printf("const = %d | const означает сумму по строкам, столбцам и диагоналям, которая должна быть у магического квадрата\n",square_const);
    for(int i = 0; i < n*n; i++) {
        for(int j = 0; j < n*n; j++) {
            arr[(n -1 + i)%n][(n - 1 + j)%n] = n * ((i + j - 1 + (n - 1) / 2) % n) + ((i + 2 * j - 2) % n) + 1;
        }
    }
}
void MagicSquare_Even_N_1(int arr[N][N],const int&n)
{
    int square_const=n*(n*n+1)/2; int j,i;
    printf("const = %d | const означает сумму по строкам, столбцам и диагоналям, которая должна быть у магического квадрата\n",square_const);
    for ( i = 0; i<n; i++)
    {
        for ( j = 0; j<n; j++)
                    arr[i][j] = (n*i) + j + 1;        
    }

    for ( i = 0; i<n/4; i++)
    {
        for ( j = 0; j<n/4; j++)
            arr[i][j] = (n*n + 1) - arr[i][j];
    }

    for ( i = 0; i< n/4; i++)
    {
        for ( j = 3* (n/4); j<n; j++)
            arr[i][j] = (n*n + 1) - arr[i][j];
    }

    for ( i = 3* n/4; i<n; i++)
    {
        for ( j = 0; j<n/4; j++)
            arr[i][j] = (n*n + 1) - arr[i][j];
    }
    
    for ( i = 3* n/4; i<n; i++)
    {
        for ( j = 3* n/4; j<n; j++)
            arr[i][j] = (n*n + 1) - arr[i][j];
    }
 
    for ( i = n/4; i<3* n/4; i++)
    {
        for ( j = n/4; j<3* n/4; j++)
            arr[i][j] = (n*n + 1) - arr[i][j];
    }
}
///////////////////////////////////////
void MagicSquare_Even_N_2(int arr[N][N], const int &n)
{
    int set_arr6[6][6] = {
        {35, 23, 6, 34, 3, 10},
        {17, 13, 30, 20, 5, 26},
        {24, 11, 9, 14, 32, 21},
        {1, 4, 36, 29, 25, 16},
        {15, 27, 8, 12, 18, 31},
        {19, 33, 22, 2, 28, 7}
    };
    if(n==6)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                printf("%d\t",set_arr6[i][j]);
            }
            printf("\n");
        }
    }
    int set_arr10[10][10] = {
        {53, 81, 25, 43, 69, 97, 31, 59, 87, 15},
        {20, 48, 76, 94, 22, 50, 78, 6, 34, 62},
        {12, 40, 68, 96, 24, 52, 80, 8, 36, 64},
        {49, 77, 5, 33, 61, 89, 17, 45, 73, 1},
        {16, 44, 72, 100, 28, 56, 84, 12, 40, 68},
        {86, 14, 42, 70, 98, 26, 54, 82, 10, 38},
        {63, 91, 19, 47, 75, 3, 31, 59, 87, 15},
        {30, 58, 86, 14, 42, 70, 98, 26, 54, 82},
        {7, 35, 63, 91, 19, 47, 75, 3, 31, 59},
        {74, 2, 30, 58, 86, 14, 42, 70, 98, 26}
        };
    if(n==10)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                printf("%d\t",set_arr10[i][j]);
            }
            printf("\n");
        }
    }
   
}
//////////////////////////////////////
int main()
{
    system("chcp 1251");
    float n;
    float choice; int arr[N][N];
    printf("-------------------------------------------\n");
    printf("Добро пожаловать в мир волшебных квадратов!\n");
    printf("-------------------------------------------\n\n");
    do
    {
        do
        {
            printf("Введите вариант: 0 - завершение программы | 1 - перейти к программе: "); scanf_s("%f", &choice);
            printf("*\t*\t*\t*\t*\t*\t*\t*\t*\t*\n");
            if (choice != 0 && choice != 1)
            {
                printf("Введено неверное значение!!\n");
            }
        } while (choice != 0 && choice != 1);
        switch((int)choice)
        {
            case(0):printf("Завершение программы"); return 1;
            case(1):
                {
                    printf("Магический квадрат — квадратная таблица NxN, заполненная N^2 различными числами таким образом,\n"
                    "что сумма чисел в каждой строке, каждом столбце и на обеих диагоналях одинакова.\n");
                    printf("N берёт целую часть числа\n") ;
                    printf("Введите значение N: ");scanf_s("%f",&n);
                    int clone = (int)n;
                    if(n<=2 || n>10){printf("некорректное значение N\n");}
                    else
                    {
                        if(clone%2!=0)
                        {
                            MagicSquare_Odd_N(arr,clone);
                            PrintMatrix(arr,clone);
                        }
                        if(clone%2==0 && clone%4==0)
                        {
                            MagicSquare_Even_N_1(arr,clone);
                            PrintMatrix(arr,clone);
                        }
                        if(clone%2==0 && clone%4!=0)
                        {
                            MagicSquare_Even_N_2(arr,clone);
                        }
                        break;
                    }break;
                }
            default: printf("Ошибка\n");break;
        }
    }
    while(choice!=0);
    return 1;
}
