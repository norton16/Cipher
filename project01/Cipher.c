#include <stdio.h>
#include <stdint.h>
#include <string.h>

int decToBin(int x){
    int bin = 0;
    int remainder;
    int i = 1;
    int count = 1;
    while (x!=0)
        {
            remainder = x % 2;
            count++;
            x /= 2;
            bin += (remainder*i);
            i *= 10;
        }
        return bin;
}
int binToDec(char num[]){
    int ret = 0;
    int x = 0;
    char h;
    size_t len = strlen(num);
    for (int i = 0; i < len; ++i) {
        ret <<= 1;
        ret += num[i] - '0';
    }
    return ret;
}

//PART 1: ENCRYPT//////////////////////////////////////////////////////////////////////////
void encrypt(uint32_t charCount, uint32_t key){
    char utext[charCount];
    int etext[charCount * 8];
    int shift = 0;

    uint32_t byte1 = (key >> 24);           

    uint32_t byte2 = (key >> 16) & 0xff;   
   
    uint32_t byte3 = (key >> 8)  & 0xff;  
   
    uint32_t byte4 = key & 0xff;    

    printf("Enter the text: ");
    //input text
    scanf(" %[^\n]", utext);
    printf("The encrypted text is: ");

    for (int i = 0; i < charCount; i++) 
    {
        if(shift == 4){
            shift = 0;
        }
        if(utext[i] == ' ')
        {
            printf(" ");
            continue;
        }
    
    if(shift == 0){
        etext[i] = utext[i] ^ byte1; 
        printf("%08d", decToBin(etext[i])); 
    }
    if(shift == 1){
        etext[i] = utext[i] ^ byte2; 
        printf("%08d", decToBin(etext[i])); 
    }
    if(shift == 2){
        etext[i] = utext[i] ^ byte3; 
        printf("%08d", decToBin(etext[i])); 
    }
    if(shift == 3){
        etext[i] = utext[i] ^ byte4; 
        printf("%08d", decToBin(etext[i])); 
    }
    shift++;
    }
  printf("\n");
}

//PART 2: DECRYPT///////////////////////////////////////////////////////////////////////
void decrypt(uint32_t charCount, uint32_t key){
    char utext[charCount];
    char bintext[charCount];
    int etext[charCount * 8];
    int shift = 0;
    int octa = 0;
    char octaArr[8];

    uint32_t byte1 = (key >> 24);           
                                             
    uint32_t byte2 = (key >> 16) & 0xff;    
                                              
    uint32_t byte3 = (key >> 8)  & 0xff;    

    uint32_t byte4 = key & 0xff;    

    printf("Enter the encrypted text: ");
    //input text
    scanf(" %[^\n]", utext);
    printf("The decrypted text is: ");

    for (int i = 0; i < charCount; i++){
        bintext[i] = utext[i];
    }

    for (int i = 0; i < charCount; i++){
        if(shift == 4){
            shift = 0;
        }
        if(bintext[i] == ' '){
            printf(" ");
            continue;
        }

        octaArr[octa] = bintext[i];
        octa++;

        if(octa == 8){

            if(shift == 0){
            int x = binToDec(octaArr);
            printf("%c", (x ^ byte1));
            }

            if(shift == 1){
            int x = binToDec(octaArr);
            printf("%c", (x ^ byte2));
            }

            if(shift == 2){
            int x = binToDec(octaArr);
            printf("%c", (x ^ byte3));
            }
            
            if(shift == 3){
            int x = binToDec(octaArr);
            printf("%c", (x ^ byte4));
            }
            shift++;
            octa = 0;
       }
    }
  printf("\n"); 
}

//PART 3: FIND KEY//////////////////////////////////////////////////////////////////////
uint32_t findKey(unsigned char keyE[32], unsigned char keyD[4]){

      char key1[9];
      char key2[9];
      char key3[9];
      char key4[9];

        // int ret1 = 0;
        // ret1 <<= 1;
        // ret1 += keyD[0] - '0';
        
        // int ret2 = 0;
        // ret2 <<= 1;
        // ret2 += keyD[1] - '0';
       
        // int ret3 = 0;
        // ret3 <<= 1;
        // ret3 += keyD[2] - '0';
       
        // int ret4 = 0;
        // ret4 <<= 1;
        // ret4 += keyD[3] - '0';

    key1[0] = keyE[0];
    key1[1] = keyE[1];
    key1[2] = keyE[2];
    key1[3] = keyE[3];
    key1[4] = keyE[4];
    key1[5] = keyE[5];
    key1[6] = keyE[6];
    key1[7] = keyE[7];
    key1[8] = '\0';
    
     key2[0] = keyE[8];
     key2[1] = keyE[9];
     key2[2] = keyE[10];
     key2[3] = keyE[11];
     key2[4] = keyE[12];
     key2[5] = keyE[13];
     key2[6] = keyE[14];
     key2[7] = keyE[15];
     key2[8] = '\0';
    
    key3[0] = keyE[16];
    key3[1] = keyE[17];
    key3[2] = keyE[18];
    key3[3] = keyE[19];
    key3[4] = keyE[20];
    key3[5] = keyE[21];
    key3[6] = keyE[22];
    key3[7] = keyE[23];
    key3[8] = '\0';
    
    key4[0] = keyE[24];
    key4[1] = keyE[25];
    key4[2] = keyE[26];
    key4[3] = keyE[27];
    key4[4] = keyE[28];
    key4[5] = keyE[29];
    key4[6] = keyE[30];
    key4[7] = keyE[31];
    key4[8] = '\0';

    uint32_t x1 = decToBin(binToDec(key1) ^ keyD[0]);
    uint32_t x2 = decToBin(binToDec(key1) ^ keyD[1]);
    uint32_t x3 = decToBin(binToDec(key1) ^ keyD[2]);
    uint32_t x4 = decToBin(binToDec(key1) ^ keyD[3]);

    int xArr[4];
    xArr[0] = x1;
    xArr[1] = x1;
    xArr[2] = x1;
    xArr[3] = x1;


         printf("%d\n", binToDec(xArr));

    
    printf("\n");
}    

int main() {
    while (1){
    char choice;
    uint32_t charCount;
    uint32_t key;
    unsigned char keyE[33]; 
    unsigned char keyD[5]; 

    printf("Welcome to Cipher\n");
    printf("-----------------\n");
    printf("A-Encrypt Text\nB-Decrypt Text\nC-Find Key\nD-Exit\n");
    printf("-----------------\n");
    printf("Select an option: ");
    scanf(" %[^\n]", &choice);

    if(choice == 'A'){    
    printf("Enter the number of characters to encrypt: ");
    scanf("%u", &charCount);
    printf("Enter the key: ");
    scanf("%u", &key);
    encrypt(charCount, key);
    }

    if(choice == 'B'){
    printf("Enter the number of characters to decrypt: ");
    scanf("%u", &charCount);
    printf("Enter the key: ");
    scanf("%u", &key);
    decrypt(charCount, key);
    }

    if(choice == 'C'){
    printf("Enter keyE: ");
    fgetc(stdin);
    fgets(keyE, 33, stdin);
    printf("Enter keyD: ");
    fgetc(stdin);
    fgets(keyD, 5, stdin);
    findKey(keyE, keyD);
    }

    if(choice == 'D'){
        break;
    }
    if(choice != 'A' && choice != 'B' && choice != 'C' && choice != 'D'){
    printf("Invalid Input\n");
    }
    }
}


  