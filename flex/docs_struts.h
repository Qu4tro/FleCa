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

void append_docs(docs_ll** linked_list, docs_comment* c);

docs_comment* pop_docs(docs_ll** linked_list);

docs_ll* sort_by_authors(docs_ll* linked_list);

docs_ll* sort_by_version(docs_ll* linked_list);

int cmp_by_authors(docs_comment* c1, docs_comment* c2);

int cmp_by_version(docs_comment* c1, docs_comment* c2);
