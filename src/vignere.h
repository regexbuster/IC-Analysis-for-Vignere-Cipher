#pragma once

void strToUpper(char* str);

void strToLower(char* str);

char ShiftEnc(char key, char msgLetter);

char ShiftDec(char key, char ctLetter);

int VignereEncrypt(char* key, char* message, char* msgBuffer);

int VignereDecrypt(char* key, char* ciphertext, char* ctBuffer);