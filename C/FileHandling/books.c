// A publishing company holds in a file detail of all the books they publish. 
// However, in the future, they wish to maintain two distinct files (i) paperbacks (ii) hardbacks. 
// Write a program which reads a file containing details of both paperback and hardback books and 
// creates two files as specified above. Assume that the first character in each input record 
// indicates if the book is paperback(p) or hardback(h) or both(b).

#include <stdio.h>
int main() {
    FILE *in_file, *paperback_file, *hardback_file;
    char filename[100], line[256], book_type;

    // Ask for the input filename
    printf("Enter the input filename: ");
    scanf("%s", filename);

    // Open the input file
    in_file = fopen(filename, "r");
    if (in_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    // Open the output files
    paperback_file = fopen("paperbacks.txt", "w");
    hardback_file = fopen("hardbacks.txt", "w");

    // Read through the input file line by line
    while (fgets(line, sizeof(line), in_file)) {
        // Get the book type from the first character of the line
        book_type = line[0];

        // Write the line to the appropriate output file
        if (book_type == 'p') {
            fprintf(paperback_file, "%s", line);
        }else if (book_type == 'h') {
            fprintf(hardback_file, "%s", line);
        }else if(book_type == 'b'){
            fprintf(paperback_file, "%s", line);
            fprintf(hardback_file, "%s", line);
        }
    }

    // Close the files
    fclose(in_file);
    fclose(paperback_file);
    fclose(hardback_file);

    printf("Done.\n");
    return 0;
}