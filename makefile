C_SOURCES = $(wildcard Kernel/libc/*/*.c Kernel/kernel.c Kernel/Kernel.c)
HEADERS = $(wildcard Kernel/include/*.h)
# Nice syntax for file extension replacement
OBJ = ${C_SOURCES:.c=.o Kernel/last/interrupt.o}

# Change this if your cross-compiler is somewhere else
CC = /usr/bin/gcc
GDB = /usr/bin/gdb
# -g: Use debugging symbols in gcc
CFLAGS = -g -m32 -IKernel/include -fno-PIE

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
	qemu-system-i386 -hda Ranedeer.bin

# Open the connection to qemu and load our kernel-object file with symbols
debug: Ranedeer.bin kernel.elf
	qemu-system-i386 -s -hda Ranedeer.bin &
	${GDB} -ex "target remote localhost:1234" -ex "symbol-file kernel.elf"

# Generic rules for wildcards
# To make an object, always compile from its .c
%.o: %.c ${HEADERS}
	${CC} ${CFLAGS} -ffreestanding -c $< -o $@

%.o: %.asm
	nasm -IKernel/boot/ $< -f elf -o $@

%.bin: %.asm
	nasm -IKernel/boot/ $< -f bin -o $@

clean:
	rm Kernel/*/*.o Kernel/libc/*/*.o
