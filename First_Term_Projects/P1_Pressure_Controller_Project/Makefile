#@copyright : Amir
#FOR Machine 
CC=arm-none-eabi-
#For architecteure
CFLAGS=-mcpu=cortex-m3  -gdwarf-2
#For Liberary or path of headers
INCS=-I .
#for static libraries
LIBS=
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
As = $(wildcard *.s)
AsOBJ = $(As:.s=.o)
Project_Name = Pressure_Controller_Cortex_M3

all: $(Project_Name).bin
	@echo "=========Builg is done========="
	
# we don't  use startup.s here so startup.o(target) now depend on startup.c(dependency)	
#startup.o: startup.c
#	$(CC)gcc.exe $(CFLAGS) $< -o $@
	
%.o: %.c
	$(CC)gcc.exe -c  $(INCS) $(CFLAGS)  $< -o $@

$(Project_Name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe  -T  linkerscript.ld $(LIBS) $(OBJ) $(AsOBJ) -o $@ -Map=map_file.map 

$(Project_Name).bin: $(Project_Name).elf
	$(CC)objcopy.exe -O binary $(Project_Name).elf $(Project_Name).bin
	

clean_all:
	rm *.o *.elf *.bin
clean:
	rm *.elf *.bin