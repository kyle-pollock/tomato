.POSIX:

FLAGS = `pkg-config --cflags --libs libnotify`

tomato:
	$(CC) -o $@ tomato.c $(FLAGS)

install: tomato
	mkdir -p /usr/local/bin
	cp -f tomato /usr/local/bin
	chmod 755 /usr/local/bin/tomato

uninstall:
	rm -f /usr/local/bin/tomato

.PHONY: install uninstall
