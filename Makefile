CC := gcc
INCLUDE := include 
SRC := src

%:
	$(CC) -I $(INCLUDE) $(SRC)/$@.c -o out && ./out

clean:
	rm -rf out
