#include <stdio.h>
#include <stdint.h>
#include <assert.h>

typedef struct no_options_ipv4 {
    uint32_t ihl;
    uint32_t flags;
    uint32_t protocol;
    uint32_t source;
    uint32_t destination;
}no_options_ipv4;

typedef struct with_options_ipv4 {
    uint32_t ihl;
    uint32_t flags;
    uint32_t protocol;
    uint32_t source;
    uint32_t destination;
    uint32_t options_array[4];
}with_options_ipv4;

typedef union ipv4_packet{
    no_options_ipv4 no_opt_ipv4;
    with_options_ipv4 opt_ipv4;
}ipv4_packet;

int main() {
    with_options_ipv4 packet_1;
    no_options_ipv4 packet_2;
    assert (sizeof(packet_1) == 36);
    assert (sizeof(packet_2) == 20);
    printf("The representations matches the hardware\n");
    return 0;
}