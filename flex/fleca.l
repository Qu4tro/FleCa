%option yylineno

%{
#include <stdio.h>


%}


%x block docs str
%%

    /**
    This regex below tests for strings. 
    We want to ignore all strings, so there's no false comments(for example the following string: "/* //")
    */

[^\\]\"             { BEGIN(str); printf("<string>%s", yytext + 1);}

<str>\"             { BEGIN(INITIAL); printf("%s</string>\n", yytext);}

<str>\n             { BEGIN(INITIAL); printf("%s</string(newline)>\n", yytext);}

<str>[^\n\"]+       { printf("%s", yytext);} 


  /* First regex to match comments. In this case documentating comments.
 */

\/[\*]{2,}             { BEGIN(docs); printf("<docs>");}

<docs>\*\/             { BEGIN(INITIAL); printf("</docs>\n");}

<docs>[^\*]*           { ECHO;}


\/\*                   { BEGIN(block); printf("<block line=%d>", yylineno);}

<block>\*\/             { BEGIN(INITIAL); printf("</block line=%d>\n", yylineno);}

<block>[^\*]*           { ECHO;}




 /* Next block comments

\/\*[^\*]*\*\/                   {printf("Block comments:\n%s\n", yytext);}

 */

 /* Next inline comments

 */
^.*"//".*$              {printf("Inline comments (Line %d):\n%s\n", yylineno, yytext);}


.|\n                        {;}

%%


int yywrap(){ 
    return(1);
}

int main(){ 
    
  //test 1 2 3
    yylex();

    return 0;
}



