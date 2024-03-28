
// #include <stdio.h>

// FILE *fptr = NULL;
// int main() {
//     char buffer[100];

//     /**
//      * a - mode
//      * input.txt - filename
//      */

//     fptr = fopen("input.txt", "a");

//     if (!fptr) {
//         printf("file can't open\n");
//         return -1;
//     }

//     fputs("Appended by function\n", fptr);
//     fputc(65, fptr);
//     return 0;
// }


// #include <stdio.h>

// FILE *fptr = NULL;
// int main()
// {
//     char buffer[100];

//     /**
//      * r+ - read and write mode
//      * input.txt - filename
//      */

//     fptr = fopen("input.txt", "r+");

//     if (!fptr)
//     {
//         printf("file can't open\n");
//         return -1;
//     }

//     fgets(buffer, 100, fptr);
//     puts(buffer);
//     fprintf(fptr, "%s", "writted by printf\n");
//     return 0;
// }

// #include <stdio.h>

// FILE *fptr=NULL;

// int main() {
//     int n1,n2;

//     fopen(fptr, "r");
//     n1 = fgetc(fptr, )
//     fclose(fptr);
// }
