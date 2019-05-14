#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#include<string.h>

/*NAME: Jia Wang ID:251041197 std:C99
 *This script includes all the functions it may need in the main function
 * */


/*
 * This function takes user's input and do caesar encyprt based on the key the user gives
 * It includes the error checking when there the input key is not an integer
 * */
char * caesar_encrypt(char* plaintext, int key){
    int length = strlen(plaintext);
    int i;
    char *new = (char *) calloc(length + 1, sizeof(char));
    /*
     * Do error checking if it fails to allocate the heap
     * */
    if (new == NULL){
        printf("Fail to allocate memory!");
        exit(1);
    }
  /*
   * transfer all the letters to uppercase
   * */
    for(i=0; i<=length; i++){

        if(isalpha(plaintext[i])){
            char c = plaintext[i];
            new[i] = toupper(c);
        } else{
            new[i] = plaintext[i];
            continue;
        }

    }
    /*Do the encrypt*/
    for(i=0; i <=length; i++) {
        if (isalpha(new[i])) {
            char c = new[i];
            int c_value = (int) c;
            new[i] = (((c_value - 'A') + key) % 26) + 'A';
            if (new[i] < 'A') {
                new[i] = 'Z' + 1 - ('A' - new[i]);
            }
        }
            else {

                continue;
            }

        }

        return new;
    }


char * caesar_decrypt(char* ciphertext, int key){
        return caesar_encrypt(ciphertext, -key);

}
/*
 * Use vigen method to encrypt based on the given string key
 * */
char * vigen_encrypt(char* ciphertext, char* key){
    int length_1, i, length_2, c, position;
    length_1=strlen(ciphertext);
    length_2=strlen(key);
    char * p;
    char *new = (char *) calloc(length_1 + 1, sizeof(char));
    if (new == NULL){
        printf("Fail to allocate memory!");
        exit(1);
    }


    for(i=0; i<=length_1; i++){
        if (isalpha(ciphertext[i])) {

            position = i % length_2;
            key[position] = toupper(key[position]);
            c = key[position] - 'A';
            p = caesar_encrypt(&ciphertext[i], c);
            new[i] = *p;
        } else{
            new[i] = ciphertext[i];
            continue;
        }

    }

    return new;
}
/*
 * Use vigen method to decrypt based on the given string key
 * */
char * vigen_decrypt(char* ciphertext, char* key){
    int length_1, i, length_2, c, position;
    length_1=strlen(ciphertext);
    length_2=strlen(key);
    char * p;
    char *new = (char *) calloc(length_1 + 1, sizeof(char));
    if (new == NULL){
        printf("Fail to allocate memory!");
        exit(1);
    }


    for(i=0; i<=length_1; i++){
        if (isalpha(ciphertext[i])) {
            position = i % length_2;
            key[position] = toupper(key[position]);
            c = key[position] - 'A';
            p = caesar_encrypt(&ciphertext[i], -c);
            new[i] = *p;
        } else{
            new[i]=ciphertext[i];
            continue;
        }

    }
    return new;
}
/*
 * It takes the ciphertext then calculate the frequency in the string and put in the array of letters
 * */
void freq_analysis(char *ciphertext, double letters[26]) {
    double a, counter=0.0;
    int  i, len = strlen(ciphertext);


    for (i = 0; i <= 25; i++) {
        *(letters + i) = 0.0;
    }

    /*count all the occurance of each letter and store it in the array*/
    for (i = 0; i < len; ++i) {
        char c = *(ciphertext+i);
        if (c >= 'A' && c <= 'Z') {
            counter++;
            *(letters + (int) (c - 'A')) += 1;
        }
    }

    /*calculate probability*/

    for (i = 0; i<=25; ++i) {
        if (*(letters + i) != 0) {
            a = *(letters + i);

            *(letters + i) = (a *100/ counter );
        } else{
            continue;
        }

    }

}

