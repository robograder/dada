# Main Dada Engine makefile

all:	pb dada

dada:	bin/
	cat dada.sh | sed "s#CWD#${CURDIR}#" | sed "s#BINDIR#${CURDIR}/bin#" > bin/dada
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

.PHONY: test
test:
	python test/test.py bin/dada

INSTALL_DIR=/usr/local/bin
.PHONY: install
install: bin/pb
	cat dada.sh | sed "s#CWD#${CURDIR}#" | sed "s#BINDIR#${INSTALL_DIR}#"  > ${INSTALL_DIR}/dada
	chmod +x ${INSTALL_DIR}/dada
	cp bin/pb ${INSTALL_DIR}
