#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
       char *string;
       int line;
} inline_comment;

typedef struct node_ll_inline{
   struct node_ll_inline *next;     
   inline_comment    comment;
} inline_ll;


inline_comment* make_comment(char* str, int line){

    inline_comment* comment = malloc(sizeof(inline_comment));

    comment -> string = strdup(str);
    comment -> line = line;

    return comment;
}

void append(inline_ll** linked_list, inline_comment* c){

    if (*linked_list == NULL){
        (*linked_list) = malloc(sizeof(inline_ll));
        (*linked_list) -> comment = *c;
        (*linked_list) -> next = NULL;

    } else {
        append(&((*linked_list) -> next), c);
    }
}

inline_comment* pop(inline_ll** linked_list){

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


void print_comment(inline_comment* c){
    printf("Linha %d\n%s\n\n", c -> line, c -> string);
}

int main(){

    char s1[] = "A Célia vai faltar à aula de POO";
    char s2[] = "A Célia vai faltar à aula de CP";
    char s3[] = "A Célia vai faltar à aula de LI3";
    char s4[] = "A Célia vai faltar à aula de SO";
    char s5[] = "A Célia vai faltar à aula de MEIO";
    char s6[] = "A Célia vai faltar à aula de PL";

    inline_comment* c;

    inline_comment* c1 = make_comment(s1, 10);
    inline_comment* c2 = make_comment(s2, 12);
    inline_comment* c3 = make_comment(s3, 14);
    inline_comment* c4 = make_comment(s4, 16);
    inline_comment* c5 = make_comment(s5, 22);
    inline_comment* c6 = make_comment(s6, 24);

    inline_ll *linked_list = NULL;

    append(&linked_list, c1);
    append(&linked_list, c2);
    append(&linked_list, c3);
    append(&linked_list, c4);
    append(&linked_list, c5);
    append(&linked_list, c6);

    while ((c = pop(&linked_list)) != NULL){
        print_comment(c);
    }

    return 0;

}
