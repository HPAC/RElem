include /usr/local/conf/ElVars

SRCS = $(wildcard *.c)
OBJS = $(patsubst %.c,%.o,$(SRCS))

CC_FLAGS = -std=c99 -O3 -fPIC -Wall

R_INC = -I/usr/share/R/include


EL_PATH=-L$(EL_LIB) -L$(EL_LIB)/external/pmrrr
LINK_FLAGS = -Wl,-rpath,$(EL_LIB):$(EL_LIB)/external/pmrrr

all: RElemental.so

%.o: %.c
	$(CC) $(CC_FLAGS) -I/$(EL_INC) $(R_INC) $(MPI_CXX_INCSTRING) -o $@ -c $<

RElemental.so: $(OBJS)
	$(CC) $(CC_FLAGS) -shared -Wl,-soname,$@ -o $@ $(OBJS) $(EL_PATH) $(EL_LIBS) $(LINK_FLAGS)

clean:
	rm -f *.o *.so
