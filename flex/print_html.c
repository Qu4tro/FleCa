#include "print_html.h"

void print_head(){

    printf(""
    "\t<head>\n\n"
        "\t\t<meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\">\n"
        "\t\t<meta charset=\"UTF-8\">\n"
        "\t\t<title>FleCa - Flex Comment Analyser</title>\n"
        "\t\t<meta name=\"Author\" content=\"Célia Natália, Tiago Cunha e Xavier Francisco\">\n"
        "\t\t<meta name=\"Description\" content=\"FleCa é um analisador de comentários tipo-Java feita por um filtro de texto Flex.\">\n"
        "\t\t<meta name=\"Keywords\" content=\"fleca, analisador, comentaários, linux, unix\">\n"
        "\t\t<meta name=\"viewport\" content=\"initial-scale=1\">\n"
        "\t\t<link rel=\"stylesheet\" href=\"https://cmus.github.io/reset-min.css\">\n"
        "\t\t<link rel=\"stylesheet\" href=\"https://cmus.github.io/fonts-min.css\">\n"
        "\t\t<link rel=\"stylesheet\" href=\"https://cmus.github.io/modern.css\">\n"
        "\t\t<link rel=\"alternate\" type=\"application/atom+xml\" href=\"https://github.com/cmus/cmus/commits/master.atom\" title=\"cmus project updates\">\n"

        "\t\t<style type=\"text/css\" media=\"screen\">\n\n"

            "\t\t\tcode {\n"
                "\t\t\t\tfont-family: Monaco, Consolas, \"Andale Mono\", \"DejaVu Sans Mono\", monospace;\n"
                "\t\t\t\tfont-size: 95%;\n"
                "\t\t\t\tcolor: #999999;\n"
                "\t\t\t\tline-height: 100%;\n"
                "\t\t\t\twhite-space: pre;\n"
                "\t\t\t\twhite-space: pre-wrap;\n"
                "\t\t\t\twhite-space: -moz-pre-wrap;\n"
                "\t\t\t\twhite-space: -o-pre-wrap;\n"
                "\t\t\t\tbackground: #181818;\n"
            "\t\t\t\t}\n\n"

            "\t\t\t\t#content code {\n"
                "\t\t\t\tdisplay: block;\n"
                "\t\t\t\tpadding: 0.5em 1em;\n"
                "\t\t\t\tborder: 1px solid #bebab0;\n"
            "\t\t\t\t}\n\n"

            "\t\t\t\tul.navbar{\n"
                "\t\t\t\tfont-family: \"linux biolinum o\", \"linux libertine\", \"times new roman\", \"liberation serif\", serif;\n"
                "\t\t\t\tcolor: #999999;\n"
                "\t\t\t\tline-height: 300%;\n"
                "\t\t\t\tfont-size: 1.2em;\n"
                "\t\t\t\tletter-spacing: 1px;\n"
                "\t\t\t\ttext-transform: uppercase;\n"
                "\t\t\t\tmargin: 0;\n"
                "\t\t\t\tmargin-top: 20px;\n"
                "\t\t\t\tpadding-bottom: 0.5em;\n"
                "\t\t\t\tborder-bottom: 2px solid #9ea191;\n"
            "\t\t\t\t}\n\n"

            "\t\t\ta:visited {\n"
                "\t\t\t\tcolor: #666666;\n"
            "\t\t\t}\n"
            "\t\t\ta:link {\n"
                "\t\t\t\tcolor: #666666;\n"
            "\t\t\t}\n\n"
              
        "\t\t</style>\n"
    "\t</head>\n");


}




void print_home(int n_of_inlines, int n_of_blocks, int n_of_docs){

    printf(""
            "\t\t\t<h2 id=\"home\" style=\"display: block;\"></h2>\n"
            "\t\t\t<div class=\"chapter\" style=\"display: block;\">\n"
                "\t\t\t\t<div class=\"tagline\">FleCa é um analisador de comentários tipo-Java feita por um filtro de texto <em>Flex</em>.</div>\n"
                "\t\t\t\t<img class=\"screenshot\" alt=\"java screenshot\" title=\"java source example\" src=\"https://imgur.com/78e9F0t.png\">\n"
                "\t\t\t\t<div class=\"tagline\">O ficheiro foi analisado e foram encontrados %d comentários inline, %d comentários em bloco e %d comentários de documentação.</div>\n"
            "\t\t\t</div>\n", n_of_inlines, n_of_blocks, n_of_docs);
}

void print_inline_comments_chapter(inline_ll* inline_linked_list){

    int i;
    int count = 1;
    inline_comment* c;

    printf(""
            "\t\t\t<h2 id=\"inline\" style=\"display: none;\">Comentários Inline</h2>\n"
            "\t\t\t<div class=\"chapter\" style=\"display: none;\">\n");


    while ((c = pop_inline(&inline_linked_list)) != NULL){

        printf("\t\t\t\t<br>Linha %d:<br>\n"
               "\t\t\t\t<code>%s</code><br>\n", c -> line, 
                                                c -> string);
    }

    printf("\t\t\t</div>\n");

}

void print_block_comments_chapter(blocks_ll* blocks_linked_list){

    block_comment* c;
    const char *languages[] = {"?", "Inglês", "Português"};

    printf(""
            "\t\t\t<h2 id=\"bloco\" style=\"display: none;\">Comentários em Bloco</h2>\n"
            "\t\t\t<div class=\"chapter\" style=\"display: none;\">\n");

    while ((c = pop_block(&blocks_linked_list)) != NULL){

        printf(""
                "\t\t\t\t<br>Linha %d-%d : Comentário em <em>%s</em><br>\n"
                "\t\t\t\t<code>\n"
                "%s"
                "\t\t\t\t</code>\n", c -> initial_line,
                                     c -> final_line,
                                     languages[c -> language],
                                     c -> string);
    }

    printf("\t\t\t</div>\n");

}

void print_documenting_comments_chapter(){

    printf(""
            "\t\t\t<h2 id=\"docs\" style=\"display: none;\">Comentários de Documentação</h2>\n"
            "\t\t\t<div class=\"chapter\" style=\"display: none;\">\n"

                "\t\t\t\t<ul class=\"navbar\">\n"
                    "\t\t\t\t\t<li><a href=\"#docs_author\">Comentários por autor</a></li>\n"
                    "\t\t\t\t\t<li><a href=\"#docs_version\">Comentários por versão</a></li>\n"
                "\t\t\t\t</ul>\n"

            "\t\t\t</div>\n");


}

void print_documenting_comments_per_author_chapter(){

    printf(""
            "\t\t\t<h2 id=\"docs_author\" style=\"display: none;\">Comentários de Documentação - Por autor</h2>\n"
            "\t\t\t<div class=\"chapter\" style=\"display: none;\">\n"

                "\t\t\t\t<br>\n"

                "\t\t\t\tPor XavierFrancisco.\n"

                "\t\t\t\t<code>\n"

                    "/**  <br>\n"
                     "*   @author XavierFrancisco <br>\n"
                     "*   @param x value of x <br>\n"
                     "*   @return y <br>\n"
                     "*   @see \"Math\" <br>\n"
                     "*   @version version1 <br>\n"
                     "*/ <br>\n"
                "\t\t\t\t</code>\n\n"

                "\t\t\t\tPor CéliaNatália.\n"
                "\t\t\t\t<code>\n"

                    "/**  <br>\n"
                     "*   @author CéliaNatália <br>\n"
                     "*   @param y value of y <br>\n"
                     "*   @return x <br>\n"
                     "*   @see \"Math\" <br>\n"
                     "*   @version version2 <br>\n"
                     "*/ <br>\n"
                "\t\t\t</code>\n\n"

           "\t\t\t</div>");

}

void print_documenting_comments_per_version_chapter(){

    printf(""
            "\t\t\t<h2 id=\"docs_version\" style=\"display: none;\">Comentários de Documentação - Por versão.</h2>\n"
            "\t\t\t<div class=\"chapter\" style=\"display: none;\">\n"

                "\t\t\t\t<br>\n"

                "\t\t\t\tVersão 1.\n"

                "\t\t\t\t<code>\n"

                    "/**  <br>\n"
                     "*   @author XavierFrancisco <br>\n"
                     "*   @param x value of x <br>\n"
                     "*   @return y <br>\n"
                     "*   @see \"Math\" <br>\n"
                     "*   @version version1 <br>\n"
                     "*/ <br>\n"
                "\t\t\t\t</code>\n\n"

                "\t\t\t\tVersão 2.\n"
                "\t\t\t\t<code>\n"

                    "/**  <br>\n"
                     "*   @author CéliaNatália <br>\n"
                     "*   @param y value of y <br>\n"
                     "*   @return x <br>\n"
                     "*   @see \"Math\" <br>\n"
                     "*   @version version2 <br>\n"
                     "*/ <br>\n"
                "\t\t\t</code>\n\n"

           "\t\t\t</div>");

}


void print_body(inline_ll* inline_linked_list, int n_of_inlines, 
                blocks_ll* blocks_linked_list, int n_of_blocks, 
                int n_of_docs){
    printf(""
    "\t<body>\n"
        "\t\t<center>\n"
            "\t\t\t<img src=\"https://i.imgur.com/pDiqAGa.png\" alt=\"logotype of FleCa\"/> \n"
        "\t\t</center>\n\n"

        "\t\t<ul id=\"navbar\">\n"
            "\t\t\t<li><a href=\"#home\">Home</a></li>\n"
            "\t\t\t<li><a href=\"#inline\">Comentários inline</a></li>\n"
            "\t\t\t<li><a href=\"#bloco\">Comentários de bloco</a></li>\n"
            "\t\t\t<li><a href=\"#docs\">Comentários de documentação</a></li>\n"
        "\t\t</ul>\n\n"

        "\t\t<div id=\"content\">\n");

    print_home(n_of_inlines, n_of_blocks, n_of_docs);

    print_inline_comments_chapter(inline_linked_list);

    print_block_comments_chapter(blocks_linked_list);
    print_documenting_comments_chapter();
    print_documenting_comments_per_author_chapter();
    print_documenting_comments_per_version_chapter();

    printf(""
        "\t\t</div>\n\n"

            "\t\t<script src=\"https://ajax.googleapis.com/ajax/libs/jquery/1.4.2/jquery.min.js\"></script>\n"
            "\t\t<script src=\"https://cmus.github.io/modern.js\"></script>\n\n"


    "\t</body>\n\n"

"</html>\n");


}

void print_html(inline_ll* inline_linked_list, int n_of_inlines, 
                blocks_ll* blocks_linked_list, int n_of_blocks, 
                int n_of_docs){

    printf("<!DOCTYPE html>\n"
           "<html lang=\"pt\">\n\n");

    print_head();
    print_body(inline_linked_list, n_of_inlines, 
               blocks_linked_list, n_of_blocks,
                                   n_of_docs);

}
