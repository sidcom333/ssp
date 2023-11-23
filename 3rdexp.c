#include <stdio.h>
#include <conio.h>
#include <string.h>

void createInputFile() {
    FILE *fp = fopen("input.dat", "w");

    if (fp == NULL) {
        printf("Error creating input file.\n");
        getch();
        exit(1);
    }

    fprintf(fp, "H 100 10\n"); // Sample Header record
    fprintf(fp, "T 200 ABCDEF\n"); // Sample Text record
    fprintf(fp, "T 203 XYZ123\n"); // Another Text record
    fprintf(fp, "E\n"); // End of file

    fclose(fp);
}

void processAndSaveToFile() {
    char input[10];
    int start, length, address;
    FILE *fp1, *fp2;

    clrscr();

    // Open the input file for reading
    fp1 = fopen("input.dat", "r");

    // Check if the input file exists; if not, create it
    if (fp1 == NULL) {
        createInputFile();
        // Reopen the input file for reading
        fp1 = fopen("input.dat", "r");
        if (fp1 == NULL) {
            printf("Error opening input file.\n");
            getch();
            exit(1);
        }
    }

    // Open the output file for writing
    fp2 = fopen("output.dat", "w");

    // Check if the output file opened successfully
    if (fp2 == NULL)
    {
        printf("Error opening output file.\n");
        fclose(fp1); // Close the input file before exiting
        getch();
        exit(1); // Terminate the program with an error code
    }

    // Read the first string from the input file
    fscanf(fp1, "%s", input);

    // Continue processing until "E" is encountered
    while (strcmp(input, "E") != 0)
    {
        // Check if "H" is encountered
        if (strcmp(input, "H") == 0)
        {
            // Read start, length, and the next string
            fscanf(fp1, "%d", &start);
            fscanf(fp1, "%d", &length);
            fscanf(fp1, "%s", input);
        }
        // Check if "T" is encountered
        else if (strcmp(input, "T") == 0)
        {
            // Read address and the next string
            fscanf(fp1, "%d", &address);
            fscanf(fp1, "%s", input);

            // Write formatted data to the output file
            fprintf(fp2, "%d\t%c%c\n", address, input[0], input[1]);
            fprintf(fp2, "%d\t%c%c\n", (address + 1), input[2], input[3]);
            fprintf(fp2, "%d\t%c%c\n", (address + 2), input[4], input[5]);

            // Increment the address by 3
            address += 3;

            // Read the next string
            fscanf(fp1, "%s", input);
        }
        // Otherwise, assume it's a regular record
        else
        {
            // Write formatted data to the output file
            fprintf(fp2, "%d\t%c%c\n", address, input[0], input[1]);
            fprintf(fp2, "%d\t%c%c\n", (address + 1), input[2], input[3]);
            fprintf(fp2, "%d\t%c%c\n", (address + 2), input[4], input[5]);

            // Increment the address by 3
            address += 3;

            // Read the next string
            fscanf(fp1, "%s", input);
        }
    }

    // Close the input and output files
    fclose(fp1);
    fclose(fp2);

    printf("FINISHED");
    getch();
}

void main() {
    processAndSaveToFile();
}
