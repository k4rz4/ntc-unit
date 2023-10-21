FROM ubuntu:latest

# Install build essentials and tools
RUN apt-get update && \
    apt-get install -y build-essential git clang valgrind gcc-multilib

# Install Criterion
RUN apt-get install -y libcriterion-dev

WORKDIR /workspace

COPY . .