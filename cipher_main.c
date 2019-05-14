#include "ciphers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Name:Jia Wang
 * Student number: 251041197:std C99
 * This is the main function for the ciphers.c it asks for the input from users
 * Then process the string and when there report an error when the input is not
 * */
int main(){
    int i,a,option, number;
    char *c,plaintext[256], *keyword=NULL;
    double letters[26];


    printf("Input plaintext:\n");
    if((fgets(plaintext,256,stdin))== NULL){

        printf("Invalid Input!");
        exit (1);
    }
    a=strlen(plaintext);
    plaintext[a-1] ='\0';
    printf("\n");
    printf("Available Ciphers:\n");
    printf("1) Caesar\n2) Vigenere\n");
    printf("\n");

    printf("Select Cipher:");
    scanf("\n %d", &option);
    printf("\n");
    /*
     * use switch statement to verify the option from the user then process the text
     * */
    switch(option){
        case 1 :
            printf("Input key as number:");

            if(!scanf("\n %d", &number)){
                printf("Invalid number!\n");
                exit(1);
            }

            printf("Plaintext:\n%s", &plaintext);
            printf("\n");
            printf("\n");

            printf("Ciphertext:\n%s", caesar_encrypt(&plaintext, number));
            c=caesar_encrypt(&plaintext, number);

            printf("\n");
            printf("\n");
            printf("Decrypted plaintext:\n%s\n ", caesar_decrypt(c, number));
            /*
             * print out the frequency
             * */

            freq_analysis(c, letters);

            printf("\n     A     B     C     D     E     F     G     H     I     J     K     L     M     N     O     P     Q     R     S     T     U     V     W     X     Y     Z     \n");
            for(i=0;i<=25;i++){
                printf(" %5.1f", *(letters+i));}
            free(c);
            break;

        case 2 :
            printf("Input key as string:\n");
            if(!scanf("\n %s", &keyword)){
                printf("Invalid key!\n");
                exit(1);
            }

            printf("\n");
            printf("Plaintext:\n%s", &plaintext);
            printf("\n");

            printf("\nCiphertext:\n%s", vigen_encrypt(&plaintext, &keyword));
            c=vigen_encrypt(&plaintext, &keyword);
            printf("\n");
            printf("\n");
            printf("Decrypted plaintext:\n%s", vigen_decrypt(c, &keyword));
            printf("\n");

            freq_analysis(c, letters);

            printf("\n     A     B     C     D     E     F     G     H     I     J     K     L     M     N     O     P     Q     R     S     T     U     V     W     X     Y     Z     \n");
            for(i=0;i<=25;i++){
                printf(" %5.1f", *(letters+i));}
            /*
             * free the allocated memory
             * */
            free(c);
            break;
        default:
            printf("Invalid choice!\n");
            exit(1);

    }


}
