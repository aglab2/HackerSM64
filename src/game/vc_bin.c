// do not include vc_bin.h intentionally

// ah the wonders for virtual console
// VC is using binary matching to stub functions - this hex was copied from SM64
// 0x80329150 = 0xE4150
__attribute__((aligned(16))) char osEepromReadVC[] = 
{
0x27, 0xBD, 0xFF, 0xC8, 0xAF, 0xA5, 0x00, 0x3C, 0x93, 0xAF, 0x00, 0x3F, 0x3C, 0x0E, 0x80, 0x36,
0x25, 0xCE, 0x71, 0x70, 0x29, 0xE1, 0x00, 0x41, 0xAF, 0xBF, 0x00, 0x14, 0xAF, 0xA4, 0x00, 0x38,
0xAF, 0xA6, 0x00, 0x40, 0xAF, 0xA0, 0x00, 0x34, 0xAF, 0xA0, 0x00, 0x30, 0x14, 0x20, 0x00, 0x03,
0xAF, 0xAE, 0x00, 0x2C, 0x10, 0x00, 0x00, 0x6A, 0x24, 0x02, 0xFF, 0xFF, 0x0C, 0x0C, 0xA2, 0x3C,
0x00, 0x00, 0x00, 0x00, 0x8F, 0xA4, 0x00, 0x38, 0x0C, 0x0C, 0xA3, 0x6B, 0x27, 0xA5, 0x00, 0x28,
0xAF, 0xA2, 0x00, 0x34, 0x8F, 0xB8, 0x00, 0x34, 0x17, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00,
0x97, 0xB9, 0x00, 0x28, 0x34, 0x01, 0x80, 0x00, 0x13, 0x21, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00,
0x10, 0x00, 0x00, 0x5B, 0x24, 0x02, 0x00, 0x08, 0x93, 0xA8, 0x00, 0x2A, 0x31, 0x09, 0x00, 0x80,
0x11, 0x20, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x8F, 0xA4, 0x00, 0x38, 0x0C, 0x0C, 0xA3, 0x6B,
0x27, 0xA5, 0x00, 0x28, 0x93, 0xAA, 0x00, 0x2A, 0x31, 0x4B, 0x00, 0x80, 0x15, 0x60, 0xFF, 0xFA,
0x00, 0x00, 0x00, 0x00, 0x0C, 0x0C, 0xA4, 0xD0, 0x93, 0xA4, 0x00, 0x3F, 0x3C, 0x05, 0x80, 0x36,
0x24, 0xA5, 0x71, 0x70, 0x0C, 0x0C, 0xA2, 0x58, 0x24, 0x04, 0x00, 0x01, 0xAF, 0xA2, 0x00, 0x34,
0x8F, 0xA4, 0x00, 0x38, 0x00, 0x00, 0x28, 0x25, 0x0C, 0x0C, 0x8A, 0x00, 0x24, 0x06, 0x00, 0x01,
0xAF, 0xA0, 0x00, 0x30, 0x8F, 0xAD, 0x00, 0x30, 0x8F, 0xAF, 0x00, 0x30, 0x3C, 0x01, 0x80, 0x36,
0x00, 0x0D, 0x70, 0x80, 0x00, 0x2E, 0x08, 0x21, 0x24, 0x0C, 0x00, 0xFF, 0xAC, 0x2C, 0x71, 0x70,
0x25, 0xF8, 0x00, 0x01, 0x2B, 0x01, 0x00, 0x10, 0x14, 0x20, 0xFF, 0xF6, 0xAF, 0xB8, 0x00, 0x30,
0x3C, 0x01, 0x80, 0x36, 0x3C, 0x05, 0x80, 0x36, 0xAC, 0x20, 0x71, 0xAC, 0x24, 0xA5, 0x71, 0x70,
0x0C, 0x0C, 0xA2, 0x58, 0x00, 0x00, 0x20, 0x25, 0x24, 0x19, 0x00, 0x04, 0x3C, 0x01, 0x80, 0x36,
0xAF, 0xA2, 0x00, 0x34, 0xA0, 0x39, 0x70, 0x90, 0x8F, 0xA4, 0x00, 0x38, 0x00, 0x00, 0x28, 0x25,
0x0C, 0x0C, 0x8A, 0x00, 0x24, 0x06, 0x00, 0x01, 0xAF, 0xA0, 0x00, 0x30, 0x8F, 0xAA, 0x00, 0x30,
0x8F, 0xA8, 0x00, 0x2C, 0x25, 0x4B, 0x00, 0x01, 0x29, 0x61, 0x00, 0x04, 0x25, 0x09, 0x00, 0x01,
0xAF, 0xAB, 0x00, 0x30, 0x14, 0x20, 0xFF, 0xF9, 0xAF, 0xA9, 0x00, 0x2C, 0x8F, 0xAC, 0x00, 0x2C,
0x27, 0xAD, 0x00, 0x1C, 0x89, 0x81, 0x00, 0x00, 0x99, 0x81, 0x00, 0x03, 0xAD, 0xA1, 0x00, 0x00,
0x89, 0x8F, 0x00, 0x04, 0x99, 0x8F, 0x00, 0x07, 0xAD, 0xAF, 0x00, 0x04, 0x89, 0x81, 0x00, 0x08,
0x99, 0x81, 0x00, 0x0B, 0xAD, 0xA1, 0x00, 0x08, 0x93, 0xB8, 0x00, 0x1D, 0x33, 0x19, 0x00, 0xC0,
0x00, 0x19, 0x41, 0x03, 0x15, 0x00, 0x00, 0x0F, 0xAF, 0xA8, 0x00, 0x34, 0xAF, 0xA0, 0x00, 0x30,
0x8F, 0xA9, 0x00, 0x30, 0x8F, 0xAB, 0x00, 0x40, 0x03, 0xA9, 0x50, 0x21, 0x91, 0x4A, 0x00, 0x20,
0xA1, 0x6A, 0x00, 0x00, 0x8F, 0xAC, 0x00, 0x30, 0x8F, 0xAE, 0x00, 0x40, 0x25, 0x8F, 0x00, 0x01,
0x29, 0xE1, 0x00, 0x08, 0x25, 0xCD, 0x00, 0x01, 0xAF, 0xAF, 0x00, 0x30, 0x14, 0x20, 0xFF, 0xF4,
0xAF, 0xAD, 0x00, 0x40, 0x0C, 0x0C, 0xA2, 0x4D, 0x00, 0x00, 0x00, 0x00, 0x8F, 0xA2, 0x00, 0x34,
0x8F, 0xBF, 0x00, 0x14, 0x27, 0xBD, 0x00, 0x38, 0x03, 0xE0, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

// 0x80328af0 = 0xE3AF0
__attribute__((aligned(16))) char osEepromWriteVC[] = 
{
0x27, 0xBD, 0xFF, 0xC8, 0xAF, 0xA5, 0x00, 0x3C, 0x93, 0xAF, 0x00, 0x3F, 0x3C, 0x0E, 0x80, 0x36, 
0x25, 0xCE, 0x71, 0x70, 0x29, 0xE1, 0x00, 0x41, 0xAF, 0xBF, 0x00, 0x14, 0xAF, 0xA4, 0x00, 0x38, 
0xAF, 0xA6, 0x00, 0x40, 0xAF, 0xA0, 0x00, 0x34, 0x14, 0x20, 0x00, 0x03, 0xAF, 0xAE, 0x00, 0x2C, 
0x10, 0x00, 0x00, 0x5B, 0x24, 0x02, 0xFF, 0xFF, 0x0C, 0x0C, 0xA2, 0x3C, 0x00, 0x00, 0x00, 0x00, 
0x8F, 0xA4, 0x00, 0x38, 0x0C, 0x0C, 0xA3, 0x6B, 0x27, 0xA5, 0x00, 0x1C, 0xAF, 0xA2, 0x00, 0x34, 
0x8F, 0xB8, 0x00, 0x34, 0x17, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00, 0x97, 0xB9, 0x00, 0x1C, 
0x34, 0x01, 0x80, 0x00, 0x13, 0x21, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x4C, 
0x24, 0x02, 0x00, 0x08, 0x93, 0xA8, 0x00, 0x1E, 0x31, 0x09, 0x00, 0x80, 0x11, 0x20, 0x00, 0x08, 
0x00, 0x00, 0x00, 0x00, 0x8F, 0xA4, 0x00, 0x38, 0x0C, 0x0C, 0xA3, 0x6B, 0x27, 0xA5, 0x00, 0x1C, 
0x93, 0xAA, 0x00, 0x1E, 0x31, 0x4B, 0x00, 0x80, 0x15, 0x60, 0xFF, 0xFA, 0x00, 0x00, 0x00, 0x00, 
0x93, 0xA4, 0x00, 0x3F, 0x0C, 0x0C, 0xA3, 0x28, 0x8F, 0xA5, 0x00, 0x40, 0x3C, 0x05, 0x80, 0x36, 
0x24, 0xA5, 0x71, 0x70, 0x0C, 0x0C, 0xA2, 0x58, 0x24, 0x04, 0x00, 0x01, 0xAF, 0xA2, 0x00, 0x34, 
0x8F, 0xA4, 0x00, 0x38, 0x00, 0x00, 0x28, 0x25, 0x0C, 0x0C, 0x8A, 0x00, 0x24, 0x06, 0x00, 0x01, 
0xAF, 0xA0, 0x00, 0x30, 0x8F, 0xAD, 0x00, 0x30, 0x8F, 0xAF, 0x00, 0x30, 0x3C, 0x01, 0x80, 0x36, 
0x00, 0x0D, 0x70, 0x80, 0x00, 0x2E, 0x08, 0x21, 0x24, 0x0C, 0x00, 0xFF, 0xAC, 0x2C, 0x71, 0x70, 
0x25, 0xF8, 0x00, 0x01, 0x2B, 0x01, 0x00, 0x10, 0x14, 0x20, 0xFF, 0xF6, 0xAF, 0xB8, 0x00, 0x30,
0x3C, 0x01, 0x80, 0x36, 0x3C, 0x05, 0x80, 0x36, 0xAC, 0x20, 0x71, 0xAC, 0x24, 0xA5, 0x71, 0x70, 
0x0C, 0x0C, 0xA2, 0x58, 0x00, 0x00, 0x20, 0x25, 0x24, 0x19, 0x00, 0x05, 0x3C, 0x01, 0x80, 0x36, 
0xAF, 0xA2, 0x00, 0x34, 0xA0, 0x39, 0x70, 0x90, 0x8F, 0xA4, 0x00, 0x38, 0x00, 0x00, 0x28, 0x25, 
0x0C, 0x0C, 0x8A, 0x00, 0x24, 0x06, 0x00, 0x01, 0xAF, 0xA0, 0x00, 0x30, 0x8F, 0xAA, 0x00, 0x30,
0x8F, 0xA8, 0x00, 0x2C, 0x25, 0x4B, 0x00, 0x01, 0x29, 0x61, 0x00, 0x04, 0x25, 0x09, 0x00, 0x01, 
0xAF, 0xAB, 0x00, 0x30, 0x14, 0x20, 0xFF, 0xF9, 0xAF, 0xA9, 0x00, 0x2C, 0x8F, 0xAC, 0x00, 0x2C, 
0x27, 0xAD, 0x00, 0x20, 0x89, 0x81, 0x00, 0x00, 0x99, 0x81, 0x00, 0x03, 0xAD, 0xA1, 0x00, 0x00, 
0x89, 0x8F, 0x00, 0x04, 0x99, 0x8F, 0x00, 0x07, 0xAD, 0xAF, 0x00, 0x04, 0x89, 0x81, 0x00, 0x08, 
0x99, 0x81, 0x00, 0x0B, 0xAD, 0xA1, 0x00, 0x08, 0x93, 0xB8, 0x00, 0x21, 0x33, 0x19, 0x00, 0xC0, 
0x00, 0x19, 0x41, 0x03, 0x0C, 0x0C, 0xA2, 0x4D, 0xAF, 0xA8, 0x00, 0x34, 0x8F, 0xA2, 0x00, 0x34, 
0x8F, 0xBF, 0x00, 0x14, 0x27, 0xBD, 0x00, 0x38, 0x03, 0xE0, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

__attribute__((aligned(16))) char __osEepStatusVC[] = 
{
0x27, 0xBD, 0xFF, 0xD0, 0x3C, 0x0E, 0x80, 0x36, 0x25, 0xCE, 0x71, 0x70, 0xAF, 0xBF, 0x00, 0x14,
0xAF, 0xA4, 0x00, 0x30, 0xAF, 0xA5, 0x00, 0x34, 0xAF, 0xA0, 0x00, 0x2C, 0xAF, 0xAE, 0x00, 0x24,
0xAF, 0xA0, 0x00, 0x28, 0x8F, 0xAF, 0x00, 0x28, 0x8F, 0xB9, 0x00, 0x28, 0x3C, 0x01, 0x80, 0x36,
0x00, 0x0F, 0xC0, 0x80, 0x00, 0x38, 0x08, 0x21, 0xAC, 0x20, 0x71, 0x70, 0x27, 0x28, 0x00, 0x01,
0x29, 0x01, 0x00, 0x10, 0x14, 0x20, 0xFF, 0xF7, 0xAF, 0xA8, 0x00, 0x28, 0x3C, 0x0A, 0x80, 0x36,
0x24, 0x09, 0x00, 0x01, 0x3C, 0x01, 0x80, 0x36, 0x25, 0x4A, 0x71, 0x70, 0xAC, 0x29, 0x71, 0xAC,
0xAF, 0xAA, 0x00, 0x24, 0xAF, 0xA0, 0x00, 0x28, 0x8F, 0xAB, 0x00, 0x24, 0xA1, 0x60, 0x00, 0x00,
0x8F, 0xAE, 0x00, 0x28, 0x8F, 0xAC, 0x00, 0x24, 0x25, 0xCF, 0x00, 0x01, 0x29, 0xE1, 0x00, 0x04,
0x25, 0x8D, 0x00, 0x01, 0xAF, 0xAF, 0x00, 0x28, 0x14, 0x20, 0xFF, 0xF7, 0xAF, 0xAD, 0x00, 0x24,
0x24, 0x18, 0x00, 0xFF, 0x24, 0x19, 0x00, 0x01, 0x24, 0x08, 0x00, 0x03, 0x24, 0x09, 0x00, 0xFF,
0x24, 0x0A, 0x00, 0xFF, 0x24, 0x0B, 0x00, 0xFF, 0x24, 0x0C, 0x00, 0xFF, 0xA3, 0xB8, 0x00, 0x1C,
0xA3, 0xB9, 0x00, 0x1D, 0xA3, 0xA8, 0x00, 0x1E, 0xA3, 0xA0, 0x00, 0x1F, 0xA3, 0xA9, 0x00, 0x20,
0xA3, 0xAA, 0x00, 0x21, 0xA3, 0xAB, 0x00, 0x22, 0xA3, 0xAC, 0x00, 0x23, 0x27, 0xAE, 0x00, 0x1C, 
0x8D, 0xC1, 0x00, 0x00, 0x8F, 0xAD, 0x00, 0x24, 0x24, 0x0A, 0x00, 0xFE, 0x3C, 0x05, 0x80, 0x36,
0xA9, 0xA1, 0x00, 0x00, 0xB9, 0xA1, 0x00, 0x03, 0x8D, 0xD9, 0x00, 0x04, 0x24, 0xA5, 0x71, 0x70,
0x24, 0x04, 0x00, 0x01, 0xA9, 0xB9, 0x00, 0x04, 0xB9, 0xB9, 0x00, 0x07, 0x8F, 0xA8, 0x00, 0x24,
0x25, 0x09, 0x00, 0x08, 0xAF, 0xA9, 0x00, 0x24, 0x0C, 0x0C, 0xA2, 0x58, 0xA1, 0x2A, 0x00, 0x00,
0xAF, 0xA2, 0x00, 0x2C, 0x8F, 0xA4, 0x00, 0x30, 0x00, 0x00, 0x28, 0x25, 0x0C, 0x0C, 0x8A, 0x00,
0x24, 0x06, 0x00, 0x01, 0x24, 0x0B, 0x00, 0x05, 0x3C, 0x01, 0x80, 0x36, 0x3C, 0x05, 0x80, 0x36,
0xA0, 0x2B, 0x70, 0x90, 0x24, 0xA5, 0x71, 0x70, 0x0C, 0x0C, 0xA2, 0x58, 0x00, 0x00, 0x20, 0x25,
0xAF, 0xA2, 0x00, 0x2C, 0x8F, 0xA4, 0x00, 0x30, 0x00, 0x00, 0x28, 0x25, 0x0C, 0x0C, 0x8A, 0x00,
0x24, 0x06, 0x00, 0x01, 0x8F, 0xAC, 0x00, 0x2C, 0x11, 0x80, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00,
0x10, 0x00, 0x00, 0x2C, 0x01, 0x80, 0x10, 0x25, 0x3C, 0x18, 0x80, 0x36, 0x27, 0x18, 0x71, 0x70,
0xAF, 0xB8, 0x00, 0x24, 0xAF, 0xA0, 0x00, 0x28, 0x8F, 0xAF, 0x00, 0x24, 0xA1, 0xE0, 0x00, 0x00,
0x8F, 0xB9, 0x00, 0x28, 0x8F, 0xAD, 0x00, 0x24, 0x27, 0x28, 0x00, 0x01, 0x29, 0x01, 0x00, 0x04,
0x25, 0xAE, 0x00, 0x01, 0xAF, 0xA8, 0x00, 0x28, 0x14, 0x20, 0xFF, 0xF7, 0xAF, 0xAE, 0x00, 0x24,
0x8F, 0xA9, 0x00, 0x24, 0x27, 0xAA, 0x00, 0x1C, 0x89, 0x21, 0x00, 0x00, 0x99, 0x21, 0x00, 0x03,
0xAD, 0x41, 0x00, 0x00, 0x89, 0x2C, 0x00, 0x04, 0x99, 0x2C, 0x00, 0x07, 0xAD, 0x4C, 0x00, 0x04,
0x93, 0xB8, 0x00, 0x1E, 0x8F, 0xAE, 0x00, 0x34, 0x33, 0x0F, 0x00, 0xC0, 0x00, 0x0F, 0x69, 0x03,
0xA1, 0xCD, 0x00, 0x03, 0x93, 0xB9, 0x00, 0x21, 0x93, 0xAB, 0x00, 0x20, 0x8F, 0xA9, 0x00, 0x34,
0x00, 0x19, 0x42, 0x00, 0x01, 0x0B, 0x50, 0x25, 0xA5, 0x2A, 0x00, 0x00, 0x8F, 0xB8, 0x00, 0x34,
0x93, 0xAC, 0x00, 0x22, 0xA3, 0x0C, 0x00, 0x02, 0x8F, 0xAF, 0x00, 0x34, 0x91, 0xED, 0x00, 0x03,
0x11, 0xA0, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x02, 0x01, 0xA0, 0x10, 0x25,
0x00, 0x00, 0x10, 0x25, 0x8F, 0xBF, 0x00, 0x14, 0x27, 0xBD, 0x00, 0x30, 0x03, 0xE0, 0x00, 0x08, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};