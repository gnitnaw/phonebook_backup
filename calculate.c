#include <stdio.h>
#include <stdlib.h>
#define	NDATA	5
void read_file(char* fileName, double* opt_sum_a, double* opt_sum_f)
{

    FILE *input = fopen(fileName, "r");
    if (!input) {
        printf("ERROR opening input file %s\n", fileName);
        exit(0);
    }

    int i;
    *opt_sum_a = 0.0;
    *opt_sum_f = 0.0;
    char append[50], find[50];
    double opt_a, opt_f;
    for (i = 0; i < 100; i++) {
        if (feof(input)) {
            printf("ERROR: You need 100 datum instead of %d\n", i);
            printf("run 'make run' longer to get enough information\n\n");
            exit(0);
        }
        fscanf(input, "%s %s %lf %lf\n", append, find,&opt_a, &opt_f);
        *opt_sum_a += opt_a;
        *opt_sum_f += opt_f;
    }
    *opt_sum_a /=100;
    *opt_sum_f /=100;
    fclose(input);
}

int main(void)
{
    FILE *output = fopen("output.txt", "w");
    int i;
    double avg_a[NDATA], avg_f[NDATA];
    read_file("orig.txt", &avg_a[0], &avg_f[0]);
    read_file("opt_SmallerStruct.txt", &avg_a[1], &avg_f[1]);
    read_file("opt_HashSdbm.txt", &avg_a[2], &avg_f[2]);
    read_file("opt_HashBkdr.txt", &avg_a[3], &avg_f[3]);
    read_file("opt_NewSize.txt", &avg_a[4], &avg_f[4]);

    fprintf(output, "append()");
    for (i=0; i<NDATA; ++i) {
        fprintf(output, " %lf", avg_a[i]);
    }
    fprintf(output, "\nfindName()");
    for (i=0; i<NDATA; ++i) {
        fprintf(output, " %lf", avg_f[i]);
    }
    fprintf(output, "\n");

    fclose(output);
    return 0;
}
