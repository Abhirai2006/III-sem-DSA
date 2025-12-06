
int main()
{
    int n, *ptr;
    printf("Enter the value of n:\n");
    scanf("%d", &n);
    printf("n = %d\n", n);
    ptr = (int*)malloc(n * sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    for(int i=0; i<n; i++)
    {
        scanf("%d", (ptr + i));
    }
    // Optionally print elements to check:
    for(int i=0; i<n; i++)
    {
        printf("%d ", *(ptr + i));
    }
    free(ptr); // Always free allocated memory
    return 0;
}
