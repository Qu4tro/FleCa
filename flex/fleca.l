%option yylineno

%{
#include <stdio.h>
#include "inline_struts.h"
#include "blocks_struts.h"
#include "docs_struts.h"
#include "utils.h"

inline_ll* inline_linked_list = NULL;
inline_comment* icomment;

char* current;

blocks_ll* blocks_linked_list = NULL;
block_comment* bcomment;

docs_ll* docs_linked_list = NULL;
docs_comment* dcomment;

unsigned int n_of_inlines = 0;
unsigned int n_of_blocks = 0;
unsigned int n_of_docs = 0;

%}


%x block docs str
%%

    /**
    This regex below tests for strings. 
    We want to ignore all strings, so there's no false comments(for example the following string: "/* //")
    */

[^\\]\"                    { BEGIN(str);} 

<str>\"                    { BEGIN(INITIAL);} 

<str>\n                    { BEGIN(INITIAL);} 

<str>[^\n\"]+              { ;} 


  /* First regex to match comments. In this case documentating comments. */

\/\*{2,}                   { BEGIN(docs); 
                             n_of_docs++;
                             dcomment = malloc(sizeof(docs_comment));
                             current = NULL;
                           }

<docs>\*\/                 { BEGIN(INITIAL);
                             dcomment -> string = strdup(current);
                             append_docs(&docs_linked_list, dcomment);
                             /* print_comment(dcomment); */
                             free(dcomment);
                             free(current);
                           }

<docs>"@author ".*\n       { dcomment -> author  = strdup(yytext + 8);}

<docs>"@version ".*\n      { dcomment -> version = strdup(yytext + 9); }

<docs>.|\n                 { current = str_append(current, yytext);}


\/\*                       { BEGIN(block); 
                             n_of_blocks++; 
                             bcomment = malloc(sizeof(block_comment));
                             bcomment -> initial_line = yylineno;
                             current = NULL;
                           }

<block>\*\/                { BEGIN(INITIAL);
                             bcomment -> final_line = yylineno;
                             bcomment -> string = strdup(current);
                             bcomment -> language = detect_lang(bcomment -> string);
                             append_block(&blocks_linked_list, bcomment);
                             free(bcomment);
                             free(current);
                           }

<block>\*[^\/]             { ;}

<block>[^\*]*              { current = str_append(current, yytext);}



 /* 
     Next inline comments
 */

^.*"//".*$                 { icomment = make_inline_comment(yytext, yylineno);
                             append_inline(&inline_linked_list, icomment);
                             free(icomment);
                             n_of_inlines++;
                           }


.|\n                       {;}

%%


int yywrap(){ 
    return(1);
}

int main(){ 
    
    yylex();
    
    print_html(inline_linked_list, n_of_inlines, blocks_linked_list, n_of_blocks, docs_linked_list, n_of_docs);

    return 0;
}



