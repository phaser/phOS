ASM_SOURCES=$(patsubst %.s, %.o, $(wildcard arch/x86/asm/*.s))
ARCH_CPP_SOURCES=$(patsubst %.cpp, %.o, $(wildcard arch/x86/*.cpp)) 
ARCH_C_SOURCES=$(patsubst %.c, %.o, $(wildcard arch/x86/*.c))
ARCH_SOURCES=$(ARCH_CPP_SOURCES) $(ARCH_C_SOURCES)

KERNEL_SOURCES=$(patsubst %.c, %.o, $(wildcard kernel/*.c)) $(patsubst %.cpp, %.o, $(wildcard kernel/*.cpp))

SOURCES=$(ASM_SOURCES) $(ARCH_SOURCES) $(KERNEL_SOURCES)

CXXFLAGS=-I./include -m32 -ffreestanding -fno-rtti -fno-exceptions -nostdlib -nostdinc -fno-stack-protector
CFLAGS=-I./include -m32 -ffreestanding -fno-exceptions -nostdlib -nostdinc -fno-stack-protector

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

tags:
	@ctags -R -f phOS.tags .
