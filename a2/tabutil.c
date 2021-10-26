/* Name:Chayathorn Terataninan
 * ID: 6280945
 */
#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char tabtospace[] = "-d";
    int space = 0;
    char c;
    char ch[10000];
    int index = 0;
    int num = atoi(argv[2]);
    if (strcmp(argv[1], tabtospace) == 0)
    {
        while (1)
        {
            if ((c = getchar()) == '\n')
            {
                break;
            }
            ch[index] = c;
            index++;
        }
        int i = 0;
        while (i < index)
        {
            if (ch[i] == '\t')
            {
                for (int j = 0; j < atoi(argv[2]); j++)
                {
                    printf(" ");
                }
            }
            else
            {
                printf("%c", ch[i]);
            }
            i++;
        }
    }
    else
    {
        while (1)
        {
            if ((c = getchar()) == '\n')
            {
                break;
            }
            ch[index++] = c;
        }
        int i = 0;
        while (i < index)
        {
            if (ch[i] != ' ')
            {
                if ((space < num) && (space > 0))
                {
                    for (int k = 0; k < space; k++)
                    {
                        putchar(' ');
                    }
                }
                printf("%c", ch[i]);
                space = 0;
            }
            else
            {
                space++;
                if (space == num)
                {
                    printf("%c", '\t');
                    space = 0;
                }
            }
            i++;
        }
    }
    printf("\n");
    return 0;
}