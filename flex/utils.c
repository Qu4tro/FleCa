#include "utils.h"

char* str_append(char* fst, char* snd) {

    int len;
    char* out;

    if (fst == NULL){
        fst = strdup("");
    }
    if (snd == NULL){
        snd = strdup("");
    }

     len = sizeof(char) * (strlen(fst) + strlen(snd) + 1);
     out = malloc(len);
     sprintf(out, "%s%s", fst, snd);

     return out;
}

