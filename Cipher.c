#include <stdio.h>
#include <stdint.h>

int main() {
    char choice;
    uint32_t charCount;
    uint32_t key;
    
    printf("Welcome to Cipher\n");
    printf("-----------------\n");
    printf("A-Encrypt Text\nB-Decrypt Text\nC-Find Key\nD-Exit\n");
    printf("-----------------\n");
    scanf("%c", &choice);

    if(choice == 'A'){
    encrypt(charCount, key);
    }

    

}

//PART 1: ENCRYPT//////////////////
void encrypt(uint32_t charCount, uint32_t key){
    char str[] = "text"; //input text to be encrypted

    printf("Enter the number of characters to encrypt: ");
    scanf("%u", &charCount);
    printf("Enter the key: ");
    scanf("%u", &key);
    printf("Enter the text: ");
    scanf("%s", str);
    printf("%s", str);
}
  