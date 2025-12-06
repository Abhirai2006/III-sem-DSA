#include <stdio.h>

enum HttpStatus
{
    OK = 200,
    NOT_FOUND = 404,
    SERVER_ERROR = 500
};

void main()
{
    int errorCode;

    // Pretend we fetched this from server (real world)
    printf("Enter HTTP status code: ");
    scanf("%d", &errorCode);

    if (errorCode == OK)
        printf("Request succeeded (200 OK)\n");
    else if (errorCode == NOT_FOUND)
        printf("Error: Page not found (404)\n");
    else if (errorCode == SERVER_ERROR)
        printf("Error: Internal Server Error (500)\n");
    else
        printf("Unknown status code: %d\n", errorCode);
}

