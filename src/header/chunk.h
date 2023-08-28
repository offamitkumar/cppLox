//
// Created by Amit Kumar on 31/07/23.
//

#ifndef CPPLOX_CHUNK_H
#define CPPLOX_CHUNK_H

#include "common.h"
#include "iomanip"
#include "value.h"

using std::vector;

using OpCode = enum {OP_RETURN , OP_CONSTANT,};

class Chunk {
public:
    vector<uint8_t> code;
    valueArray constants;
    vector<int> lines;

    ~Chunk() {
        code.clear();
    }

    auto writeChunk(const uint8_t& byte) -> void;
    auto addConstant(const Value& v) -> int;
    [[nodiscard]] auto size() const -> int;
};

void disassembleChunk(const Chunk& chunk, const std::string &name);
int disassembleInstruction(const Chunk& chunk, const int& offset);

#endif //CPPLOX_CHUNK_H
