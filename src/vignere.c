#include <string.h>

/*
0 - successful
1 - buffer too short
*/
int VignereEncrypt(char* key, char* message, char* msgBuffer){
    int keyItr, keyLength, msgLength;

    keyLength = strlen(key);
    msgLength = strlen(message);

    if (msgLength > strlen(msgBuffer)){
        printf("Unable to encrypt as output buffer is too small.\n");
        return 1;
    }

    for(int i = 0; i < msgLength; i++){

    }
}

void VignereDecrypt(char* key, char* ciphertext, char* ctBuffer){

}

int main(){
    
}