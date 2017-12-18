sources := \
$(wildcard inc/*.h) \
$(wildcard src/*.c)

docs: $(sources)
	doxygen
	moxygen docs/xml

clean:
	rm -r docs
