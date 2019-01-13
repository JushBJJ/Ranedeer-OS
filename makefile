C_SOURCES = $(wildcard Kernel/kernel.c Kernel/lib/CPU/*.c Kernel/lib/io/*.c Kernel/lib/Signal/*.c Kernel/lib/String/*.c Kernel/lib/Drivers/*.c Kernel/lib/other*.c)
HEADERS = $(wildcard Kernel/lib/Headers/Kernel.h Kernel/lib/Headers/CPU/*.h Kernel/lib/Headers/Drivers/*.h Kernel/lib/Headers/io/*.h Kernel/lib/Headers/other/*.h Kernel/lib/Headers/Signal/*.h Kernel/lib/Headers/String/*.h)
# Nice syntax for file extension replacement
OBJ = ${C_SOURCES:.c=.o Kernel/lib/CPU/interrupt.o}

# Change this if your cross-compiler is somewhere else
CC = /usr/bin/gcc
GDB = /usr/bin/gdb
# -g: Use debugging symbols in gcc
CFLAGS = -g -m32 -IKernel/lib/Headers -fno-PIE

# First rule is run by default
Ranedeer.bin: Kernel/boot/bootsect.bin Kernel/kernel.bin
	cat $^ > Ranedeer.bin

# '--oformat binary' deletes all symbols as a collateral, so we don't need
# to 'strip' them manually on this case
Kernel/kernel.bin: Kernel/boot/kernel_entry.o ${OBJ}
	ld -no-pie -melf_i386 -o $@ -Ttext 0x1000 $^ --oformat binary

# Used for debugging purposes
Kernel/kernel.elf: Kernel/boot/kernel_entry.o ${OBJ}
	ld -no-pie -melf_i386  -o $@ -Ttext 0x1000 $^

run: Ranedeer.bin
	qemu-system-i386 -fda Ranedeer.bin

# Open the connection to qemu and load our kernel-object file with symbols
debug: Ranedeer.bin kernel.elf
	qemu-system-i386 -s -fda Ranedeer.bin &
	${GDB} -ex "target remote localhost:1234" -ex "symbol-file kernel.elf"

# Generic rules for wildcards
# To make an object, always compile from its .c
%.o: %.c ${HEADERS}
	${CC} ${CFLAGS} -ffreestanding -c $< -o $@

%.o: %.asm
	nasm $< -f elf -o $@

%.bin: %.asm
	nasm $< -f bin -o $@

clean: ${OBJ}2
#C sources
	rm
