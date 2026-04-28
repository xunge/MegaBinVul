#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#define VBE_DISPI_INDEX_NB 0x0f
#define VBE_DISPI_INDEX_ID 0x0
#define VBE_DISPI_INDEX_XRES 0x1
#define VBE_DISPI_INDEX_YRES 0x2
#define VBE_DISPI_INDEX_BPP 0x3
#define VBE_DISPI_INDEX_BANK 0x4
#define VBE_DISPI_INDEX_ENABLE 0x5
#define VBE_DISPI_INDEX_VIRT_WIDTH 0x6
#define VBE_DISPI_INDEX_VIRT_HEIGHT 0x7
#define VBE_DISPI_INDEX_X_OFFSET 0x8
#define VBE_DISPI_INDEX_Y_OFFSET 0x9

#define VBE_DISPI_ID0 0xB0C0
#define VBE_DISPI_ID1 0xB0C1
#define VBE_DISPI_ID2 0xB0C2
#define VBE_DISPI_ID3 0xB0C3
#define VBE_DISPI_ID4 0xB0C4
#define VBE_DISPI_MAX_XRES 4096
#define VBE_DISPI_MAX_YRES 4096
#define VBE_DISPI_ENABLED 0x01
#define VBE_DISPI_NOCLEARMEM 0x80
#define VBE_DISPI_8BIT_DAC 0x20

#define VGA_GFX_MISC 0x06
#define VGA_GR06_GRAPHICS_MODE 0x01
#define VGA_CRTC_MODE 0x17
#define VGA_CRTC_OFFSET 0x13
#define VGA_CRTC_H_DISP 0x01
#define VGA_CRTC_V_DISP_END 0x12
#define VGA_CRTC_OVERFLOW 0x07
#define VGA_CRTC_LINE_COMPARE 0x18
#define VGA_CRTC_MAX_SCAN 0x09
#define VGA_SEQ_CLOCK_MODE 0x01
#define VGA_SEQ_MEMORY_MODE 0x04
#define VGA_SR04_CHN_4M 0x08
#define VGA_SEQ_PLANE_WRITE 0x02
#define VGA_SR02_ALL_PLANES 0x0F
#define VGA_GFX_MODE 0x05

typedef struct VGACommonState {
    uint32_t vbe_index;
    uint32_t vbe_regs[16];
    uint32_t vbe_bank_mask;
    uint32_t bank_offset;
    uint32_t vbe_line_offset;
    uint32_t vbe_start_addr;
    uint32_t vbe_size;
    uint8_t *vram_ptr;
    uint8_t gr[256];
    uint8_t cr[256];
    uint8_t sr[256];
    bool dac_8bit;
} VGACommonState;

void vga_update_memory_access(VGACommonState *s);