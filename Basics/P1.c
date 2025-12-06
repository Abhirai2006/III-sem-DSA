
void main()
{
    int a,b;
    printf("Enter the values for a and b:\n");
    scanf("%d%d",&a,&b);
    int *c;
    c = &b;
    printf("The entered values of a and b are: %d and %d\n",a,b);
    printf("a = %d\n",a);
    printf("b = %d\n",*c);
}
