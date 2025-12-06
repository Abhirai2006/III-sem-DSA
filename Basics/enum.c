#include <stdio.h>

// Define an enum for HTTP status codes
enum HttpStatus
{
    OK = 200,
    NOT_FOUND = 404,
    SERVER_ERROR = 500
};

void main()
{
    int errorCode;

    // Example 1: Using direct numbers
    errorCode = 404;
    if (errorCode == 404) printf("Direct check: Not Found\n");
    if (errorCode == 500) printf("Direct check: Server Error\n");

    // Example 2: Using enum
    errorCode = NOT_FOUND;   // same as 404
    if (errorCode == NOT_FOUND) printf("Enum check: Not Found\n");
    if (errorCode == SERVER_ERROR) printf("Enum check: Server Error\n");

    // Example 3: Another case
    errorCode = SERVER_ERROR; // same as 500
    if (errorCode == NOT_FOUND) printf("Enum check: Not Found\n");
    if (errorCode == SERVER_ERROR) printf("Enum check: Server Error\n");

}
