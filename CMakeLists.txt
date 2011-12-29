cmake_minimum_required (VERSION 2.8)
PROJECT (kernel)

INCLUDE_DIRECTORIES (include)

SET (CMAKE_CXX_FLAGS "-m32 -ffreestanding -fno-rtti -fno-exceptions -nostdlib -nostdinc -fno-stack-protector")
SET (CMAKE_C_FLAGS "-m32 -ffreestanding -fno-exceptions -nostdlib -nostdinc -fno-stack-protector")
SET (CMAKE_EXE_LINKER_FLAGS "-m elf_i386 -T${CMAKE_CURRENT_LIST_DIR}/link.ld")
SET (CMAKE_ASM_NASM_OBJECT_FORMAT "elf")

ENABLE_LANGUAGE (ASM_NASM)

FILE (GLOB_RECURSE kernel_C_SOURCES "kernel/*.c")
FILE (GLOB_RECURSE kernel_CPP_SOURCES "kernel/*.cpp")
FILE (GLOB_RECURSE kernel_ASM_SOURCES "arch/x86/asm/*.nasm")
FILE (GLOB_RECURSE kernel_ARCH_C_SOURCES "arch/x86/*.c")
FILE (GLOB_RECURSE kernel_ARCH_CPP_SOURCES "arch/x86/*cpp")

ADD_LIBRARY (kernel.img STATIC
			${kernel_C_SOURCES} 
			${kernel_CPP_SOURCES} 
			${kernel_ARCH_C_SOURCES} 
			${kernel_ARCH_CPP_SOURCES} 
			${kernel_ASM_SOURCES})

ADD_CUSTOM_COMMAND (TARGET kernel.img
	POST_BUILD
	COMMAND "/usr/bin/ld -m elf_i386 -T${CMAKE_CURRENT_LIST_DIR}/link.ld -o phOS.img ${CMAKE_BINARY_DIR}/libkernel.img.a")

