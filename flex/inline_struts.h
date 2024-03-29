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


inline_comment* make_inline_comment(char* str, int line);

void append_inline(inline_ll** linked_list, inline_comment* c);

inline_comment* pop_inline(inline_ll** linked_list);

