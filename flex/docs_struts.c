#include "docs_struts.h"

void print_comment(docs_comment* c){

    printf("Autor: %s\n", c -> author);
    printf("Versão %s\n", c -> version);
    printf("Comentários: \n%s\n", c -> string);

}

void print_comments(docs_ll* linked_list){
    docs_comment *c;
    while ((c = pop_docs(&linked_list)) != NULL){
        print_comment(c);
    }
}

void append_docs(docs_ll** linked_list, docs_comment* c){

    if (*linked_list == NULL){
        (*linked_list) = malloc(sizeof(docs_ll));
        (*linked_list) -> comment = *c;
        (*linked_list) -> next = NULL;

    } else {
        append_docs(&((*linked_list) -> next), c);
    }
}

docs_comment* pop_docs(docs_ll** linked_list){

    docs_comment *c;
    docs_ll* next_comment;

    if ((*linked_list) == NULL){
        return NULL;
    }

    next_comment = (*linked_list) -> next;

    c = &((*linked_list) -> comment);

    free(*linked_list);
    *linked_list = next_comment;

    return c;
}


int cmp_by_authors(docs_comment* c1, docs_comment* c2){
    return strcmp(c1->author, c2->author);
}

void insert_by_authors(docs_ll** lt, docs_comment* c){
    docs_ll* new_node;

    if(*lt == NULL || (*lt)->next == NULL) {
        append_docs(lt, c);
    } else {
        if(cmp_by_authors(&(*lt)->next->comment, c) > 0) {
            new_node = malloc(sizeof(docs_ll));
            new_node->comment = *c;
            new_node->next = (*lt)->next;
            (*lt)->next = new_node;
        } else {
            insert_by_authors(&(*lt)->next, c);
        }
    }

}

docs_ll* sort_by_authors(docs_ll* ll){
    docs_ll* aux = ll; //LISTA LIGADA AUXILIAR
    docs_ll* temp = NULL; //Lista LIGADA PARA ORD
  
    while(aux){
        insert_by_authors(&temp,&aux->comment);
        aux = aux -> next;
    }

    return temp;
}


int cmp_by_version(docs_comment* c1, docs_comment* c2){
    return strcmp(c1 -> version, c2 -> version);
}

void insert_by_version(docs_ll** lt, docs_comment* c){
    docs_ll* new_node;

    if(*lt == NULL || (*lt) -> next == NULL) {
        append_docs(lt, c);
    } else {
        if (cmp_by_version(&(*lt)->next->comment, c) > 0) {
            new_node = malloc(sizeof(docs_ll));
            new_node->comment = *c;
            new_node->next = (*lt) -> next;
            (*lt) -> next = new_node;
        } else {
            insert_by_version(&(*lt) -> next, c);
        }
    }

}

docs_ll* sort_by_version(docs_ll* ll){
    docs_ll* aux = ll; 
    docs_ll* temp = NULL; 
  
    while(aux){
        insert_by_version(&temp, &aux -> comment);
        aux = aux -> next;
    }

    return temp;
}
