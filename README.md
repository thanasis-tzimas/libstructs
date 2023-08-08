# libstructs

`libstructs` is a shareable library that exposes common data structures to be used in other C applications.  

## Building from source
**Prerequisites** for building the shareable library:
- `gcc`: libstructs is written in C90 and it should be compilable by most C compilers.
- `glibc`: as of now, some data structures depend upon `glibc`, primarly for memory allocations.
- `make`: it is recommended to use GNU Make for automating the building process.

**Building**:
- Change directory to the `libstructs` directory.
- Run GNU Make by invoking: `make` or `make all`.
