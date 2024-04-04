# Jtest

**Jtest** is a unit testing framework built in c. It is used to write test-cases on c programs.

#### Running the tests

- add the test files in makefile

```makefile
run:
	./a

build:
	gcc \
	test/a.c \
	test/b.c \
	Main.c \
	-o a
```
- execute make command
  
```bash
make
```
  