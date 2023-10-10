 gcc $(pkg-config --cflags gtk4) -o hello-world-gtk a.c $(pkg-config --libs gtk4)
