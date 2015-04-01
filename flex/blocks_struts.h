#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *string;
    int initial_line;
    int final_line;
    int language;
} block_comment;

typedef struct node_ll_blocks{
    struct node_ll_blocks *next;     
    block_comment         comment;
} blocks_ll;



void append_block(blocks_ll** linked_list, block_comment* c);

block_comment* pop_block(blocks_ll** linked_list);

int detect_lang(char* s);
