#include <string.h>
#include <stdio.h>

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

/*
0 - successful
1 - buffer too short
*/
int VignereEncrypt(char* key, char* message, char* msgBuffer){
    int keyPos, keyLength, msgLength;

    keyLength = strlen(key);
    msgLength = strlen(message);

    if (msgLength > strlen(msgBuffer)){
        printf("Unable to encrypt as output buffer is too small.\n");
        return 1;
    }

    for(int i = 0; i < msgLength; i++){
        keyPos = i % keyLength;

        msgBuffer[i] = ShiftEnc(key[keyPos], message[i]);
    }

    return 0;
}

void VignereDecrypt(char* key, char* ciphertext, char* ctBuffer){

}

int main(int argc, char* argv[]){
    if (argc < 4){
        printf("Usage: vignere [enc/dec] [KEY] [MESSAGE]\n");
        exit(1);
    }
}