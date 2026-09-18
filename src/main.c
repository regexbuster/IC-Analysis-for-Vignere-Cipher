#import <stdlib.h>
#import <string.h>

#import "frequency.h"
#import "vignere.h"

int main(int argc, char *argv[]){
    if (argc < 2){
        printf("Usage: analysis [OPTION]...\n");
        exit(1);
    }
    
    if (strcmp(argv[2], "frequency")){

    } else if (strcmp(argv[2], "vignere")){

    } else {
        printf("Usage: analysis [OPTION]...");
        exit(1);
    }
}