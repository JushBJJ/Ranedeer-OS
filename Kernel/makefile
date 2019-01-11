C_SOURCES = $(wildcard kernel.c lib/*.c lib/Drivers/*.c lib/CPU/*.c)
HEADERS = $(wildcard lib/*.h lib/Drivers/*.h lib/CPU/*.h)
# Nice syntax for file extension replacement
OBJ = ${C_SOURCES:.c=.o lib/CPU/interrupt.o}

# Change this if your cross-compiler is somewhere else
CC = /usr/bin/gcc
GDB = /usr/bin/gdb
# -g: Use debugging symbols in gcc
CFLAGS = -g -m32 -Ilib/

# First rule is run by default
Ranedeer.bin: boot/bootsect.bin kernel.bin
	cat $^ > Ranedeer.bin

# '--oformat binary' deletes all symbols as a collateral, so we don't need
# to 'strip' them manually on this case
kernel.bin: boot/kernel_entry.o ${OBJ}
	ld -melf_i386 --ignore-unresolved-symbol _GLOBAL_OFFSET_TABLE_ -o $@ -Ttext 0x1000 $^ --oformat binary

# Used for debugging purposes
kernel.elf: boot/kernel_entry.o ${OBJ}
	ld -melf_i386 --ignore-unresolved-symbol _GLOBAL_OFFSET_TABLE_ -o $@ -Ttext 0x1000 $^

run: Ranedeer.bin
	qemu-system-i386 -fda Ranedeer.bin

# Open the connection to qemu and load our kernel-object file with symbols
debug: Ranedeer.bin kernel.elf
	qemu-system-i386 -s -fda Ranedeer &
	${GDB} -ex "target remote localhost:1234" -ex "symbol-file kernel.elf"

# Generic rules for wildcards
# To make an object, always compile from its .c
%.o: %.c ${HEADERS}
	${CC} ${CFLAGS} -ffreestanding -c $< -o $@

%.o: %.asm
	nasm $< -f elf -o $@

%.bin: %.asm
	nasm $< -f bin -o $@

clean:
	rm -rf *.bin *.dis *.o Ranedeer.bin *.elf
	rm -rf *.o lib/*.o lib/Drivers/*.o Boot/*.o Boot/*.bin lib/CPU/*.o
