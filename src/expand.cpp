#include <cassert>  // assert
#include <cstddef>  // size_t
#include <cstdint>  // uint64_t, uint32_t

// Expands the binary representation of input by a factor of scale.
// e.g., expand(0b1111ull, 3) == 0b001001001001
uint64_t expand(uint64_t input, uint32_t scale) {
    uint64_t output = 0;
    for (uint64_t i = 0; i < 64; ++i) {
        // Mask the input bit
        if (input & (1ULL << i)) {
            // Shift and OR the bit by scale and set
            output |= (1ULL << (i * scale));
        }
    }
    return output;
}

int main() {
    // test here...

    assert(expand(0b1111,3) == 0b001001001001);
    assert(expand(0b0101,2) == 0b00010001);
    assert(expand(0b1101,2) == 0b01010001);
    return 0;
}
