# jawe compiler

jawe compiles Javascript into Web Assembly. It's primary goal is to compile Javascript to LLVM, from
which it can be then compiled into Web Assembly via various toolchains.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for developmet and testing purposes. This project is still in it's early phase and if you notice any bugs or strange behaviour, please submit an issue.

### Prerequisites

In order to successfuly compile jawe, you'll need to install the following:

* [gcc](https://gcc.gnu.org/) - GNU compiler for C/C++ (tested on gcc 6.3.1)
* [make](https://www.gnu.org/software/make/manual/make.html) - build system from GNU (tested on: 4.2.1)
* [cmake](https://cmake.org/) - cross-platform build system (min: 3.8)
* [boost](http://www.boost.org/) - set of C++ libraries (tested on: 1.63)
* [flex](https://github.com/westes/flex) - lexical analyzer generator (min: 2.5.35)
* [bison](https://www.gnu.org/software/bison/) - general-purpose parser generator from GNU (min: 2.4.1)

### Compiling

After ensuring that all of the dependencies are met, you need to clone this repository. After you fetched the code,
position your self into this folder and run these commands
```
mkdir build
cd build
cmake ..
make
```

Alternatively, you can run only `make` command from the project root and it will automatically create build folder and run cmake from within
that folder. After that it'll run make and run jawe with one of the javascript files from tests folder.


## Usage

Since this is still a premature stage of development, no real output is provided. Only two thigs can be done at this
point:
* print parsed file to the standard output
* print AST to the standard output

```
[uros: build> jawe --help
Usage: jawe [OPTION]... --input-file program.js:
  -h [ --help ]              prints this help message
  -v [ --version ]           prints version info
  --verbose                  prints verbose parsing information
  --dump-ast                 prints parsed abstract syntax tree
  --print                    prints input program back to the output
  --memory					 shows memory address of each node and its parent node
  --input-file arg           input filename
  --output-file arg (=a.out) output filename
```

Only `--input-file` followed by path to Javascript file is required. If `--dump-ast` flag is present, jawe will print abstract syntax tree. It
is also possible to print detailed output from bison parser by including `--verbose` flag. For debugging purposes, it's
possible to print out memory address for each node in AST with flag --memory.

Example:
```js
// file: test.js
let b = 10;
const y = [b, 11, 12];
var z = b += 1;
```
```
[uros: build> jawe --input-file test.js --dump-ast
command-block
    Declaration [let]
        operator [=]
            Variable [b]
            Number [10]
    Declaration [const]
        operator [=]
            Variable [y]
            Array(3)
                Variable [b]
                Number [11]
                Number [12]
    Declaration [var]
        operator [=]
            Variable [z]
            operator [+=]
                Variable [b]
                Number [1]
```

## Last words

Like i said earlier, this project is still in it's early phase so any comments, suggestions and bug reports are more than welcome.
If you have any questions feel free to contact me.

Good luck coding! :)

## Authors

* **Uros Stegic** - *urosstegic@gmx.com* - [uros-stegic](https://github.com/uros-stegic)

## License

This project is licensed under the GNU GPL-3 License - see the [LICENSE](LICENSE) file for details

