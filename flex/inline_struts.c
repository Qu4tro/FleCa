#include "inline_struts.h"

inline_comment* make_inline_comment(char* str, int line){

    inline_comment* comment = malloc(sizeof(inline_comment));

    comment -> string = strdup(str);
    comment -> line = line;

    return comment;
}

void append_inline(inline_ll** linked_list, inline_comment* c){

    if (*linked_list == NULL){
        (*linked_list) = malloc(sizeof(inline_ll));
        (*linked_list) -> comment = *c;
        (*linked_list) -> next = NULL;

    } else {
        append_inline(&((*linked_list) -> next), c);
    }
}

inline_comment* pop_inline(inline_ll** linked_list){

    inline_comment *c;
    inline_ll* next_comment;

    if ((*linked_list) == NULL){
        return NULL;
    }

    next_comment = (*linked_list) -> next;

    c = &((*linked_list) -> comment);

    free(*linked_list);
    *linked_list = next_comment;

    return c;
}


