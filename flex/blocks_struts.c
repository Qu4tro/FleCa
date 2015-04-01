#include "blocks_struts.h"

void append_block(blocks_ll** linked_list, block_comment* c){

    if (*linked_list == NULL){
        (*linked_list) = malloc(sizeof(blocks_ll));
        (*linked_list) -> comment = *c;
        (*linked_list) -> next = NULL;

    } else {
        append_block(&((*linked_list) -> next), c);
    }
}

block_comment* pop_block(blocks_ll** linked_list){

    block_comment *c;
    blocks_ll* next_comment;

    if ((*linked_list) == NULL){
        return NULL;
    }

    next_comment = (*linked_list) -> next;

    c = &((*linked_list) -> comment);

    free(*linked_list);
    *linked_list = next_comment;

    return c;
}


unsigned int starts_with_word(char s[], const char word[]){

    int i = 0;

    while (word[i]) {
        if (word[i] != s[i])
            return 0;
        i++;
    }

    return i;
}

int detect_lang(char* s){

    /* English: https://en.wikipedia.org/wiki/Most_common_words_in_English
     * Portuguese: https://en.wiktionary.org/wiki/Wiktionary:Frequency_lists/Portuguese_wordlist
     */
    int i, j = 0;

    const char *english[] = {"the", "be", "to", "of", "and", "for", "in", "that", "have", "I", "it", "not", "on"};
    const char *portuguese[] = {"que", "não", "de", "um", "para", "se", "uma", "está", "com", "do", "por", "mas", "é"};
    int count_english_matches = 0;
    int count_portuguese_matches = 0;

    while (s[j]){

        for (i = 0; i < 13; ++i){
            if (starts_with_word(&s[j], english[i]))
                count_english_matches++;
        }
        for (i = 0; i < 13; ++i){
            if (starts_with_word(&s[j], portuguese[i]))
                count_portuguese_matches++;
        }

        j++;
    }

    if (count_portuguese_matches == 0 && count_english_matches == 0)
        return 0;

    if (count_english_matches > count_portuguese_matches)
        return 1;
    else 
        return 2;
}


