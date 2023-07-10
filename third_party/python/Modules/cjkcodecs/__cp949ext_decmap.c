#include "libc/x/x.h"
#include "third_party/python/Modules/cjkcodecs/xloadzd.h"
/* clang-format off */

static _Atomic(void *) __cp949ext_decmap_ptr;
static const unsigned char __cp949ext_decmap_rodata[1970] = {
  0xb5, 0x5a, 0x09, 0x53, 0x14, 0x47, 0x14, 0xce, 0x9b, 0xea, 0x74, 0x4d, 0x6d,
  0x51, 0xa9, 0x94, 0xbf, 0x58, 0x0c, 0x06, 0x14, 0x03, 0x09, 0x15, 0x14, 0x2c,
  0x51, 0x82, 0x20, 0x97, 0x2c, 0x57, 0xb8, 0xef, 0x43, 0xb9, 0x14, 0x10, 0x95,
  0xc3, 0x93, 0x18, 0x62, 0xd0, 0xa0, 0x20, 0x2a, 0x1a, 0x4a, 0x4d, 0x66, 0xe6,
  0xbd, 0x9d, 0xe9, 0x9e, 0xe9, 0x37, 0x33, 0xbb, 0xa9, 0x74, 0x6d, 0xb1, 0x5b,
  0x3d, 0xdf, 0xbc, 0xf7, 0xba, 0xfb, 0xdd, 0x4d, 0x49, 0xd7, 0xd7, 0x96, 0xb0,
  0x32, 0x96, 0x33, 0x4e, 0x14, 0x39, 0xbf, 0xdc, 0x8f, 0x3b, 0xa4, 0x6d, 0x59,
  0x3f, 0xaf, 0x58, 0x5f, 0xb9, 0xe3, 0xa7, 0x15, 0x77, 0x42, 0x79, 0xe8, 0x0c,
  0x81, 0x3f, 0xc5, 0xda, 0x32, 0x62, 0x56, 0x96, 0x2d, 0x1d, 0xe0, 0x0f, 0xf7,
  0x45, 0xe9, 0xcd, 0xcb, 0x8c, 0xcb, 0x48, 0xe7, 0xe1, 0x0c, 0xdb, 0x79, 0x1e,
  0x4c, 0x08, 0x02, 0x08, 0x9d, 0x51, 0x8e, 0x8e, 0x70, 0xe0, 0xd2, 0xf2, 0xe5,
  0x41, 0xba, 0x39, 0x61, 0xf4, 0x17, 0x89, 0xea, 0xf9, 0x25, 0x94, 0xb0, 0x72,
  0x49, 0xe3, 0xad, 0xbd, 0xb3, 0xbc, 0x88, 0x98, 0x85, 0x45, 0xcb, 0xc4, 0x36,
  0xe3, 0x49, 0xa9, 0xb0, 0x55, 0x57, 0x47, 0x54, 0x42, 0x43, 0x7d, 0x3d, 0xe0,
  0x19, 0x3c, 0xe4, 0xf7, 0xca, 0x0e, 0xcb, 0xe7, 0x8d, 0xd9, 0x39, 0x94, 0x70,
  0x6a, 0xce, 0x62, 0xb7, 0xb8, 0x84, 0x30, 0xc5, 0x73, 0x1e, 0x01, 0x47, 0x34,
  0x61, 0x07, 0x9b, 0x64, 0xe3, 0x96, 0x44, 0xb6, 0x9f, 0x5b, 0x41, 0xec, 0xb0,
  0x0d, 0x64, 0x84, 0xba, 0x7a, 0xe3, 0x91, 0x58, 0x87, 0x33, 0x28, 0xe1, 0xfe,
  0x8c, 0xc7, 0x56, 0x98, 0xd8, 0xf6, 0x13, 0xa6, 0x77, 0x46, 0x59, 0x9e, 0xf0,
  0xb7, 0xd0, 0x36, 0x89, 0x2c, 0x95, 0xbf, 0x86, 0x63, 0xd0, 0xa4, 0x90, 0xca,
  0x2c, 0x37, 0x94, 0x6d, 0xa2, 0x73, 0x17, 0x0a, 0xbd, 0xe1, 0x49, 0x94, 0x70,
  0x60, 0x52, 0xe7, 0xae, 0xf2, 0x38, 0x9a, 0x40, 0xcc, 0x9b, 0x09, 0xd3, 0x99,
  0xcb, 0x88, 0x9e, 0x98, 0x85, 0xc0, 0x75, 0xdb, 0x42, 0x24, 0x1d, 0x90, 0x34,
  0xa8, 0xb6, 0x4d, 0x76, 0x2d, 0x8b, 0x9c, 0x4d, 0x8b, 0x9e, 0xd7, 0xe6, 0x28,
  0x4a, 0x78, 0x7f, 0x54, 0x79, 0x28, 0x74, 0x91, 0x2e, 0x11, 0xa6, 0x76, 0x94,
  0xe3, 0xeb, 0xee, 0xa6, 0xf4, 0xa9, 0x9a, 0xf8, 0x68, 0xcb, 0x96, 0xbc, 0xee,
  0x1b, 0x8d, 0xda, 0x0e, 0xa3, 0xc3, 0x2f, 0x9e, 0x1b, 0x42, 0x09, 0xcf, 0x0c,
  0x59, 0xc6, 0xd3, 0x77, 0x3f, 0x6b, 0x83, 0xe4, 0xa3, 0x06, 0x43, 0x76, 0x28,
  0x75, 0x47, 0x23, 0x02, 0x63, 0xb2, 0x8c, 0x46, 0x18, 0xb5, 0xef, 0x98, 0x53,
  0x61, 0x0e, 0x5c, 0xd3, 0xdd, 0x9c, 0x2e, 0x6e, 0xf7, 0xa1, 0x84, 0x8f, 0xfb,
  0x50, 0x26, 0xdb, 0xf2, 0x2d, 0xd8, 0x27, 0x53, 0x41, 0x98, 0xf2, 0xbe, 0xc4,
  0x5d, 0x73, 0xcd, 0xbe, 0xc8, 0xa1, 0x52, 0x64, 0x3c, 0x91, 0x3c, 0x4d, 0x5d,
  0x31, 0x79, 0x29, 0x91, 0x85, 0x70, 0xcf, 0x3c, 0x4a, 0xf7, 0x59, 0x37, 0x4a,
  0xf8, 0xb4, 0xdb, 0xe2, 0xbc, 0xa4, 0x68, 0x20, 0xcc, 0x95, 0x6e, 0x5e, 0x03,
  0xbc, 0x45, 0x48, 0x4f, 0xf9, 0x59, 0x6d, 0x89, 0x3d, 0x12, 0xb3, 0xcb, 0x4d,
  0x69, 0x3b, 0x5d, 0x59, 0x94, 0xb0, 0x23, 0xcb, 0x33, 0xfa, 0xd8, 0x81, 0x98,
  0xf7, 0x1d, 0x2c, 0x71, 0x63, 0x48, 0x32, 0x79, 0xc5, 0xc0, 0xe4, 0x94, 0x48,
  0x29, 0x52, 0xb9, 0xa8, 0x9c, 0x9a, 0x66, 0x22, 0xcb, 0xb0, 0x0f, 0xda, 0x50,
  0xc2, 0x57, 0x6d, 0x8c, 0x5d, 0x3a, 0xa3, 0x85, 0x30, 0x4d, 0x6d, 0x05, 0x29,
  0x04, 0x32, 0x8c, 0x35, 0xfe, 0x74, 0x07, 0xc7, 0x1f, 0xc8, 0x74, 0x33, 0x4a,
  0x38, 0xd1, 0x1c, 0xde, 0xd5, 0xe0, 0xab, 0x8c, 0x30, 0xa7, 0x9b, 0xd3, 0xf2,
  0x11, 0x05, 0xd9, 0x80, 0xb2, 0xbf, 0x32, 0xd5, 0x3a, 0x7c, 0xc4, 0x74, 0x23,
  0xad, 0xa2, 0x91, 0xf7, 0x12, 0x65, 0x84, 0x39, 0xdd, 0xa8, 0x07, 0xa9, 0x24,
  0x89, 0x64, 0x5c, 0x6a, 0x21, 0x19, 0x67, 0xa4, 0x78, 0x3a, 0x7f, 0xce, 0xd1,
  0xa1, 0x8c, 0x15, 0x17, 0xd5, 0x8f, 0xeb, 0x51, 0xc2, 0x0f, 0xf5, 0x7a, 0x82,
  0xa4, 0x8e, 0x69, 0xc2, 0x4c, 0xd4, 0xc7, 0x98, 0x58, 0x54, 0x59, 0x4c, 0xf2,
  0xd8, 0xa6, 0xa3, 0x12, 0x22, 0x26, 0xde, 0x19, 0x8e, 0x35, 0x2a, 0xe3, 0x78,
  0x1d, 0x4a, 0x38, 0x52, 0xc7, 0xbb, 0x8d, 0x53, 0x84, 0xf9, 0xe7, 0x12, 0x9b,
  0x5b, 0x9a, 0x24, 0xfe, 0x2f, 0xc1, 0x42, 0x6a, 0x0e, 0x21, 0x86, 0x3a, 0xce,
  0x9d, 0xba, 0x48, 0x12, 0xd6, 0xe6, 0x9e, 0xca, 0x48, 0xf6, 0x33, 0x59, 0x8b,
  0x98, 0xb1, 0xda, 0xc4, 0x4c, 0xc1, 0x99, 0x2b, 0xca, 0x91, 0xd1, 0x73, 0x85,
  0x8c, 0x39, 0x43, 0x14, 0x29, 0xad, 0x45, 0xf8, 0x71, 0xcc, 0xe4, 0x1d, 0x2e,
  0x9f, 0x47, 0x09, 0x2f, 0x9c, 0x0f, 0x1d, 0x9e, 0x1d, 0xf8, 0xc4, 0xcd, 0x6a,
  0xca, 0x52, 0xaa, 0xf9, 0xfc, 0x43, 0xc4, 0x6b, 0x81, 0x4c, 0x63, 0xa9, 0x49,
  0x5e, 0x3a, 0x50, 0x3d, 0x3f, 0xad, 0x12, 0xe8, 0xfe, 0x36, 0xab, 0x48, 0xc2,
  0x2a, 0x23, 0xdc, 0xfb, 0xbe, 0x48, 0x98, 0x0b, 0x55, 0x69, 0x04, 0xe0, 0x1e,
  0x08, 0x4b, 0xc4, 0x4f, 0x27, 0x3a, 0x0b, 0xaa, 0x04, 0x84, 0x9b, 0x1e, 0x14,
  0xf9, 0x6b, 0x70, 0x9f, 0x55, 0x55, 0x52, 0x95, 0x54, 0xa9, 0x9d, 0x92, 0x50,
  0x3d, 0xc0, 0x62, 0x05, 0x62, 0xe6, 0x2a, 0x52, 0x67, 0x11, 0x6a, 0x48, 0x93,
  0x61, 0x9f, 0x65, 0x1b, 0x92, 0x30, 0xa5, 0x02, 0x4c, 0xaa, 0x3b, 0x0c, 0x07,
  0x3e, 0x5d, 0x4e, 0xfe, 0xa7, 0x9c, 0x37, 0xbc, 0xb3, 0x84, 0x29, 0xd5, 0x31,
  0x32, 0xc6, 0x6f, 0x72, 0x2b, 0x0b, 0xf4, 0x40, 0x46, 0x39, 0xe5, 0x67, 0xf4,
  0x6a, 0x74, 0xbb, 0x58, 0x46, 0xda, 0x52, 0x66, 0xb1, 0x6e, 0x61, 0xbd, 0x14,
  0x31, 0x77, 0x4a, 0xad, 0x50, 0x04, 0x48, 0x6d, 0x95, 0x76, 0x68, 0x82, 0xcf,
  0xe0, 0xf3, 0x8c, 0xdf, 0xf8, 0xd2, 0x7a, 0x09, 0x49, 0x58, 0xe2, 0x93, 0xc8,
  0x15, 0xb7, 0x3e, 0x8d, 0x2a, 0xc2, 0x54, 0x96, 0x44, 0x38, 0xe8, 0x5c, 0x83,
  0xa4, 0x25, 0x5d, 0x1a, 0x57, 0x70, 0x96, 0x1b, 0x89, 0xdd, 0xc5, 0xa4, 0x51,
  0xc5, 0x3c, 0xe8, 0x1c, 0x61, 0xce, 0x14, 0x5b, 0x86, 0x65, 0x18, 0x4e, 0xf0,
  0xff, 0x18, 0xb1, 0x39, 0xe8, 0xcd, 0x2f, 0x80, 0xdd, 0x83, 0x2f, 0x60, 0x50,
  0x72, 0xb2, 0x0b, 0xc2, 0x94, 0xba, 0x98, 0x94, 0x25, 0xa6, 0xe3, 0x7e, 0x33,
  0x09, 0xcd, 0x05, 0xce, 0x60, 0x23, 0xd9, 0x6f, 0x11, 0x95, 0x17, 0xee, 0x8b,
  0xc2, 0x48, 0x6a, 0xf9, 0x18, 0x25, 0x5c, 0x38, 0x06, 0x73, 0x9e, 0xe0, 0x7c,
  0xbe, 0x27, 0xcc, 0x77, 0xc7, 0xa0, 0xef, 0x82, 0xad, 0xd7, 0x48, 0x82, 0xb5,
  0x3e, 0x5d, 0x3a, 0x19, 0x57, 0x54, 0x70, 0x01, 0x3a, 0x28, 0x1f, 0x45, 0xd4,
  0x2c, 0x0f, 0x8f, 0x50, 0xc2, 0xfd, 0x23, 0x30, 0xf9, 0x1e, 0x6f, 0x43, 0xba,
  0x08, 0xd3, 0x71, 0x04, 0x3c, 0x1f, 0xcd, 0xc9, 0xa8, 0xbe, 0x41, 0x6a, 0xc0,
  0x74, 0x19, 0xa4, 0x8d, 0x85, 0xa3, 0x94, 0x5a, 0xb1, 0x1e, 0x76, 0x08, 0x81,
  0xd2, 0xd4, 0xbc, 0x45, 0x09, 0xab, 0xdf, 0x02, 0xab, 0x8a, 0xcf, 0x0e, 0x11,
  0xf3, 0xf4, 0x10, 0x52, 0x79, 0x24, 0xa5, 0x4c, 0x2c, 0xc8, 0x7e, 0x45, 0x62,
  0x0c, 0xd2, 0xac, 0xd2, 0x19, 0x27, 0x0f, 0x50, 0xc2, 0xcf, 0xfb, 0xc0, 0xba,
  0xed, 0xf9, 0x7d, 0xc4, 0xdc, 0x30, 0x61, 0xf2, 0x6f, 0xe9, 0xa4, 0xea, 0x43,
  0xa5, 0xed, 0x2e, 0x90, 0x46, 0xed, 0x91, 0x46, 0xed, 0xf1, 0xfb, 0x3c, 0x4e,
  0x98, 0x91, 0x3d, 0x30, 0x39, 0x28, 0xea, 0xb5, 0x98, 0xd3, 0x8b, 0x84, 0xdc,
  0xd1, 0x76, 0x5f, 0x74, 0xff, 0x48, 0xde, 0x01, 0x08, 0x25, 0x61, 0xd2, 0x9b,
  0xb4, 0x3e, 0xed, 0x1f, 0x5f, 0xa0, 0x84, 0x3f, 0xbc, 0x00, 0x4c, 0x3b, 0xbf,
  0x15, 0x22, 0xcc, 0x30, 0xbb, 0x8b, 0x98, 0xf6, 0x5d, 0xc8, 0x99, 0xb4, 0xbb,
  0xef, 0xdf, 0x58, 0xa1, 0xc6, 0xb2, 0x54, 0xe4, 0xb5, 0xdd, 0x96, 0xb1, 0x27,
  0xac, 0xb4, 0x52, 0x76, 0x2d, 0x65, 0x52, 0x71, 0xa2, 0xce, 0xd9, 0xda, 0xcc,
  0xf6, 0x0e, 0x4a, 0xf8, 0x78, 0x07, 0xa2, 0x76, 0x43, 0x34, 0x6a, 0x08, 0x53,
  0xbd, 0x03, 0x51, 0xad, 0x8c, 0x67, 0xab, 0x2f, 0xc3, 0xf1, 0x2e, 0x27, 0xcc,
  0x99, 0xa0, 0x2f, 0x99, 0x9d, 0x41, 0x6f, 0x6a, 0x0b, 0xae, 0x53, 0x10, 0x6e,
  0xb1, 0xba, 0x5f, 0xb3, 0xdb, 0x28, 0xe1, 0xc4, 0x36, 0xb0, 0x26, 0x59, 0x46,
  0x98, 0xd3, 0xdb, 0x60, 0x4c, 0xf8, 0x93, 0x7d, 0xbf, 0x4c, 0xee, 0x3d, 0x87,
  0x13, 0x16, 0x3d, 0x7f, 0x10, 0x7c, 0xc9, 0xe5, 0x52, 0x3e, 0x7e, 0x84, 0x12,
  0x7e, 0x78, 0x04, 0x6c, 0x01, 0xdc, 0x43, 0x98, 0xce, 0x47, 0x60, 0x32, 0xc1,
  0xe8, 0x09, 0x1b, 0x78, 0x5d, 0x7b, 0x88, 0x34, 0x7e, 0x79, 0x08, 0xac, 0xdd,
  0xbe, 0x7e, 0x80, 0x98, 0xbf, 0x1e, 0x40, 0xea, 0x9b, 0x81, 0xb0, 0xe5, 0x3d,
  0xd9, 0x42, 0x1a, 0x5b, 0x5b, 0x60, 0x71, 0x2e, 0xbe, 0x9e, 0x30, 0x75, 0x5b,
  0x10, 0x9f, 0x8b, 0x4b, 0x3c, 0x72, 0x61, 0x88, 0xd5, 0xef, 0x36, 0x90, 0xc6,
  0x9b, 0x0d, 0xe0, 0x0a, 0x71, 0xab, 0x87, 0x30, 0x9d, 0x1b, 0x90, 0xbe, 0x1c,
  0x0c, 0x85, 0xec, 0x96, 0x75, 0xa4, 0xd1, 0xb4, 0x0e, 0x6c, 0xea, 0x72, 0x70,
  0x1f, 0x31, 0xaf, 0xee, 0x43, 0xc1, 0x9d, 0xa4, 0xc3, 0x7b, 0xe4, 0x1f, 0xef,
  0x81, 0x6e, 0x47, 0x0a, 0x95, 0x2c, 0x61, 0xda, 0x3d, 0x8c, 0xc8, 0xaf, 0xc9,
  0x48, 0xcf, 0xda, 0xee, 0x22, 0x8d, 0xe6, 0xbb, 0xc0, 0x3a, 0xed, 0x77, 0x6b,
  0xb4, 0xb7, 0x6b, 0x90, 0x3e, 0x1c, 0x84, 0x52, 0xb5, 0xbd, 0x3b, 0x48, 0xe3,
  0xc5, 0x1d, 0x60, 0x05, 0xec, 0x27, 0x4c, 0xaf, 0x09, 0x93, 0x10, 0x58, 0xfc,
  0x98, 0xb1, 0x4a, 0x31, 0x63, 0x15, 0xd8, 0xec, 0xb5, 0x84, 0x30, 0xc5, 0xab,
  0x10, 0x1b, 0xea, 0xa8, 0x05, 0x20, 0x84, 0xa1, 0x65, 0xb9, 0xbd, 0x4c, 0x3e,
  0x73, 0x19, 0x42, 0x29, 0x5d, 0xe0, 0x93, 0x6a, 0x08, 0x53, 0xbd, 0x0c, 0x85,
  0xa9, 0x9b, 0x33, 0x75, 0xf6, 0x36, 0x65, 0xb8, 0xb7, 0x81, 0x2d, 0x22, 0xe7,
  0x6f, 0x51, 0xb4, 0xbf, 0x65, 0x8e, 0xf6, 0x56, 0x7c, 0x8a, 0xef, 0xd1, 0x1b,
  0x5d, 0x42, 0x1a, 0x43, 0x4b, 0x60, 0x72, 0x9d, 0xde, 0xef, 0x93, 0x84, 0xf9,
  0xbc, 0x08, 0xa9, 0x3b, 0x13, 0x61, 0x17, 0xf4, 0x69, 0x01, 0x69, 0xfc, 0xbd,
  0x00, 0x6c, 0xa8, 0x1e, 0x27, 0xcc, 0x88, 0x87, 0x49, 0xd5, 0xa3, 0x8a, 0x3c,
  0x1c, 0x9e, 0x47, 0x1a, 0x03, 0xf3, 0xc0, 0x0a, 0xf5, 0x71, 0x0e, 0x31, 0xef,
  0xe7, 0x20, 0xa6, 0xbb, 0x1d, 0x5e, 0x89, 0x3e, 0x5e, 0xde, 0x44, 0x1a, 0x7f,
  0xde, 0x04, 0xf6, 0x56, 0xb4, 0x91, 0x30, 0x57, 0x08, 0x23, 0xd3, 0xf5, 0x11,
  0x35, 0x0b, 0x2a, 0xbb, 0x41, 0x91, 0xeb, 0x06, 0xb0, 0xd6, 0xb0, 0x36, 0x8b,
  0x98, 0x95, 0x59, 0x60, 0x7b, 0xae, 0x49, 0x25, 0x4e, 0xff, 0x0c, 0xd2, 0xe8,
  0x9e, 0x01, 0xb6, 0x2b, 0xfe, 0x6e, 0x9a, 0xfc, 0xc1, 0x34, 0xa4, 0x28, 0xb7,
  0x8c, 0x1b, 0x2b, 0x9e, 0x4d, 0x51, 0x9e, 0x3d, 0xc5, 0xfa, 0x03, 0xd1, 0x46,
  0x98, 0xe6, 0x29, 0x28, 0xa0, 0x33, 0x8f, 0x8c, 0xdb, 0x26, 0x89, 0xc6, 0x24,
  0xb0, 0x41, 0x7d, 0x77, 0x02, 0x31, 0x7f, 0x4c, 0x40, 0xb4, 0x61, 0x9f, 0xc6,
  0x78, 0x9c, 0xf1, 0x64, 0x9c, 0xe2, 0xdc, 0x38, 0xb0, 0xe1, 0xf0, 0x32, 0x61,
  0x6a, 0xc7, 0x21, 0xbf, 0xaa, 0x5f, 0x61, 0x58, 0x33, 0x46, 0x3e, 0x65, 0x0c,
  0xa4, 0xa1, 0x7e, 0xf2, 0x0e, 0x6b, 0x7e, 0x94, 0xfc, 0xc1, 0x28, 0xc8, 0x74,
  0x57, 0x69, 0x86, 0x9e, 0xf3, 0x08, 0xd9, 0xe0, 0x08, 0xb0, 0xe9, 0xcd, 0x49,
  0xc2, 0x7c, 0x1e, 0x86, 0x44, 0xbd, 0xe2, 0xcc, 0x76, 0x77, 0x88, 0xf6, 0x7e,
  0x08, 0xd8, 0x95, 0x67, 0x09, 0xd3, 0x3a, 0xa4, 0xe5, 0x10, 0x31, 0x37, 0xcc,
  0xd1, 0xe9, 0x96, 0x41, 0x8a, 0xdb, 0x83, 0xc0, 0xf6, 0xc9, 0x0e, 0x06, 0x28,
  0xdf, 0x19, 0x80, 0x7c, 0x6e, 0xdb, 0x35, 0x0f, 0xb5, 0xd3, 0x8f, 0x34, 0x7e,
  0xeb, 0x07, 0xb6, 0x3c, 0xba, 0x4e, 0x98, 0xd6, 0x7e, 0xc8, 0xaf, 0xe4, 0x52,
  0xf4, 0xaa, 0xa1, 0x8f, 0x7c, 0x4a, 0x1f, 0x98, 0xae, 0xe2, 0xbc, 0x89, 0x07,
  0xbf, 0x22, 0x66, 0xe3, 0x57, 0xe0, 0x6f, 0x76, 0x8d, 0x77, 0xf0, 0x41, 0x7b,
  0xad, 0xbf, 0x97, 0x62, 0x72, 0x2f, 0xb0, 0xff, 0x89, 0xf1, 0xb2, 0x87, 0x7c,
  0x60, 0x0f, 0x14, 0x7c, 0x43, 0xf5, 0xba, 0x9b, 0xf6, 0xbe, 0x1b, 0x58, 0x37,
  0x55, 0x4f, 0x98, 0x3a, 0x0f, 0x13, 0x9b, 0x97, 0x0b, 0xee, 0xf2, 0xa5, 0xa2,
  0x0b, 0x69, 0x94, 0x77, 0xf1, 0xb1, 0x65, 0xb5, 0x13, 0x31, 0xb7, 0x3b, 0x21,
  0x65, 0xd2, 0x16, 0xd5, 0xc4, 0xf5, 0x2c, 0xd2, 0xb8, 0x9b, 0x05, 0xa6, 0x61,
  0xef, 0xd8, 0x32, 0x61, 0xaa, 0xb3, 0x90, 0xfe, 0x2a, 0x35, 0x34, 0x77, 0xae,
  0x03, 0x69, 0x9c, 0xe9, 0x00, 0xfe, 0x7f, 0x09, 0xae, 0x53, 0x5c, 0xb8, 0x0e,
  0x09, 0x3d, 0x79, 0xc1, 0x36, 0x8e, 0xa6, 0xdb, 0xa9, 0xba, 0x6a, 0xe7, 0xcf,
  0xb8, 0x82, 0x30, 0xe5, 0x1e, 0x26, 0x36, 0x18, 0x08, 0x2e, 0xf0, 0x3d, 0x6f,
  0x45, 0x1a, 0xbf, 0xb7, 0x02, 0xbb, 0x01, 0x59, 0xc2, 0xb4, 0xb7, 0x42, 0x2a,
  0xed, 0x12, 0x06, 0x11, 0xea, 0x5b, 0x48, 0x97, 0x5a, 0x80, 0x0d, 0xc3, 0x9b,
  0xcd, 0xb4, 0x6f, 0xcd, 0xa6, 0x8a, 0x52, 0x44, 0x8d, 0x48, 0x44, 0xfb, 0x74,
  0xc3, 0xd7, 0x28, 0x0f, 0xb9, 0x06, 0x8a, 0x3e, 0x6a, 0x25, 0xbc, 0xf5, 0xa9,
  0x89, 0x72, 0xa2, 0x26, 0x30, 0x55, 0xf3, 0x49, 0x97, 0x3b, 0x1e, 0xf6, 0x79,
  0x23, 0xf9, 0x9d, 0x46, 0xca, 0x7b, 0x0d, 0x87, 0xd9, 0x40, 0x98, 0x2b, 0x8d,
  0xc0, 0xe4, 0x38, 0x09, 0x41, 0xce, 0xcd, 0x47, 0xaf, 0x52, 0x3e, 0x7a, 0x15,
  0x4c, 0x8d, 0x3c, 0x2f, 0x45, 0x9e, 0x6c, 0x40, 0xcc, 0x58, 0x03, 0xd0, 0x7e,
  0x98, 0xff, 0x99, 0xc9, 0xc4, 0xe2, 0x5f,
};

optimizesize void *__cp949ext_decmap(void) {
  return xloadzd(&__cp949ext_decmap_ptr,
                 __cp949ext_decmap_rodata,
                 1970, 10204, 9650, 2, 0xb92a1dffu); /* 10.2073% profit */
}
