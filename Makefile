CC=arm-none-eabi-gcc
CONVERT=arm-none-eabi-objcopy
hexFlags=-O ihex
CFlags= -c -mcpu=cortex-m3 -mthumb -std=gnu11 -O0
LSFlags = -nostdlib -T stm32.ld -Wl,-Map=final.map

all : main.o RCC_program.o startup.o final.elf

main.o : main.c
	$(CC) $(CFlags) $^ -o $@
	
RCC_program.o : RCC_program.c
	$(CC) $(CFlags) $^ -o $@

startup.o : startup.c
	$(CC) $(CFlags) $^ -o $@

final.elf : main.o RCC_program.o startup.o
	$(CC) $(LSFlags) $^ -o $@

clean:
	rm -rf *.o *.elf

hex :
	$(CONVERT) $(hexFlags) final.elf final.hex