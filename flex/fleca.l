%option yylineno

%{
#include <stdio.h>
#include "inline_struts.h"

inline_ll* inline_linked_list = NULL;
inline_comment* comment;

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

[^\\]\"             { BEGIN(str);} /* printf("<string>%s", yytext + 1);} */

<str>\"             { BEGIN(INITIAL);} /* printf("%s</string>\n", yytext);} */

<str>\n             { BEGIN(INITIAL);} 

<str>[^\n\"]+       {;} /*{ printf("%s", yytext);} */


  /* First regex to match comments. In this case documentating comments. */

\/[\*]{2,}             { BEGIN(docs); n_of_docs++;}

<docs>\*\/             { BEGIN(INITIAL);}

<docs>[^\*]*           {;}


\/\*                   { BEGIN(block); n_of_blocks++;}

<block>\*\/             { BEGIN(INITIAL);}

<block>[^\*]*           {;}



 /* Next block comments

\/\*[^\*]*\*\/                   {printf("Block comments:\n%s\n", yytext);}

 */

 /* Next inline comments

^.*"//".*$              {printf("Inline comments (Line %d):\n%s\n", yylineno, yytext);}
 */

^.*"//".*$              {comment = make_inline_comment(yytext, yylineno);
                         append_inline(&inline_linked_list, comment);
                         n_of_inlines++;
                        }


.|\n                        {;}

%%


int yywrap(){ 
    return(1);
}

int main(){ 
    
  //test 1 2 3
    yylex();
    print_html(inline_linked_list, n_of_inlines, n_of_blocks, n_of_docs);


    return 0;
}



