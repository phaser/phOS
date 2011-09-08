SOURCES=arch/monitor.o arch/boot.o arch/tables.o kernel/hw_tables.o kernel/Video.o kernel/Kernel.o

CXXFLAGS=-I./include -m32 -ffreestanding -fno-rtti -fno-exceptions -nostdlib -nostdinc -fno-stack-protector
CFLAGS=$(CXXFLAGS)
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
