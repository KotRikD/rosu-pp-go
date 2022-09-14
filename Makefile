ROOT_DIR := $(dir $(realpath $(lastword $(MAKEFILE_LIST))))

.PHONY: build
build: clean
	@mkdir lib/
	@cd rosu-pp-ffi/ && cargo build --release && cargo test
	@cp rosu-pp-ffi/target/release/librosu_pp_ffi.so lib/
	@cp rosu-pp-ffi/bindings/rosu_pp_ffi.h lib/
	go build -ldflags="-r $(ROOT_DIR)lib" main.go

.PHONY: run
run: build
	@./main

.PHONY: clean
clean:
	rm -rf lib/ main