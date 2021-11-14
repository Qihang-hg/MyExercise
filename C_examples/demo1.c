#include<stdio.h>
int main()
{
    float weight;
    float value;
    printf("are you worth your weight ?\n");
    printf("lets chect it out.\n\n");
    printf("please enter your weight in pounds:");
    scanf("%f",&weight);
    value = 1700.0 * weight * 14.5833;
    printf("$%.2f.\n", value);
    return 0;
}