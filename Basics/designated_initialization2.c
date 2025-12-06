#include <stdio.h>
#include <stdlib.h>
#define N 100
#pragma pack(1)

struct school
{
    int e_year;
    double strength;
    char s_name[N];
};

int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    struct school d[n], *ptr;
    ptr = d;

    if (n > 0) {
        d[0] = (struct school){
            .e_year = 1999,
            .strength = 1500.75,
            .s_name = "National_Public_School"
        };
    }

    if (n > 1) {
        d[n-1] = (struct school){
            .e_year = 2010,
            .strength = 2300.50,
            .s_name = "St_Josephs_High"
        };
    }

    for (int i = 1; i < n-1; i++)
    {
        printf("Enter the details of school %d (year strength name): ", i+1);
        scanf("%d %lf %s",
              &(ptr+i)->e_year,
              &(ptr+i)->strength,
              (ptr+i)->s_name);
    }

    printf("\n%-5s %-10s %-30s\n", "Year", "Strength", "Name");
    printf("-------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-5d %-10.2lf %-30s\n",
               (ptr+i)->e_year,
               (ptr+i)->strength,
               (ptr+i)->s_name);
    }

    return 0;
}
