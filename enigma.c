#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char lacznica[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
char dalej[] = {"FRP"};

char pierscienie[3][26] = { "EKMFLGDQVZNTOWYHXUSPAIBRCJ",
                            "AJDKSIRUXBLHWTMCQGZNPYFVOE",
                            "BDFHJLCPRTXVZNYEIWGAKMUSQO"};

int kolejnosc[3] = { 2, 1, 3 };

char p1[] = {"AJDKSIRUXBLHWTMCQGZNPYFVOE"};
char p2[] = {"EKMFLGDQVZNTOWYHXUSPAIBRCJ"};
char p3[] = {"BDFHJLCPRTXVZNYEIWGAKMUSQO"};
/*
char p1[26], p2[26], p3[26];

void przyporzadkuj(){
    for(i = 0; i < 3; i++){
            switch(i){
                case 0:
                    for(j = 0; j < 26; j++)
                        p1[j] = pierscienie[kolejnosc[i] - 1][j];
                    break;
                case 1:
                    for(j = 0; j < 26; j++)
                        p2[j] = pierscienie[kolejnosc[i] - 1][j];
                    break;
                case 2:
                    for(j = 0; j < 26; j++)
                        p3[j] = pierscienie[kolejnosc[i] - 1][j];
                    break;

            }
    }
}
*/
void obroc(char p[]){
    int i;
    char swap = p[0];
    for(i = 0; i < 26 - 1; i++){
        p[i] = p[i + 1];
    }
    p[25] = swap;
}

char pierscien1(char l){
    int pozycja = (int)(l - 'A'); 
    l = p1[pozycja];
    return l;
} 

char pierscien2(char l){
    int pozycja = (int)(l - 'A'); 
    l = p2[pozycja];
    return l;
}

char pierscien3(char l){
    int pozycja = (int)(l - 'A'); 
    l = p3[pozycja];
    return l;
}



void szyfruj(char t[], int rozmiar){
    int i;
    for(i = 0; i < rozmiar; i++){
        t[i] = pierscien3(pierscien2(pierscien1(t[i])));
        
        if(p1[0] == dalej[0]){
            obroc(p2);
            if(p2[1] == dalej[1]){
                obroc(p3);
            }
        }
        obroc(p1);
    }
}

void deszyfruj(char t[]){

}




int main(){
    // czy szyrujemy czy deszyfrujemy

    // wczytujemy tekst
        // usun puste znaki (entery spacje)
        // zmien litery na duże
    char tekst[] = {"JEBACXSTUDIA"};
    
    // początkowe ustawienie pierscieni

    // jezeli szyfrujemy
    szyfruj(tekst, strlen(tekst));

    // jeżeli deszyfrujemy
    // deszyfruj();

    // wyświetlamy / zapisujemy do pliku

    fputs(tekst, stdout);
}
