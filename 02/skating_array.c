#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ARRAY_SIZE 10

double mean_calc(double[], int);
double sd_calc (double[], int);


int main (void){

    double j1[ARRAY_SIZE], j2[ARRAY_SIZE], j3[ARRAY_SIZE];
    int lines = 0, num=0;
    double s1=0, s2=0, s3=0, mean=0, sd=0;

    while (4 == scanf("%d%lg%lg%lg", &num, &s1, &s2, &s3)){
        j1[lines] = s1;
        j2[lines] = s2;
        j3[lines] = s3;
        lines++;
    }

    printf("\t\tAverage\tSD\n");
    printf("judge 1 : \t%f\t%f\n", mean_calc(j1, lines), sd_calc(j1, lines));
    printf("judge 2 : \t%f\t%f\n", mean_calc(j2, lines), sd_calc(j2, lines));
    printf("judge 3 : \t%f\t%f\n", mean_calc(j3, lines), sd_calc(j3, lines));
}

double mean_calc(double judge_num[], int array_len){

    int i = 0;
    double total = 0, mean = 0;

    for (i = 0; i < array_len; i++){
        total += judge_num[i];
    }
    mean = total/array_len;
    return mean;
}

double sd_calc (double judge_num[], int array_len){

    int i = 0;
    double total=0, sd=0;
    double mean = mean_calc(judge_num, array_len);

    for (i = 0; i < array_len; i++){
        total += (judge_num[i]-mean) * (judge_num[i] - mean);
    }
    sd = sqrt(total/(array_len-1));
    return sd;
}


   
