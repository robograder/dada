# Main Dada Engine makefile

all:	pb dada

.PHONY: pb dada release
pb:	bin/pb
dada:	bin/dada

release:
	$(MAKE) -C src y.tab.c
	$(MAKE) -C src lex.yy.c

bin/dada:	bin/
	cat dada.sh | sed "s#CWD#${CURDIR}#" | sed "s#BINDIR#${CURDIR}/bin#" > bin/dada
	chmod +x bin/dada

bin/pb:	bin/ src/pb
	cp src/pb bin/pb

bin/:
	mkdir -p bin

src/pb:
	$(MAKE) -C src

clean:
	( cd pydada; rm -f *.pyc )
	$(MAKE) -C src clean
	rm -f bin/*


.PHONY: test
test: bin/dada pb
	python test/test.py bin/dada

INSTALL_DIR=/usr/local/bin
.PHONY: install
install: bin/pb
	cat dada.sh | sed "s#CWD#${CURDIR}#" | sed "s#BINDIR#${INSTALL_DIR}#"  > ${INSTALL_DIR}/dada
	chmod +x ${INSTALL_DIR}/dada
	cp bin/pb ${INSTALL_DIR}
