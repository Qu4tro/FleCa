#include "utils.h"

char* str_append(char* fst, char* snd) {

    if (fst == NULL){
        fst = strdup("");
    
    }
    if (snd == NULL){
        snd = strdup("");
    }

     int len = sizeof(char) * (strlen(fst) + strlen(snd));
     char* out = (char*)malloc(len);
     sprintf(out, "%s%s", fst, snd);

     return out;
}

