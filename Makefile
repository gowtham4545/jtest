run:
	./a

build:
	gcc \
	test/a.c \
	test/b.c \
	Main.c \
	-o a