#include <stdio.h>

int starts_with_word(char *s, char *word){

    while (*word) {
        if (*word != *s)
            return 0;
        word++; 
        s++;
    }

    return 1;
}

int next_word(char *word){

    int size = 0;

    while ((*(word + size) != ' ') && *word)
        size++;

    while (!((*(word + size) >= 'A' && *(word + size) <= 'Z') || (*(word + size) >= 'a' && *(word + size) <= 'z')) && (*word))
        size++;

    return size;

}

char* detect_lang(char* s){

    /* English: https://en.wikipedia.org/wiki/Most_common_words_in_English
     * Portuguese: https://en.wiktionary.org/wiki/Wiktionary:Frequency_lists/Portuguese_wordlist
     */
    int i;
    char *languages[] = {"?", "Português", "Inglês"};

    char *english[] = {"the", "be", "to", "of", "and", "for", "in", "that", "have", "I", "it"};
    char *portuguese[] = {"que", "não", "de", "um", "para", "se", "uma", "está", "com", "do", "por", "o", "é"};
    int count_english_matches = 0;
    int count_portuguese_matches = 0;

    while (*s){

        for (i = 0; i < 12; ++i){
            if (starts_with_word(s, english[i]))
                count_english_matches++;
        }
        for (i = 0; i < 14; ++i){
            if (starts_with_word(s, portuguese[i]))
                count_portuguese_matches++;
        }

        s += next_word(s);
    }


    return languages[0];
}

int main(){

    char s[] = "Olá. está tudo bem?";
    printf("%s\n", detect_lang(s));

    return 1;

}
