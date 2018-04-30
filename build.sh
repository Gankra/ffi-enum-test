#!/bin/sh

# cargo build
rustc --crate-type=staticlib wr.rs
g++ -c -std=c++14 main.cpp
# g++ -o main.o target/debug/libwr.a -Wl,--gc-sections -lpthread -ldl
g++ -o main.o libwr.a -Wl,--gc-sections -lpthread -ldl