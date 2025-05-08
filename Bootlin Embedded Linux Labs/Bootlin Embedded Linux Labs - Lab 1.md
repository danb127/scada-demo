
2025-04-07 16:01

Status:

Tags: [[Linux]] [[Toolchain]] [[Cross-compiling]] [[Embedded Linux]] [[Embedded Systems]]

# Bootlin Embedded Linux Labs - Lab 1
## Building a cross-compiling toolchain
**Objective: Learn how to compile your own cross-compiling toolchain for the musl C library**

### Notes
In this lab I built a toolchain that involved first getting Crosstool-NG. To do this,  I first ran tar xvf for the embedded-linux-labs.t which extracted the directory and gave me the tools needed. Then within the directory I cd'd into the toolchain sub directory and was able to clone the git repo for crosstool-ng. We checked out a stable version 1.26, and then we generated the configure script by running ./bootstrap .I had to make sure I had all the packages installed on NixOS however, so




# References
