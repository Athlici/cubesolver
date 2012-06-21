CXXFLAGS= -Ofast

debug: cubesolver

release: CXXFLAGS=-O3
release:
	$(MAKE) clean
	$(MAKE) cubesolver

cubesolver: main.o
	g++ $(CXXFLAGS) -o cubesolver $^

install: release
	install -Ds -m 755 -o root -g root cubesolver $(DESTDIR)/bin/cubesolver

clean:
	rm -f *.o cubesolver

# vim:noexpandtab:
