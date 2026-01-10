#include <stdio.h>

void decrypt_caesar(char text[], int key) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = (text[i] - 'a' - key + 26) % 26 + 'a';
        } 
        else if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = (text[i] - 'A' - key + 26) % 26 + 'A';
        }
    }
}

int main() {
    char message[] = "Khoor Zruog"; // "Hello World" chiffré
    int key = 3;

    decrypt_caesar(message, key);
    printf("Message déchiffré : %s\n", message);

    return 0;
}
