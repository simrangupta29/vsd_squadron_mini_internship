# vsd_squadron_mini_internship 
First installed the oracle virtual machine
The next step was to download ubuntu and open it into virtual box.
This is the RISC-V C and C++ cross-compiler. It supports two build modes: a generic ELF/Newlib toolchain and a more sophisticated Linux-ELF/glibc toolchain.
give command:-$ sudo apt-get install autoconf automake autotools-dev curl python3 python3-pip libmpc-dev libmpfr-dev libgmp-dev gawk build-essential bison flex texinfo gperf libtool patchutils bc zlib1g-dev libexpat-dev ninja-build git cmake libglib2.0-dev libslirp-dev
$git clone -- recursive https://github.com/riscv/riscv-gnu-toolchain 
$./configure --prefix=/opt/riscv
$ make linux
$ sudo make linux
