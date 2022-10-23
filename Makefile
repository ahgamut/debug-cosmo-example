MODE =
# to use Cosmopolitan with UBSAN support, uncomment the below line
# MODE = dbg

ifeq ($(MODE),)
	COSMODIR = ./libcosmo
	DBGFLAGS =
endif

ifeq ($(MODE), dbg)
	COSMODIR = ./libcosmo-dbg
	DBGFLAGS = -fsanitize=address -fsanitize=undefined
endif

CFLAGS = -g3 -O2 -static -nostdlib -nostdinc -fno-pie -no-pie -mno-red-zone \
  -fno-omit-frame-pointer -pg -mnop-mcount -mno-tls-direct-seg-refs -gdwarf-4 \
  $(DBGFLAGS) \
  -I./header_stubs -include $(COSMODIR)/cosmopolitan.h

LDFLAGS = -fuse-ld=bfd -Wl,-T,$(COSMODIR)/ape.lds -Wl,--gc-sections \
  $(COSMODIR)/crt.o $(COSMODIR)/ape-no-modify-self.o $(COSMODIR)/cosmopolitan.a

BINS = hex16.com hex16-backtrace.com hex16-fixed.com hex16-ubsan.com
DBG_BINS = $(BINS:%=%.dbg)

all: $(BINS) $(DBG_BINS)

%.com: %.com.dbg
	objcopy -S -O binary $< $@

%.com.dbg: %.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

clean:
	rm -f ./*.com ./*.com.dbg
