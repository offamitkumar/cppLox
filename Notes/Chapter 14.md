* jlox relies on the JVM to do lots of things for us. If we want to understand how an interpreter works all the way down to the metal, we need to build those bits and pieces ourselves.


* Issue with Tree Walking Interpreter:
  1. the interpreter traverses the TWI generated from the source code directly and interprets each node in the tree to execute the corresponding operation.
  2. The interpreter needs to recursively traverse the tree for each statement or expression, leading to multiple function calls and stack operations.
  3. The tree-walk approach can be slow because it involves a lot of overhead due to the recursive nature of the interpretation process.
  4. Additionally, the interpreter must repeatedly analyze the structure of the AST to identify the appropriate actions to perform, which can add to the computational cost.


* Bytecode Interpreter:
  1. In the bytecode model, the source code is first translated into a lower-level representation called bytecode.
  2. Bytecode consists of a series of compact and pre-defined instructions that directly represent the operations to be performed.
  3. The interpreter then executes the bytecode instructions directly, usually using a loop that iterates over the bytecode sequence.
  4. The bytecode instructions are typically designed to be more straightforward to interpret and execute than the complex AST structures.
  5. As a result, the bytecode interpreter can often be more efficient and faster than a tree-walk interpreter.

```cpp
int a = 5 + 3;
```

```cpp
    (int a)
       |
      (=)
     /   \
   (a)   (+)
          |
        (1) (2)
```

```asm
       1: iload_1
       2: iload_2
       3: iadd
       4: istore_3
       5: return
```

* Spatial Locality Issues: The loosely connected web of objects in the AST causes poor spatial locality. Modern CPUs process data much faster than they can fetch it from RAM, and the CPU caches play a crucial role in speeding up data access. However, the scattered nature of the AST objects prevents efficient use of the CPU caches.
* Cache Misses: Each time the tree-walking interpreter follows a reference to a child node, it may result in a cache miss, as the required data may not be present in the cache. This can lead to CPU stalls and slowdowns in program execution.


**Why not Native Code**
* Unlike abstract syntax trees (ASTs), machine code uses direct jumps for control flow.
* Native code delivers lightning-fast performance but demands sophisticated compilation techniques.
* Compiling to native code limits portability across different architectures.
* Writing separate back ends for multiple instruction sets is necessary.

**ByteCode**
* Bytecode characteristics:
  1. Resembles machine code: dense, linear sequence of binary instructions.
  2. Low overhead and cache-friendly, Since the bytecode instructions are stored in a contiguous manner.
  3. Simpler and higher-level instruction set than real chips, typically one-byte-long instructions.
  4. An idealized, fantasy instruction set that makes compiler writing easier.


* Overcoming the absence of a real architecture:
  1. Emulator: a simulated chip written in software interprets bytecode one instruction at a time.
  2. Virtual Machine (VM): the emulation layer adds overhead, making bytecode slower than native code, but it offers portability.
  3. VM written in a language like C ensures compatibility with multiple hardware platforms.