# Debugging C with Cosmopolitan Libc

This repo contains some example programs to showcase the debugging features
available when using Cosmopolitan Libc.

Requirements: The recommended development environment for Cosmopolitan Libc is Linux.
You'd also need a recent version of `gcc` (9 or above), `ld.bfd`, `objcopy`, and `make`.


1. Download the cosmopolitan libc amalgamation into the `libcosmo` folder

```bash
cd libcosmo
wget https://justine.lol/cosmopolitan/cosmopolitan.zip
unzip cosmopolitan.zip
ls -alh
cd ../
```

2. Download the cosmopolitan libc amalgamation with ASAN/UBSAN runtime into the
   `libcosmo-dbg` folder:

```bash
cd libcosmo-dbg/
wget https://justine.lol/cosmopolitan/cosmopolitan-dbg.zip
unzip cosmopolitan-dbg.zip
ls -alh
cd ../
```

3. Run `make` and try out the programs with the sample text files.


4. Run `make clean` and `make MODE=dbg` and try running the programs again.
