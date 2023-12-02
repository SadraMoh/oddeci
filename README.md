# My journey towards learning the C programming language

### Progression

- [x] C type syntax
- [x] String interploation syntax
- [ ] Type conversions
  - [ ] Type parsing
  - [x] Type casting
- [x] Creating modules and libraries
- [ ] Interrupts
- [ ] Memory management
- [ ] Data structures
  - [ ] Vector
  - [x] Linked List
  - [ ] Hash map
  - [ ] Queue
  - [ ] BTree
  - [ ] Graph
- [ ] Build tools
- [ ] Database connection
- [ ] WebAssembly/WASI

### Build & Run

```shell
gcc main.c lib/<library_name>.c -o bin.out && ./bin.out
```

#### Build to wasi

Make sure the following tools are installed:

- cmake
- clang
- ninja

Clone the `wasi-sdk` repository
`git clone https://github.com/WebAssembly/wasi-sdk`

Build the sdk and install

```shell
cd wasi-sdk
NINJA_FLAGS=-v make package

export WASI_VERSION=20
export WASI_VERSION_FULL=${WASI_VERSION}.0
wget https://github.com/WebAssembly/wasi-sdk/releases/download/wasi-sdk-${WASI_VERSION}/wasi-sdk-${WASI_VERSION_FULL}-linux.tar.gz
tar xvf wasi-sdk-${WASI_VERSION_FULL}-linux.tar.gz

export WASI_SDK_PATH=`pwd`/wasi-sdk-${WASI_VERSION_FULL}
CC="${WASI_SDK_PATH}/bin/clang --sysroot=${WASI_SDK_PATH}/share/wasi-sysroot"
```

```shell
$CC main.c lib/linked_list.c \
-o bin.wasm \
--target=wasm32-wasi \
-Wl,--export=malloc \
-Wl,--export=free \
-Wl,--export=realloc \
-Wl,--export=calloc \
-Wl,--export=hello \
-Wl,--no-entry

wasmer inspect bin.wasm
```
