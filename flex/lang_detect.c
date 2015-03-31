#include <stdio.h>

int starts_with_word(char s[], char word[]){

    int i = 0;

    while (word[i]) {
        if (word[i] != s[i])
            return 0;
        i++;
    }

    return i;
}


char* detect_lang(char s[]){

    /* English: https://en.wikipedia.org/wiki/Most_common_words_in_English
     * Portuguese: https://en.wiktionary.org/wiki/Wiktionary:Frequency_lists/Portuguese_wordlist
     */
    int i, j = 0;
    char **languages = {"?", "Português", "Inglês"};

    char **english= {"the", "be", "to", "of", "and", "for", "in", "that", "have", "I", "it"};
    char **portuguese = {"que", "não", "de", "um", "para", "se", "uma", "está", "com", "do", "por", "o", "é"};
    int count_english_matches = 0;
    int count_portuguese_matches = 0;

    while (s[j]){


        for (i = 0; i < 12; ++i){
            if (starts_with_word(s, english[i]))
                count_english_matches++;
        }
        for (i = 0; i < 14; ++i){
            if (starts_with_word(s, portuguese[i]))
                count_portuguese_matches++;
        }

        j++;
    }

    if (count_portuguese_matches == 0 && count_english_matches == 0)
        return languages[0];

    if (count_english_matches > count_portuguese_matches)
        return languages[2];
    else 
        return languages[1];

}

int main(){

    char s1[] = "Olá. está tudo bem?";
    char s2[] = "Olá. está tudo bem?";
    printf("%d\n", starts_with_word(s1,s2));

    return 1;

}
