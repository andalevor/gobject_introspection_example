LIBRARY = libgirtest.so
GIR = Girtest-0.1.gir
TYPELIB = Girtest-0.1.typelib

SDIR = src

ifeq ($(BUILD_DIR),)
	ODIR = obj_dir
else
	ODIR = $(BUILD_DIR)
endif

CFLAGS = `pkg-config --cflags gobject-introspection-1.0` -fpic
LDFLAGS = `pkg-config --libs gobject-introspection-1.0`

SRC = $(wildcard $(SDIR)/*.c)
DEP = $(wildcard $(SDIR)/*.h)
OBJ = $(patsubst $(SDIR)/%.c, $(ODIR)/%.o, $(SRC))

.PHONY: clean $(LIBRARY)
.IGNORE: clean
.SILENT: clean

all: directories $(LIBRARY) introspection

$(ODIR)/%.o: $(SDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBRARY): $(OBJ)
	$(CC) -shared $(OBJ) -o $(LIBRARY) $(LDFLAGS)

introspection:
	LD_LIBRARY_PATH=`pwd`:$$LD_LIBRARY_PATH \
		g-ir-scanner $(SDIR)/girtest_object.[ch] --library=girtest \
		`pkg-config --cflags gobject-introspection-1.0` \
		--include=GObject-2.0 --namespace=Girtest --nsversion=0.1 \
		--output=$(GIR)

	g-ir-compiler $(GIR) --output=$(TYPELIB)

clean:
	@rm -rf $(ODIR)
	@rm $(LIBRARY)
	@rm $(GIR)
	@rm $(TYPELIB)

directories:
	@mkdir -p $(ODIR)
