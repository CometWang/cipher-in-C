#ifndef CIPHERS_HEADER
#define CIPHERS_HEADER
/*NAME: Jia Wang ID:251041197 std:C99
 *
 * This function takes user's input and do caesar encyprt based on the key the user gives
 * It includes the error checking when there the input key is not an integer
 * */
char * caesar_encrypt(char* plaintext, int key);

/*
 * Decrypt the text based on the key
 * */
char * caesar_decrypt(char* ciphertext, int key);

/*
 * Use vigen method to encrypt based on the given string key
 * */
char * vigen_encrypt(char* ciphertext, char* key);

/*
 * Decrypt based on the given string key
 * */
char * vigen_decrypt(char* ciphertext, char* key);

/*
 * It takes the ciphertext then calculate the frequency in the string and put in the array of letters
 * */
void freq_analysis(char *ciphertext, double letters[26]);

#endif /* CIPHERS_HEADER */