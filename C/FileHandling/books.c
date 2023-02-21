// A publishing company holds in a file detail of all the books they publish. 
// However, in the future, they wish to maintain two distinct files (i) paperbacks (ii) hardbacks. 
// Write a program which reads a file containing details of both paperback and hardback books and 
// creates two files as specified above. Assume that the first character in each input record 
// indicates if the book is paperback(p) or hardback(h) or both(b).

#include <stdio.h>
int main() {
    FILE *in_file, *paperback_file, *hardback_file;
    char filename[100], line[256], book_type;

    printf("Enter the input filename: ");
    scanf("%s", filename);

    in_file = fopen(filename, "r");
    if (in_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    paperback_file = fopen("paperbacks.txt", "w");
    hardback_file = fopen("hardbacks.txt", "w");

    while (fgets(line, sizeof(line), in_file)) {
        book_type = line[0];

        if (book_type == 'p') {
            fprintf(paperback_file, "%s", line);
        }else if (book_type == 'h') {
            fprintf(hardback_file, "%s", line);
        }else if(book_type == 'b'){
            fprintf(paperback_file, "%s", line);
            fprintf(hardback_file, "%s", line);
        }
    }

    fclose(in_file);
    fclose(paperback_file);
    fclose(hardback_file);

    printf("Done.\n");
    return 0;
}