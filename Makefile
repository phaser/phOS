SOURCES=arch/boot.o kernel/main.o

CFLAGS=-nostdlib -nostdinc -fno-builtin -fno-stack-protector
LDFLAGS=-Tlink.ld
NASM_FLAGS=-felf

all: $(SOURCES) link

link:
	ld $(LDFLAGS) -o phOS.img $(SOURCES)
	
clean:
	rm -rvf $(SOURCES)

.s.o:
	nasm $(NASM_FLAGS) $<

