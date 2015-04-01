all:
	flex fleca.l && gcc lex.yy.c inline_struts.c blocks_struts.c print_html.c utils.c -o fleca


noFlex:
	gcc lex.yy.c inline_struts.c blocks_struts.c print_html.c utils.c -o fleca

debug:
	flex fleca.l && gcc --debug lex.yy.c inline_struts.c blocks_struts.c print_html.c utils.c -o fleca

clean:
	rm fleca lex.yy.c a.out *.html *.o
