SOURCES=arch/monitor.o arch/boot.o kernel/main.o kernel/monitor.o arch/tables.o kernel/hw_tables.o

CFLAGS=-I./include -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector
LDFLAGS=-m elf_i386 -Tlink.ld
NASM_FLAGS=-felf -g

all: $(SOURCES) link

link:
	ld $(LDFLAGS) -o phOS.img $(SOURCES)
	
clean:
	rm -rvf $(SOURCES)

.s.o:
	nasm $(NASM_FLAGS) $<

qemu-start:
	@echo "Starting qemu"
	@./boot.sh qemu

bochs-start:
	@echo "Starting bochs"
	@./boot.sh
