# Main Dada Engine makefile


all:	pb

pb:	bin/pb

bin/pb:	bin/ src/pb
	mv src/pb bin/pb

bin/:
	mkdir -p bin

src/pb:
	$(MAKE) -C src

clean:
	( cd src ; make clean )

