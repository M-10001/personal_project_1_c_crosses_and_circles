BINARY = 1_main.exe
CODEDIRS = .
INCDIRS = C:/msys64/mingw64/include/gtk-4.0 C:/msys64/mingw64/include/pango-1.0 C:/msys64/mingw64/include/glib-2.0 C:/msys64/mingw64/lib/glib-2.0/include C:/msys64/mingw64/include/harfbuzz C:/msys64/mingw64/include/freetype2 C:/msys64/mingw64/include/libpng16 C:/msys64/mingw64/include/fribidi C:/msys64/mingw64/include/cairo C:/msys64/mingw64/include/pixman-1 C:/msys64/mingw64/include/gdk-pixbuf-2.0 C:/msys64/mingw64/include/webp C:/msys64/mingw64/include/graphene-1.0 C:/msys64/mingw64/lib/graphene-1.0/include
LIBS = gtk-4 pangowin32-1.0 pangocairo-1.0 pango-1.0 harfbuzz gdk_pixbuf-2.0 cairo-gobject cairo graphene-1.0 gio-2.0 gobject-2.0 glib-2.0 intl

CC = gcc
OBJMAKEFLAGS = -c -DLIBDEFLATE_DLL -mfpmath=sse -msse -msse2 -MP -MD
INCFLAGS = $(foreach D,$(INCDIRS),-I$(D))
LIBFLAGS = $(foreach D,$(LIBS),-l$(D))

CFILES = $(foreach D,$(CODEDIRS),$(wildcard $(D)/*.c))
OBJFILES = $(patsubst %.c,%.o,$(CFILES))
DEPFILES = $(patsubst %.c,%.d,$(CFILES))

all: $(BINARY)

$(BINARY): $(OBJFILES)
	$(CC) -o $@ $^ $(LIBFLAGS)

%.o:%.c
	$(CC) $(OBJMAKEFLAGS) $(INCFLAGS) -o $@ $<

-include $(DEPFILES)

clean:
	rm -rf $(BINARY) $(OBJFILES) $(DEPFILES)