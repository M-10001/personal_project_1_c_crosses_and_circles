BINARY = 1_main.exe
CODEDIRS = . ./include
INCDIRS = C:/msys64/mingw64/include/gtk-3.0 C:/msys64/mingw64/include/pango-1.0 C:/msys64/mingw64/include/glib-2.0 C:/msys64/mingw64/lib/glib-2.0/include C:/msys64/mingw64/include/harfbuzz C:/msys64/mingw64/include/freetype2 C:/msys64/mingw64/include/libpng16 C:/msys64/mingw64/include/fribidi C:/msys64/mingw64/include/cairo C:/msys64/mingw64/include/pixman-1 C:/msys64/mingw64/include/gdk-pixbuf-2.0 C:/msys64/mingw64/include/webp C:/msys64/mingw64/include/atk-1.0
LIBS = gtk-3 gdk-3 z gdi32 imm32 shell32 ole32 uuid winmm dwmapi setupapi cfgmgr32 hid winspool comctl32 comdlg32 pangowin32-1.0 pangocairo-1.0 pango-1.0 harfbuzz atk-1.0 cairo-gobject cairo gdk_pixbuf-2.0 gio-2.0 gobject-2.0 glib-2.0 intl

CC = gcc
OBJMAKEFLAGS = -c -DLIBDEFLATE_DLL -MP -MD
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