/* testtwisted .c zum Testen der Belegaufgabe 2 */
#include <stdio.h> // fuer printf ()
#include <stdlib.h> // fuer free

char* twisted (const char* const str); // Deklaration der Aufgabenfunktion

int main (int carg , const char** varg ){
    carg = 2;
    printf("%d", carg);
    const char text[] = "!$%"; 
    if (carg != 2){
        return -1;
    }
    char* twstr = twisted(text);
    // char* twstr = twisted(varg[1]);
    printf ("Die verwurfelte Version von \"%s\" ist \"%s\".\n",varg[1], twstr); // gibt Ergebnis aus
    free (twstr);
    return 0; // 0 bedeutet alles okay
}

unsigned long GetStringLength(const char* InString){ // Diese Funktion ermittelt die Länge der Zeichenfolge, die in main übergeben wird

    if(InString[0] == 0) return 1;  
    return 1 + GetStringLength(InString + 1);
}

void swap(char *x, char *y){ 
    char temp = *x;
    *x = *y;
    *y = temp;
}

void reverse(char *str, int k, int i){  //kehren Sie die Reihenfolge um, in der das Wort geschrieben wird

    if (*(str + k) == '\0') {
        return;
    }
    reverse(str, k + 1, 0);
    if (i <= k) {
        swap(&str[i++], &str[k]);
    }
}

char change_lether(char character){ //Vertausche die Buchstaben a-z, b-y, ...
    
    if(character > 47 && character < 58){
        return (57 - (character - 48)); 
    }else if(character < 65 || character > 122){ 
        return character;
    }else if(character > 90 && character < 97){ 
        return character;
    }else if(character > 64 && character < 91){ // prüfen Sie, ob es sich um Großbuchstaben handelt
        return (90 - (character - 65));
    }else if(character > 96 && character < 123){// prüfen Sie, ob es sich um Kleinbuchstaben handelt
        return (122 - (character - 97));
    }
    return character;
}

void CopyStringIntoString(char* InOutString, char* InString){
    
    if(InString[0] == 0){
        InOutString[0] = 0;
        return;
    }
    InOutString[0] = InString[0];
    CopyStringIntoString(InOutString + 1, InString + 1);
}

char* twisted (const char* const str){
    
    char *res = calloc(GetStringLength(str), sizeof(char));
    if(str[0] != 0){
        if(str[0] == ' '){
            res[0] = str[0];
        }else{
            res[0] = change_lether(str[0]);
        }
        char* ret = twisted(str + 1);
        CopyStringIntoString(res + 1, ret);
        free(ret);
    }else{
        res[0] = str[0];
    }
    reverse(res, 0, 0);
    return res;
}