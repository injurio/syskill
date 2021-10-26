/* Name:Chayathorn Teratanitnan
 * ID:6280945
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmpfunc (const void * char1, const void * char2){
    return (strcmp((char*)char1, (char*)char2));
}
char dic[500000][50];
int flag = 0;
char word[50];
char scramble[50];
int main(int argc, char **argv){
    FILE *scrambles, *dictionary;
    dictionary = fopen(argv[1], "r");
    scrambles = fopen(argv[2], "r");
    int lenDict = 0;
    while (fgets(scramble, 50, dictionary) != NULL){
        size_t lastCharacter = strlen(scramble)-1;
        if (scramble[lastCharacter] == '\n')
            scramble[lastCharacter] = '\0';
        strcpy(dic[lenDict], scramble);
        lenDict++;
    }
    while (fgets(scramble, 50, scrambles) != NULL){
        size_t lastCharacter = strlen(scramble)-1;
        if (scramble[lastCharacter] == '\n')
            scramble[lastCharacter] = '\0';
        printf("%s: ", scramble);
        qsort(scramble, strlen(scramble), sizeof(char), cmpfunc);
        for(int i = 0; i<lenDict; i++){
            strcpy(word, dic[i]);
            qsort(word, strlen(dic[i]), sizeof(char), cmpfunc);
            if (strcmp(scramble, word) == 0 ){
                printf("%s ", dic[i]);
                flag = 1;
            }
        }
        if (flag == 0){
            printf("NO MATCHES");
        }
        flag = 0;
        printf("\n");
    }
    fclose(dictionary);
    fclose(scrambles);
}