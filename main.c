#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"
#include "cbc.h"
#include "fileio.h"
#include<openssl/evp.h>
int main() {
    uint8_t key[16] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08,
                       0x09, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16};
    uint8_t iv[16]  = {0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48,
                       0x49, 0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56};

    char *fichier_entree = "cbc.txt";
    char *fichier_sortie = "cbc.enc";
    node* liste = file_to_list("cbc.txt");

    if (liste == NULL) {
        printf("Erreur");
        return 1;
    }

    printf("le contenu avant chiffrement:\n");
    display(liste);
    printf("apres chiffrement:\n");
    encryption(liste, key, iv);
    display(liste);
    printf("apres dechiffrement:\n");
    decryption(liste,key,iv);
    display(liste);
    list_to_file(fichier_sortie, ma_liste);
    printf("le fichier %s est donné",fichier_sortie);
    return 0;
}


