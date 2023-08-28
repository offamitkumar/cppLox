//
// Created by Amit Kumar on 01/08/23.
//

#include "header/chunk.h"

auto Chunk::writeChunk(const uint8_t &byte) -> void {
    code.emplace_back(byte);
}

auto Chunk::addConstant(const Value &v) -> int {
    constants.emplace_back(v);
    return static_cast<int>(constants.size() - 1);
}

auto Chunk::size() const -> int {
    return static_cast<int>(code.size());
}

void disassembleChunk(const Chunk& chunk, const std::string &name) {
    std::cout << "----" << name << "----" << '\n';

    for (int offset = 0; offset < chunk.size();) {
        offset = disassembleInstruction(chunk, offset);
    }

}

static int simpleInstruction(const std::string& name, const int& offset) {
    std::cout << name << '\n';
    return offset + 1;
}

static int constantInstruction(const std::string& name, const Chunk& chunk, const int& offset) {
    uint8_t constant = chunk.code.at(offset + 1);
    std::cout << std::setfill(' ') << std::left << std::setw(16) << name  << " " << std::right << std::setw(4) << static_cast<int>(constant) << " '";
    printValue(chunk.constants.at(constant));
    std::cout << "'" << std::endl;
    return offset + 2;
}

int disassembleInstruction(const Chunk& chunk, const int& offset) {
    std::cout << std::setw(4) << std::setfill('0') << offset << " ";

    uint8_t instruction = chunk.code.at(offset);
    switch (instruction) {
        case OP_CONSTANT:
            return constantInstruction("OP_CONSTANT", chunk, offset);
        case OP_RETURN:
            return simpleInstruction("OP_RETURN", offset);
        default:
            printf("Unknown opcode %d\n", instruction);
            return offset + 1;
    }
}
