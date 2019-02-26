.PHONY: run
.PHONY: clean
g_flags=-pthread

all: demo.prog

demo.prog: source.cpp
	g++ $(g_flags) source.cpp -o demo.prog

debug:
	g++ $(g_flags) -g source.cpp -o demo.prog

run: demo.prog
	@echo "Run the demo with and without 'forgetful' as the first argument"

clean:
	rm *.o *.prog *.h.gch -f
