#ifndef Offsets_hpp
#define Offsets_hpp
#include <stdint.h>

#pragma pack(push, 1) 
struct UnityVariableNode {
    uint32_t bitSize;
    uint32_t bitAlign;
    uint64_t offset;
};
#pragma pack(pop)

class MemoryManager {
public:
    [span_3](start_span)// Implementation of your legacy offset logic[span_3](end_span)
    static uint64_t calculateTotalSize(UnityVariableNode node) {
        uint64_t size = node.bitSize;
        if (node.offset != static_cast<uint64_t>(-1)) {
            return size + node.offset; [span_4](start_span)// Matches your: if (-1 != offset) return size + offset;[span_4](end_span)
        }
        return size;
    }
    
    [span_5](start_span)[span_6](start_span)// Logic for packed structures found in your code[span_5](end_span)[span_6](end_span)
    static uint32_t getAlignment(bool isPacked, uint32_t defaultAlign) {
        return isPacked ? 1 : defaultAlign; 
    }
};
#endif
