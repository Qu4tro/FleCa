#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *string;
    char *author;
    char *version;
} docs_comment;

typedef struct node_ll_docs{
    struct node_ll_docs *next;     
    docs_comment         comment;
} docs_ll;

void print_comment(docs_comment* c);

void print_comments(docs_ll* linked_list);

void append_docs(docs_ll** linked_list, docs_comment* c);

docs_comment* pop_docs(docs_ll** linked_list);

docs_ll* sort_by_authors(docs_ll* linked_list);

docs_ll* sort_by_version(docs_ll* linked_list);
