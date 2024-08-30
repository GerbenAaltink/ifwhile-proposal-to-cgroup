CC = clang
CFLAGS = -Wall -Wextra -g -pedantic

EXAMPLES = example1_traditional example2_traditional example3_traditional
SOURCES = example1_traditional.c example1_new.c example2_traditional.c example2_new.c example3_new.c example3_traditional.c

all: build_and_run_all

build_and_run_all: $(EXAMPLES) run_all

$(EXAMPLES): %: %.c
	@echo "Compiling $<..."
	-$(CC) $(CFLAGS) $< -o $@ || true
	@echo ""

run_all: $(EXAMPLES)
	@for exe in $(EXAMPLES); do \
		echo "Running $$exe..."; \
		./$$exe && echo "" || true; \
	done

run_%: %
	@echo "Running $<..."
	./$< || true

lint:
	-clang-tidy *.c
	-cppcheck *.c 

archive:
	tar -cvf ifwhile.tar $(SOURCES) Makefile README.pdf

.PHONY: run_example1_traditional run_example1_new run_example2_traditional run_example2_new run_example3_new run_example3_traditional clean build_and_run_all run_all lint archive docs

clean:
	rm -f $(EXAMPLES)

docs:
	pandoc README.md -o README.pdf --pdf-engine=xelatex \
	-V mainfont="Roboto" \
	-V monofont="Ubuntu Mono" \
	-V geometry:margin=1in \
	-V colorlinks \
	-V linkcolor=blue \
	-V urlcolor=blue \
	-V textcolor=white \
	-V backgroundcolor=black \
	-V codebackgroundcolor="#2E2E2E" \
	-V quotebackgroundcolor="#1E1E1E"

