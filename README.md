# vsd_squadron_mini_internship 
First installed the oracle virtual machine<br />
The next step was to download ubuntu and open it into virtual box.<br />
# RISCV-Toolchain
This is the RISC-V C and C++ cross-compiler. It supports two build modes: a generic ELF/Newlib toolchain and a more sophisticated Linux-ELF/glibc toolchain.<br />
give command:-$ sudo apt-get install autoconf automake autotools-dev curl python3 python3-pip libmpc-dev libmpfr-dev libgmp-dev gawk build-essential bison flex texinfo gperf libtool patchutils bc zlib1g-dev libexpat-dev ninja-build git cmake libglib2.0-dev libslirp-dev<br />
$git clone -- recursive https://github.com/riscv/riscv-gnu-toolchain <br />
$./configure --prefix=/opt/riscv<br />
$ make linux<br />
$ sudo make linux<br />
![intern_riscv](https://github.com/simrangupta29/vsd_squadron_mini_internship/assets/130252328/d3cf31fe-2712-4d0d-ad97-b394c5498b41)
# YOSYS
$ git clone https://github.com/YosysHQ/yosys.git<br />
$ cd yosys<br />
$ sudo apt install make (If make is not installed please install it) <br />
$ sudo apt-get install build-essential clang bison flex \<br />
    libreadline-dev gawk tcl-dev libffi-dev git \<br />
    graphviz xdot pkg-config python3 libboost-system-dev \<br />
    libboost-python-dev libboost-filesystem-dev zlib1g-dev<br />
$ make config-gcc<br />
$ make <br />
$ sudo make install<br />
![intern_yosys](https://github.com/simrangupta29/vsd_squadron_mini_internship/assets/130252328/a562fb43-7d69-4e0c-b9c6-cd00f0c9dc0f)
# verilog
$sudo apt-get install iverilog<br />
![intern_verilog](https://github.com/simrangupta29/vsd_squadron_mini_internship/assets/130252328/99574331-89fb-4484-ae07-7ef634dfb823)

# Gtkware
$sudo apt update<br />
$sudo apt install gtkwave<br />
![intern_gitkware](https://github.com/simrangupta29/vsd_squadron_mini_internship/assets/130252328/533e8301-6589-47dc-a309-4882c1bc80af)
TASK-2
Colons can be used to align columns.

| Tables        | Are           | Cool  |
| ------------- |:-------------:| -----:|
| col 3 is      | right-aligned | $1600 |
| col 2 is      | centered      |   $12 |
| zebra stripes | are neat      |    $1 |

There must be at least 3 dashes separating each header cell.
The outer pipes (|) are optional, and you don't need to make the 
raw Markdown line up prettily. You can also use inline Markdown.

Markdown | Less | Pretty
--- | --- | ---
*Still* | `renders` | **nicely**
1 | 2 | 3
