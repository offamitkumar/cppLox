//
// Created by Amit Kumar on 31/07/23.
//

#include "header/common.h"
#include "header/chunk.h"

int main(int argc, const char *argv[]) {
    Chunk chunk;
    chunk.writeChunk(OP_CONSTANT);
    chunk.writeChunk(chunk.addConstant(1));
    chunk.writeChunk(OP_CONSTANT);
    chunk.writeChunk(chunk.addConstant(2));
    chunk.writeChunk(OP_CONSTANT);
    chunk.writeChunk(chunk.addConstant(4));
    chunk.writeChunk(OP_RETURN);
    DEBUG_ONLY(disassembleChunk(chunk, "test chunk");)
    return 0;
}