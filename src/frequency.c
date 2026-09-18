#include <stdio.h>
#include <stdbool.h>
#include <errno.h>
#include <stdlib.h>

#include "frequency.h"

int CalcFrequency(freq_data_t* freqData, FILE* inputFile) {
    int chr = 0;
    while((chr = fgetc(inputFile)) != EOF){
        // convert capital letters to lower case
        if ((int)'A' <= chr && chr <= (int)'Z') {
            chr = (chr - ((int)'A' - (int)'a'));
        // skip if the remaining characters aren't lower case letters
        } else if (!((int)'a' <= chr && chr <= (int)'z')){
            continue;
        }

        freqData->counts[(chr - (int)'a')] = freqData->counts[(chr - (int)'a')] + 1;
        freqData->total++;
    }

    if (freqData->total == 0) {
        return 1;
    }

    for (int i = 0; i < 26; i++){
        freqData->frequencies[i] = (double)freqData->counts[i]/freqData->total;
    }

    return 0;
}

double CalcIC(freq_data_t* freqData) {
    double sum = 0;
    for (int i = 0; i < 26; i++){
        sum += (freqData->counts[i]/(double)freqData->total)*((freqData->counts[i]-1)/((double)freqData->total-1));
    }

    return sum;
}

int main(int argc, char* argv[]){
    if (argc < 2){
        printf("Usage: frequency [INPUTFILE]\n");
        exit(1);
    }

    freq_data_t freqData = {0};

    FILE* inputFile = fopen(argv[2], "r");
    if (inputFile == NULL) {
        perror("Error On Input File Name");
        exit(errno);
    }

    int res = CalcFrequency(&freqData, inputFile);

    fclose(inputFile);

    if (res == 1){
        printf("No suitable letters found.");
        exit(1);
    }

    for (int i = 0; i < 26; i++){
        printf("%c: %.2f%% \n", (char) ('a' + i), ((freqData.frequencies[i]) * 100));
    }
    printf("%d total letters analyzed\n", freqData.total);

    printf("%.4f IC_english\n", CalcIC(&freqData));  
}