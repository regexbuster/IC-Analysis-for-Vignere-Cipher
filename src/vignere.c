#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void strToUpper(char* str){
    for (int i = 0; i < strlen(str); i++){
        str[i] = toupper(str[i]);
    }
}

void strToLower(char* str){
    for (int i = 0; i < strlen(str); i++){
        str[i] = tolower(str[i]);
    }
}

char ShiftEnc(char key, char msgLetter){
    int absKey, absLetter, shifted;
    absKey = (int)(key - 'a');
    absLetter = (int)(msgLetter - 'a');

    shifted = (absKey + absLetter) % 26;

    return (char)('A' + shifted);
}

char ShiftDec(char key, char ctLetter){
    int absKey, absLetter, shifted;
    absKey = (int)(key - 'A');
    absLetter = (int)(ctLetter - 'A');

    shifted = (absLetter - absKey);

    if (shifted < 0) {
        shifted += 26;
    }

    return (char)('a' + shifted);
}

int VignereEncrypt(char* key, char* message, char* msgBuffer){
    int keyPos, keyLength, msgLength;

    keyLength = strlen(key);
    msgLength = strlen(message);

    // if (msgLength > strlen(msgBuffer)){
    //     printf("Unable to encrypt as output buffer is too small.\n");
    //     return 1;
    // }

    for(int i = 0; i < msgLength; i++){
        keyPos = i % keyLength;

        msgBuffer[i] = ShiftEnc(key[keyPos], message[i]);
    }

    return 0;
}

int VignereDecrypt(char* key, char* ciphertext, char* ctBuffer){
    int keyPos, keyLength, msgLength;

    keyLength = strlen(key);
    msgLength = strlen(ciphertext);

    // if (msgLength > strlen(msgBuffer)){
    //     printf("Unable to encrypt as output buffer is too small.\n");
    //     return 1;
    // }

    for(int i = 0; i < msgLength; i++){
        keyPos = i % keyLength;

        ctBuffer[i] = ShiftDec(key[keyPos], ciphertext[i]);
    }

    return 0;
}

int main(int argc, char* argv[]){
    if (argc < 4){
        printf("Usage: vignere [enc/dec] [KEY] [MESSAGE]\n");
        exit(1);
    }

    if (!strcmp("enc", argv[1])){
        strToLower(argv[2]);
        strToLower(argv[3]);
        char* buffer = malloc(strlen(argv[3]) * sizeof(char));

        VignereEncrypt(argv[2], argv[3], buffer);

        printf("ENC: %s\n", buffer);
        free(buffer);
    } else if (!strcmp("dec", argv[1])){
        strToUpper(argv[2]);
        strToUpper(argv[3]);
        char* buffer = malloc(strlen(argv[3]) * sizeof(char));

        VignereDecrypt(argv[2], argv[3], buffer);

        printf("DEC: %s\n", buffer);
        free(buffer);
    } else {
        printf("Usage: vignere [enc/dec] [KEY] [MESSAGE]\n");
        printf("Unknown option: %s\n", argv[1]);
        exit(1);
    }
}