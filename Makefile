sources := \
$(wildcard inc/*.h) \
$(wildcard src/*.c) \
$(wildcard example/general/*)

docs: $(sources)
	doxygen
	moxygen docs/xml

format:
	clang-format -i $(sources) $$(find example -name main.c)

clean:
	rm -r docs
