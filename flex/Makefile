all: struts.o
	flex fleca.l && gcc lex.yy.c struts.c print_html.c -o fleca

clean:
	rm fleca lex.yy.c a.out a.html
