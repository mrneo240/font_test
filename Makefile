BIN = font
OBJS = startup.o main.o biossymbol.o video.o sleep.o

include ./Makefile.config

all: $(BIN).bin

%.bin: %.elf
	@$(KOS_CC_BASE)/sh-elf/bin/objcopy -R .stack -O binary $< $(basename $<)
	@$(KOS_BASE)/utils/scramble/scramble $(basename $<) 1ST_READ.BIN

$(BIN).elf: $(OBJS)
	$(KOS_CC) $(DREAM_CFLAGS) $(DREAM_LDFLAGS) -o $@ $(OBJS) $(DREAM_LIBS)

%.o: %.c
	$(KOS_CC) $(DREAM_CFLAGS) $(DREAM_LDFLAGS) $(INCS) -c $< -o $@

%.o: %.s
	#$(AS) -little $(INCS) $< -o $@
	$(KOS_CC) $(DREAM_CFLAGS) $(DREAM_LDFLAGS) -c $< -o $@

clean:
	-rm -f *.o *.elf 1ST_READ.BIN *.bck $(EXTRA_CLEAN)

reallyclean: clean
	-rm -f *.bin *.srec

force:
	-rm -f $(BIN).elf
	make

