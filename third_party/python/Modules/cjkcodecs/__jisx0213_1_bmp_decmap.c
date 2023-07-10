#include "libc/x/x.h"
#include "third_party/python/Modules/cjkcodecs/xloadzd.h"
/* clang-format off */

static _Atomic(void *) __jisx0213_1_bmp_decmap_ptr;
static const unsigned char __jisx0213_1_bmp_decmap_rodata[2205] = {
  0x8d, 0x56, 0x0d, 0x70, 0x14, 0x45, 0x16, 0xb6, 0x5f, 0xbf, 0xee, 0x6d, 0xe6,
  0x86, 0x71, 0x18, 0xa7, 0x86, 0x61, 0x19, 0x86, 0x71, 0x5d, 0x96, 0x75, 0x6b,
  0x5d, 0x53, 0x5b, 0xa9, 0x35, 0xa6, 0x62, 0x8e, 0xe2, 0x72, 0x31, 0x15, 0x29,
  0x48, 0x51, 0x14, 0xe5, 0x71, 0x16, 0x75, 0xde, 0x21, 0x25, 0x1c, 0x25, 0xea,
  0xe5, 0x2c, 0xef, 0xa7, 0x30, 0x12, 0xf2, 0x03, 0x4a, 0x30, 0x81, 0xf0, 0x13,
  0x13, 0xfe, 0x12, 0x7e, 0x8c, 0xfc, 0x84, 0xf0, 0x17, 0x24, 0xbb, 0x40, 0x3c,
  0x7e, 0x34, 0x98, 0xe3, 0x9f, 0x80, 0xc0, 0x49, 0xe0, 0xc2, 0x4f, 0xa2, 0x46,
  0x89, 0x04, 0x51, 0xe0, 0x06, 0x04, 0xd1, 0x2b, 0xb9, 0xf3, 0xab, 0xea, 0xea,
  0xf7, 0x5e, 0xbf, 0xd7, 0xfd, 0xe6, 0xbd, 0xd7, 0xaf, 0xa7, 0xe4, 0x5b, 0x4f,
  0x2f, 0xa3, 0xea, 0xaa, 0xe7, 0x62, 0x82, 0x00, 0xc8, 0x50, 0x48, 0xb7, 0x91,
  0x44, 0x9c, 0xdf, 0xf7, 0x1d, 0x2e, 0x7d, 0xc5, 0x41, 0x82, 0x7c, 0xf0, 0xe4,
  0x21, 0x74, 0x5d, 0xba, 0x2d, 0xdd, 0xef, 0x0a, 0xe1, 0x0c, 0x81, 0xc4, 0x00,
  0xa8, 0xf1, 0x02, 0x83, 0x96, 0x6d, 0x77, 0xd4, 0x6f, 0x63, 0xf3, 0x65, 0xfe,
  0x04, 0xf2, 0x67, 0x60, 0x27, 0x3d, 0xf4, 0xf5, 0x9d, 0xa5, 0x45, 0xed, 0x9c,
  0x01, 0x3b, 0x03, 0xc4, 0x20, 0xfb, 0x55, 0xa0, 0x7c, 0x74, 0x16, 0x05, 0x9c,
  0x3b, 0x00, 0xca, 0x3e, 0xbe, 0x6b, 0x7c, 0xad, 0x95, 0x77, 0xdc, 0x7f, 0xfe,
  0xe1, 0xb2, 0x06, 0x4e, 0xe2, 0xa7, 0x79, 0x51, 0xdf, 0x86, 0x1b, 0xff, 0xb5,
  0xf1, 0x0f, 0x70, 0xb8, 0x87, 0x6f, 0xa5, 0x4f, 0x5d, 0xc9, 0xfe, 0x3c, 0x3b,
  0xb8, 0xe6, 0x9b, 0x7b, 0xab, 0x6d, 0x8d, 0xf3, 0x05, 0x43, 0x5b, 0x06, 0xc3,
  0xe2, 0x7e, 0xed, 0x09, 0x7e, 0x3a, 0xc1, 0xdb, 0x12, 0xfc, 0x64, 0x82, 0x9f,
  0x4a, 0xf0, 0x63, 0x09, 0x7e, 0x3c, 0xc1, 0x0f, 0x27, 0xf8, 0x91, 0xc4, 0xbd,
  0xad, 0x7f, 0x1e, 0x0e, 0xc6, 0xdd, 0x78, 0x84, 0x96, 0xc7, 0xf9, 0x92, 0x38,
  0x5f, 0x1a, 0xe7, 0x55, 0x71, 0xbe, 0xd0, 0x3d, 0x35, 0xce, 0x2b, 0xe2, 0xbc,
  0x3c, 0xce, 0xe7, 0xde, 0x09, 0x66, 0x41, 0x9c, 0x17, 0xde, 0x0d, 0x6c, 0x23,
  0xef, 0x6e, 0x74, 0x99, 0x8e, 0x46, 0xbe, 0xfb, 0x61, 0x0f, 0x8a, 0x5e, 0x02,
  0x3d, 0x9b, 0xda, 0xef, 0xe5, 0x49, 0x4f, 0x97, 0xa7, 0x7d, 0x9a, 0x9b, 0x9e,
  0xdb, 0xa8, 0x43, 0x28, 0x0b, 0x56, 0x07, 0xfb, 0xbb, 0xe4, 0x87, 0xe4, 0x53,
  0xb8, 0x9e, 0xf4, 0xfd, 0xca, 0x8c, 0x06, 0x5e, 0xd4, 0xc0, 0x6f, 0x91, 0xaf,
  0x3f, 0x0e, 0x3f, 0xc2, 0xd9, 0xae, 0xff, 0xfb, 0x9d, 0x33, 0x1b, 0x6f, 0x9a,
  0x6e, 0x4b, 0x81, 0x59, 0xee, 0xfc, 0xad, 0xf1, 0xd5, 0xfd, 0x73, 0xf1, 0x1d,
  0x52, 0x98, 0xfa, 0xe3, 0x7d, 0x6a, 0xc8, 0x8f, 0xf9, 0xeb, 0x1b, 0xee, 0xec,
  0xfb, 0xf1, 0xf9, 0x9b, 0xe6, 0xab, 0x0d, 0x03, 0xa0, 0xe7, 0x2f, 0x80, 0x27,
  0x5e, 0x82, 0x99, 0x2f, 0xc1, 0x08, 0xc0, 0x9b, 0x58, 0xfc, 0xb7, 0x79, 0x79,
  0x04, 0x38, 0xba, 0x1a, 0x08, 0xc0, 0x41, 0xc0, 0xff, 0x06, 0xfe, 0xcc, 0xe5,
  0x51, 0x79, 0x64, 0x2d, 0xc9, 0x2d, 0x27, 0xdf, 0xcd, 0xa5, 0x64, 0xa5, 0x67,
  0x35, 0xf7, 0xa4, 0xca, 0x54, 0x0e, 0x09, 0xda, 0x41, 0x56, 0x79, 0xd6, 0xb9,
  0x5c, 0x2b, 0x6b, 0x66, 0xae, 0x60, 0x17, 0x8b, 0x33, 0x3a, 0xa2, 0x9a, 0xbc,
  0xf0, 0x9c, 0x6c, 0x62, 0xdf, 0x89, 0x42, 0x53, 0xc3, 0xd8, 0xbf, 0xdf, 0x1d,
  0x1e, 0xc7, 0x7f, 0x27, 0xe8, 0x64, 0x4b, 0x3c, 0x41, 0xd5, 0xc9, 0x71, 0x76,
  0x92, 0x5b, 0x53, 0x31, 0x26, 0xf7, 0x93, 0xec, 0xa7, 0xd0, 0xb0, 0xff, 0x90,
  0xaa, 0x4b, 0xd6, 0xc3, 0xfd, 0xfb, 0x07, 0x46, 0x0f, 0xf8, 0xcd, 0xbb, 0xf8,
  0x21, 0xfa, 0xd6, 0xb3, 0x13, 0x8c, 0xfc, 0x76, 0xdc, 0xbb, 0x74, 0x29, 0x88,
  0x31, 0x4f, 0x2e, 0xa0, 0xaf, 0x91, 0x55, 0x38, 0xf4, 0xd9, 0xd4, 0xc7, 0x38,
  0xf6, 0x4f, 0x8f, 0x3d, 0x95, 0x33, 0x99, 0xc1, 0x2b, 0x23, 0xfe, 0x4a, 0xe6,
  0x91, 0x57, 0x1f, 0x19, 0xd4, 0x6f, 0xcf, 0x65, 0xcf, 0xeb, 0x57, 0x3c, 0xed,
  0x7f, 0x86, 0x8a, 0xa9, 0x9e, 0xdb, 0xe1, 0x9a, 0x37, 0xd5, 0x03, 0xd5, 0x2f,
  0xae, 0x03, 0x21, 0x60, 0xe2, 0x97, 0xb9, 0xe7, 0x72, 0x1f, 0xe0, 0x1e, 0x9b,
  0x3d, 0x70, 0x2b, 0x6b, 0xb5, 0xdd, 0x9e, 0xfb, 0xd6, 0x5d, 0xf2, 0x28, 0xde,
  0xc7, 0x39, 0x3c, 0x3a, 0x71, 0xb0, 0xbc, 0x84, 0xbc, 0x49, 0x4c, 0xf3, 0xfe,
  0x47, 0xe0, 0x17, 0xe0, 0x73, 0x60, 0x72, 0xa4, 0xa1, 0xf4, 0x6e, 0x12, 0x56,
  0x48, 0xdf, 0x93, 0x45, 0xca, 0x0f, 0x42, 0x54, 0xdb, 0xfb, 0x9e, 0xd1, 0x6b,
  0x79, 0xec, 0x27, 0x84, 0x91, 0x07, 0x3d, 0x2a, 0xa9, 0xf9, 0x3e, 0x99, 0xf7,
  0x1d, 0xbb, 0xce, 0x07, 0x34, 0xaa, 0x3f, 0xa1, 0xb8, 0x4c, 0xbe, 0x4b, 0x27,
  0x9e, 0x9c, 0x60, 0x8d, 0x9e, 0x60, 0x3f, 0x39, 0x3e, 0x26, 0xcf, 0x26, 0x51,
  0xa6, 0xa6, 0x0f, 0x68, 0x72, 0x3d, 0x1b, 0x08, 0x13, 0x7f, 0xdd, 0x91, 0xb5,
  0xfc, 0xea, 0x9d, 0xc2, 0xaf, 0xe7, 0x5b, 0x7b, 0x63, 0x69, 0xda, 0x67, 0xd9,
  0x47, 0xb3, 0x0b, 0x33, 0x6f, 0x9a, 0x7d, 0x4a, 0x40, 0x99, 0xc1, 0x08, 0x99,
  0x56, 0xef, 0xaa, 0x2c, 0xea, 0xe1, 0x8b, 0x7b, 0x6e, 0xaa, 0xc6, 0x7b, 0xf8,
  0x76, 0xb8, 0xde, 0xed, 0x92, 0xff, 0x6c, 0xe3, 0x9f, 0xe3, 0xf2, 0x15, 0xa4,
  0x62, 0x3b, 0xeb, 0x59, 0xcb, 0xf7, 0x3e, 0xaf, 0xc0, 0x7b, 0x64, 0x25, 0x49,
  0x41, 0xa1, 0xd6, 0x92, 0x47, 0xc1, 0xab, 0x19, 0xe8, 0x37, 0x75, 0x5e, 0x5f,
  0xcb, 0x3e, 0x7a, 0x87, 0x45, 0x86, 0x82, 0xa9, 0xdb, 0x8a, 0xbf, 0x97, 0xbc,
  0x9c, 0xbc, 0x38, 0xec, 0x57, 0xe1, 0xb9, 0xcb, 0xd8, 0xe1, 0x1a, 0xc6, 0xd4,
  0x40, 0x24, 0xb4, 0xaf, 0x9a, 0x6d, 0xa9, 0x66, 0xf8, 0xfe, 0xcb, 0xfb, 0xfe,
  0x34, 0x4c, 0x09, 0x0a, 0x33, 0xd0, 0x9c, 0xdb, 0x95, 0x8b, 0xcf, 0x5b, 0xfa,
  0xb8, 0x89, 0x47, 0xaa, 0xd8, 0x47, 0x55, 0x4c, 0xc8, 0x52, 0x7d, 0x15, 0x2b,
  0xaa, 0x62, 0x86, 0xa4, 0x84, 0xea, 0x2b, 0xd9, 0x8a, 0xb7, 0x19, 0x26, 0x87,
  0xf5, 0xd0, 0x76, 0x12, 0x1a, 0xb6, 0x90, 0x3c, 0xab, 0x19, 0x9a, 0x65, 0xa8,
  0xa9, 0x2f, 0xdb, 0xa9, 0x7a, 0xcc, 0xca, 0x94, 0xd4, 0x7d, 0x65, 0xac, 0xb4,
  0x8c, 0x0d, 0x3d, 0x50, 0xca, 0x4e, 0xbe, 0xc5, 0xe4, 0x31, 0xd6, 0x98, 0x81,
  0x35, 0xb3, 0x58, 0xe9, 0x2c, 0x86, 0x30, 0x5c, 0x32, 0xb8, 0x12, 0x86, 0x3c,
  0x72, 0xfe, 0xd6, 0x91, 0x96, 0x80, 0x57, 0x15, 0x69, 0x48, 0xfb, 0x74, 0x76,
  0xaa, 0xef, 0x1b, 0x4b, 0x98, 0x0d, 0x4a, 0x48, 0x53, 0x41, 0xd3, 0x4b, 0x8a,
  0xd9, 0xc9, 0x42, 0xc6, 0x6b, 0x8b, 0xd8, 0xd7, 0x85, 0xcc, 0x1b, 0x6a, 0x28,
  0x64, 0x4b, 0x0a, 0x59, 0x6d, 0x15, 0x3b, 0x5a, 0xc9, 0x3c, 0xb2, 0x2c, 0x6b,
  0x99, 0x17, 0x37, 0x90, 0xdd, 0xeb, 0x89, 0x93, 0xa6, 0xf8, 0xd3, 0x6d, 0x63,
  0x92, 0x53, 0x4c, 0x64, 0x5d, 0x91, 0x93, 0xb5, 0xd4, 0xee, 0x39, 0xec, 0x83,
  0xd9, 0xcc, 0x9c, 0xf5, 0xd0, 0x9e, 0x87, 0x42, 0xc3, 0xc3, 0x33, 0x48, 0x70,
  0x98, 0x29, 0xa9, 0x5b, 0xcb, 0x48, 0xed, 0x6c, 0x52, 0xdf, 0x83, 0x30, 0xad,
  0x6f, 0x51, 0x09, 0x0b, 0x39, 0x42, 0x71, 0x7c, 0x12, 0x66, 0xcc, 0x79, 0x93,
  0x6d, 0x5e, 0xcc, 0x8f, 0xcc, 0x21, 0xc9, 0x87, 0x2e, 0x61, 0xf9, 0x25, 0x04,
  0xb3, 0x4f, 0x66, 0x30, 0x5d, 0x70, 0x5f, 0xe0, 0x58, 0xe0, 0xa2, 0x58, 0x68,
  0x8f, 0x13, 0x79, 0x44, 0xde, 0x4e, 0x0e, 0x5d, 0xc0, 0x2d, 0x17, 0xf0, 0x19,
  0x05, 0xa5, 0xb0, 0xec, 0x43, 0x85, 0x4b, 0xb6, 0x30, 0x79, 0xd8, 0x0c, 0x18,
  0xaa, 0x8c, 0xfe, 0x10, 0x57, 0xb3, 0x14, 0x11, 0x43, 0x7f, 0xe7, 0x39, 0xdc,
  0xd6, 0x8e, 0x30, 0x46, 0x03, 0x35, 0x96, 0x65, 0x4b, 0x4a, 0xc9, 0x59, 0x3c,
  0xdd, 0x86, 0x67, 0xdb, 0xb0, 0xa0, 0x0d, 0x59, 0x49, 0x1b, 0x6e, 0xfd, 0x04,
  0x53, 0xa4, 0x80, 0x08, 0x85, 0xa7, 0xf8, 0x87, 0x59, 0xd6, 0x50, 0x3d, 0x23,
  0x72, 0x80, 0xa8, 0x6a, 0x4c, 0x58, 0x6b, 0xc8, 0x08, 0xdb, 0xdb, 0x44, 0x06,
  0x82, 0x24, 0xcb, 0xc3, 0xc5, 0x70, 0xa5, 0xee, 0x10, 0xae, 0x3f, 0x88, 0x93,
  0x3e, 0x3c, 0x80, 0xf9, 0xfb, 0x51, 0x33, 0xb5, 0x94, 0x47, 0x51, 0x91, 0x00,
  0xdf, 0xa2, 0xff, 0x06, 0x71, 0xb6, 0x1d, 0x3f, 0x70, 0x0f, 0x51, 0x84, 0x1b,
  0xb8, 0x50, 0x67, 0x0b, 0xee, 0x6c, 0x41, 0xbf, 0x9b, 0xe4, 0xe6, 0x35, 0xe4,
  0xcb, 0x35, 0xc4, 0xeb, 0x8f, 0xae, 0xda, 0x83, 0x1d, 0xbb, 0x71, 0xfc, 0x13,
  0x30, 0x5e, 0xf6, 0x4b, 0x7c, 0xc8, 0xdf, 0x5f, 0x8a, 0x64, 0x4b, 0x4b, 0xc9,
  0x04, 0x5b, 0x1a, 0x15, 0xe1, 0x0b, 0x77, 0xe3, 0x8e, 0x5d, 0x88, 0xde, 0xb0,
  0x9a, 0x24, 0x71, 0x30, 0xac, 0x29, 0x17, 0x8f, 0x63, 0xe9, 0xc7, 0xe8, 0x0d,
  0x99, 0x20, 0x92, 0x56, 0x36, 0xe1, 0xc9, 0x1d, 0xa8, 0x66, 0xac, 0x6b, 0x20,
  0xde, 0x44, 0x03, 0x51, 0xc0, 0x80, 0xa8, 0x7c, 0xe0, 0x28, 0x16, 0x1c, 0x45,
  0xae, 0x18, 0xb2, 0xe4, 0xa8, 0x73, 0x8f, 0xe0, 0x85, 0xc3, 0x68, 0x68, 0xa0,
  0x4c, 0xe1, 0x6b, 0xb7, 0x92, 0xca, 0x6e, 0x96, 0xdf, 0x80, 0xdc, 0xd2, 0x7c,
  0x8e, 0x2e, 0xa1, 0x63, 0x0c, 0x17, 0x85, 0x9b, 0x71, 0xc7, 0x26, 0x54, 0x20,
  0x47, 0x36, 0x32, 0x87, 0xf1, 0x4a, 0xf2, 0x47, 0xb4, 0xc1, 0x2f, 0x12, 0x64,
  0x82, 0x65, 0x1a, 0x7c, 0xf1, 0x5e, 0xbc, 0xd4, 0x8c, 0xfa, 0x10, 0xae, 0xca,
  0x51, 0xef, 0xf6, 0xf5, 0x58, 0xb0, 0x1e, 0x25, 0x34, 0xc2, 0x18, 0x90, 0xfc,
  0x02, 0x30, 0x7d, 0xce, 0x3a, 0xac, 0xae, 0x43, 0x27, 0x09, 0x2b, 0x88, 0xec,
  0xc8, 0xca, 0x34, 0xa2, 0x1f, 0x5f, 0x85, 0x5b, 0x56, 0xa1, 0x24, 0xd2, 0x54,
  0xd7, 0xd9, 0x14, 0x5d, 0x80, 0x62, 0x2a, 0xb6, 0x6c, 0xf0, 0xb1, 0x7d, 0x24,
  0x07, 0x32, 0x32, 0x02, 0x30, 0x30, 0xec, 0x73, 0xd2, 0x15, 0x33, 0x55, 0x98,
  0xa3, 0x53, 0xfa, 0xa1, 0x85, 0x61, 0xd0, 0x3f, 0xab, 0xc6, 0x8e, 0x6a, 0xd4,
  0x85, 0x7a, 0x7c, 0x29, 0x2e, 0x5a, 0x8a, 0x68, 0x8c, 0xed, 0xad, 0xe7, 0x62,
  0xc8, 0xed, 0xa7, 0xab, 0xf7, 0x91, 0xca, 0xfd, 0xc4, 0xca, 0xc4, 0x57, 0x0a,
  0x37, 0xe0, 0xea, 0xf5, 0x08, 0x27, 0xde, 0xc6, 0x37, 0xde, 0xc6, 0x70, 0x38,
  0xaa, 0x03, 0x0a, 0x29, 0x4d, 0x56, 0xb8, 0x2e, 0xa7, 0x71, 0x07, 0x4e, 0xcd,
  0xc7, 0xdd, 0xf3, 0xdd, 0x36, 0x7c, 0xab, 0x73, 0x06, 0x11, 0x84, 0x69, 0x68,
  0x18, 0x05, 0xb4, 0x05, 0x17, 0x83, 0xc2, 0x6e, 0x85, 0xe8, 0x1a, 0xf8, 0xb2,
  0x31, 0x9c, 0x94, 0x47, 0xf4, 0xe8, 0xb6, 0x56, 0xd2, 0x70, 0x8c, 0x84, 0x53,
  0x50, 0xf6, 0x82, 0x5b, 0x15, 0xaa, 0xa5, 0x46, 0x41, 0x45, 0x74, 0x92, 0x11,
  0x54, 0x61, 0xda, 0x0a, 0xca, 0x7e, 0xc3, 0xb0, 0xec, 0x18, 0x3a, 0x0a, 0x58,
  0x9c, 0x27, 0xc9, 0xc1, 0xf0, 0xa4, 0x0a, 0x12, 0x36, 0x00, 0x23, 0xf2, 0x7b,
  0x45, 0xb8, 0xb1, 0x10, 0x2b, 0xab, 0x70, 0x49, 0x15, 0xbe, 0x60, 0x59, 0x7d,
  0xb2, 0xfd, 0x9c, 0xd7, 0x4d, 0x43, 0x98, 0xe5, 0x8e, 0xb7, 0xdc, 0x01, 0xe7,
  0xf2, 0xf1, 0x62, 0x3e, 0x4e, 0x86, 0x1d, 0x53, 0xb1, 0x3e, 0x1f, 0x61, 0x72,
  0xc1, 0x54, 0x8c, 0x2a, 0x0e, 0x9e, 0x9f, 0x8f, 0x07, 0xe7, 0xa3, 0xee, 0xc5,
  0xf0, 0xd2, 0xd7, 0x71, 0x63, 0x1e, 0x66, 0x39, 0xfb, 0x6e, 0xd0, 0x45, 0x37,
  0x68, 0xac, 0xb1, 0x1c, 0xcb, 0xcb, 0x51, 0x0d, 0xa4, 0xfa, 0x43, 0x31, 0xcb,
  0x54, 0xfc, 0x5e, 0xe4, 0x4f, 0x77, 0x5d, 0xa5, 0xd7, 0xbe, 0xa6, 0x98, 0xf3,
  0xbb, 0x41, 0x18, 0xe0, 0xd5, 0xe7, 0xc8, 0x86, 0xcb, 0xec, 0x83, 0x12, 0x0c,
  0x9a, 0x61, 0xc9, 0x4c, 0x89, 0x0a, 0x31, 0x0a, 0x0c, 0x5d, 0xb6, 0x1c, 0xc5,
  0xd0, 0xd2, 0x34, 0x35, 0x24, 0xa7, 0xe8, 0xba, 0xf7, 0xfc, 0x17, 0xf4, 0x64,
  0x17, 0xfd, 0xa5, 0x26, 0x8a, 0xbf, 0xa0, 0xd5, 0x5d, 0xd4, 0xb0, 0x47, 0xf2,
  0x6e, 0x58, 0xde, 0x49, 0x4b, 0x3b, 0xa8, 0x9c, 0x63, 0x7b, 0x85, 0x17, 0xcd,
  0xa6, 0x0b, 0x74, 0xe6, 0x05, 0xea, 0xb7, 0x51, 0xaa, 0x74, 0x3b, 0x4c, 0x20,
  0x7b, 0x5c, 0x58, 0x01, 0xa9, 0x92, 0xd8, 0x92, 0x3a, 0xa3, 0x8d, 0x96, 0xb6,
  0x32, 0x75, 0xc6, 0x15, 0x12, 0x9c, 0x73, 0x99, 0xfe, 0xeb, 0x2b, 0x1a, 0x40,
  0x90, 0x24, 0x4d, 0x01, 0xc5, 0xce, 0x71, 0xe3, 0xd9, 0x44, 0x5e, 0x33, 0xbc,
  0x9a, 0xd0, 0x45, 0x8e, 0x66, 0xca, 0xb6, 0x9b, 0x30, 0x45, 0x45, 0x47, 0x8b,
  0x48, 0xa2, 0xf6, 0x18, 0x5d, 0xdd, 0x4a, 0x23, 0x3e, 0xee, 0x8f, 0xfa, 0xdc,
  0x4b, 0x80, 0x57, 0x3a, 0xe9, 0xbc, 0x0e, 0x3a, 0x58, 0x32, 0x47, 0x19, 0x97,
  0x0f, 0xd0, 0x33, 0xfb, 0xe9, 0x73, 0x7e, 0x1e, 0xb0, 0x62, 0x3c, 0x3d, 0x7b,
  0x90, 0x04, 0xc6, 0x89, 0x73, 0xb4, 0xf9, 0x1c, 0xf5, 0xd9, 0xe9, 0x62, 0x53,
  0x33, 0x5d, 0xd1, 0x4c, 0xa7, 0xe7, 0xc3, 0xc2, 0x7c, 0xd0, 0x32, 0x87, 0x4c,
  0x23, 0x08, 0xd6, 0x5e, 0x12, 0x86, 0x2c, 0x50, 0xcb, 0x8b, 0xa0, 0xb5, 0x08,
  0xc2, 0xc9, 0x42, 0x16, 0xc6, 0x97, 0xc4, 0x3f, 0x44, 0x7c, 0x72, 0x82, 0x96,
  0x9e, 0xa0, 0xc3, 0x8b, 0x77, 0xd2, 0x59, 0x3b, 0x29, 0xb8, 0x8e, 0xa3, 0xa2,
  0xac, 0x24, 0x15, 0xef, 0xd3, 0x05, 0x4d, 0xd4, 0xe7, 0x4b, 0xe1, 0xde, 0x90,
  0xa3, 0xd8, 0x22, 0x28, 0x9e, 0x19, 0x69, 0x87, 0xb0, 0xb5, 0x91, 0xba, 0x45,
  0xb3, 0xa5, 0x91, 0x5a, 0x92, 0xf3, 0x7c, 0x2b, 0xa4, 0x5f, 0xd9, 0x4c, 0x0b,
  0x36, 0xd1, 0x80, 0x90, 0x5b, 0x36, 0xd2, 0x65, 0x1b, 0xa9, 0xb6, 0x12, 0xd2,
  0xb9, 0x5c, 0x46, 0x78, 0xf2, 0x78, 0xa3, 0x70, 0x17, 0xfd, 0xe6, 0x1f, 0xb4,
  0x67, 0x01, 0x74, 0x56, 0x40, 0x96, 0xad, 0xa5, 0x1d, 0x6a, 0xa2, 0x6b, 0x77,
  0x50, 0x7b, 0xac, 0x90, 0x93, 0xb3, 0xbb, 0x57, 0xd2, 0xf8, 0x0a, 0xea, 0x75,
  0xcb, 0x49, 0xf1, 0x19, 0x32, 0xa0, 0x23, 0x83, 0x4f, 0x3a, 0x5b, 0x43, 0xab,
  0x6b, 0x5c, 0x0f, 0xdc, 0x5b, 0xa7, 0x22, 0xd7, 0x8c, 0x40, 0x4e, 0xcc, 0x92,
  0x8c, 0x58, 0xd6, 0x23, 0x6e, 0xcd, 0x84, 0xb5, 0x1c, 0xb7, 0xf0, 0x04, 0x37,
  0x47, 0x3a, 0xb9, 0xee, 0x45, 0xf3, 0xa6, 0x4b, 0x31, 0x14, 0xee, 0x43, 0x90,
  0xec, 0xf6, 0x86, 0xd1, 0x6a, 0xc4, 0x4c, 0x82, 0xec, 0xde, 0x93, 0x22, 0x51,
  0x55, 0x86, 0x06, 0xf4, 0x29, 0x9c, 0xeb, 0x8a, 0x25, 0xf1, 0x9d, 0x75, 0x70,
  0xa8, 0x0e, 0x44, 0x37, 0x79, 0xba, 0x6e, 0x26, 0xbd, 0xf6, 0x26, 0x55, 0x60,
  0x8c, 0x39, 0xa7, 0x84, 0x5e, 0x9b, 0x49, 0xe5, 0x62, 0xa2, 0xfa, 0x01, 0x8c,
  0xa0, 0x94, 0x11, 0x35, 0x15, 0x35, 0xc4, 0xa2, 0x17, 0xa7, 0xd3, 0xf8, 0x74,
  0x1a, 0xf4, 0x4a, 0xdd, 0xc5, 0x74, 0x6d, 0x31, 0x75, 0xff, 0x2f, 0x10, 0x3a,
  0x0b, 0xe8, 0xe1, 0x02, 0xaa, 0x54, 0x12, 0x2b, 0xbd, 0xcd, 0x7d, 0x3e, 0xf7,
  0x10, 0x18, 0xaa, 0x81, 0xee, 0x17, 0x62, 0x0f, 0x31, 0xd0, 0x50, 0x33, 0x35,
  0x39, 0xa9, 0xb4, 0x11, 0x56, 0x35, 0xc2, 0xef, 0x63, 0x83, 0x4c, 0x6e, 0xcb,
  0x92, 0xad, 0x25, 0x7b, 0x23, 0x01, 0x89, 0x67, 0xa6, 0x59, 0xc0, 0x1d, 0xf4,
  0xef, 0x05, 0xc8, 0x16, 0x86, 0xcf, 0x6b, 0x5a, 0xe6, 0xa8, 0xc1, 0x4e, 0xac,
  0xa5, 0x98, 0xae, 0x2e, 0xa6, 0x43, 0xac, 0x16, 0x92, 0x21, 0xab, 0x5c, 0x02,
  0xcb, 0x9a, 0x32, 0x32, 0xed, 0x65, 0xc1, 0x8d, 0x83, 0x73, 0x61, 0x57, 0xaf,
  0x06, 0x71, 0x6a, 0xec, 0x8c, 0x07, 0xff, 0x03,
};

optimizesize void *__jisx0213_1_bmp_decmap(void) {
  return xloadzd(&__jisx0213_1_bmp_decmap_ptr,
                 __jisx0213_1_bmp_decmap_rodata,
                 2205, 2892, 2197, 2, 0x54509b20u); /* 50.1821% profit */
}
