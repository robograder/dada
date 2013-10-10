# Main Dada Engine makefile


all:	pb dada

dada:	bin/
	cp dada.sh bin/dada
	chmod +x bin/dada

pb:	bin/ src/pb
	mv src/pb bin/pb

bin/:
	mkdir -p bin

src/pb:
	$(MAKE) -C src

clean:
	( cd pydada; rm -f *.pyc )
	( cd src ; make clean )

