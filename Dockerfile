FROM ubuntu:latest

# Install build essentials and tools
RUN apt-get update && \
    apt-get install -y \
    build-essential \
    git \
    clang \
    valgrind \
    gcc-multilib \
    libcriterion-dev && \
    rm -rf /var/lib/apt/lists/*

# Create a non-root user
RUN useradd -m myuser
USER myuser

WORKDIR /workspace

# Ensure correct permissions
RUN chown -R 1000:1000 /workspace

COPY . .