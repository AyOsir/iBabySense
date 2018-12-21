#include<stdio.h>
#include<string.h>

int main(){

  // Plaintext
    char msg[] = "MEDGAREVERSCOLLEGE";
  //The person sending the message chooses a keyword and repeats it until it matches the length of the plaintext, for example, "HELLO"
    char key[] = "HELLO";
    int msgLen = strlen(msg), keyLen = strlen(key), i, j;

    char newKey[msgLen], encryptedMsg[msgLen], decryptedMsg[msgLen];

    //generating new key = HELLOHELLOHELLOHEL
    // The first letter of the plaintext, M, is enciphered using the alphabet in row H, which is the first letter of the key. This is done by looking at the letter in row H and column M of the Vigenere square, namely H. Similarly, for the second letter of the plaintext, the second letter of the key is used; the letter at row E and column E is I. The rest of the plaintext is enciphered in a similar fashion:
    for(i = 0, j = 0; i < msgLen; ++i, ++j){
        if(j == keyLen)
            j = 0;

        newKey[i] = key[j];
    }

    newKey[i] = '\0';

    //encryption
    for(i = 0; i < msgLen; ++i)
        encryptedMsg[i] = ((msg[i] + newKey[i]) % 26) + 'A'; //convert into alphabets

    encryptedMsg[i] = '\0';

    //decryption
    for(i = 0; i < msgLen; ++i)
        decryptedMsg[i] = (((encryptedMsg[i] - newKey[i]) + 26) % 26) + 'A'; //convert into alphabets

    decryptedMsg[i] = '\0';

    printf("Original Message: %s", msg);
    printf("\nKey: %s", key);
    printf("\nNew Generated Key: %s", newKey);
    printf("\nEncrypted Message: %s", encryptedMsg);
    printf("\nDecrypted Message: %s", decryptedMsg);

    return 0;
}