#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpChar(const void *a, const void *b)
{
    return (*(char*)a - *(char*)b);
}

char* sortStr(const char* s)
{
    char* temp = strdup(s);
    qsort(temp, strlen(temp), sizeof(char), cmpChar);
    return temp;
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes)
{
    char*** result = (char***)malloc(strsSize * sizeof(char**));
    *returnColumnSizes = (int*)malloc(strsSize * sizeof(int));

    char** keys = (char**)malloc(strsSize * sizeof(char*));
    int groupCount = 0;

    for(int i = 0; i < strsSize; i++)
    {
        char* sorted = sortStr(strs[i]);
        int found = -1;

        for(int j = 0; j < groupCount; j++)
        {
            if(strcmp(keys[j], sorted) == 0)
            {
                found = j;
                break;
            }
        }

        if(found == -1)
        {
            keys[groupCount] = sorted;
            result[groupCount] = (char**)malloc(strsSize * sizeof(char*));
            (*returnColumnSizes)[groupCount] = 0;
            found = groupCount;
            groupCount++;
        }
        else
        {
            free(sorted);
        }

        result[found][(*returnColumnSizes)[found]] = strs[i];
        (*returnColumnSizes)[found] += 1;
    }

    *returnSize = groupCount;
    return result;
}