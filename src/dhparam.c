#include "common.h"
#ifndef OPENSSL_NO_DH
#define DN_new DH_new
#ifndef HEADER_DH_H
# include <openssl/dh.h>
#endif

DH *get_dh2048()
{
    static unsigned char dhp_2048[] = {
	0x97, 0xE0, 0xAB, 0x66, 0xE2, 0xE1, 0xDC, 0x78, 0x23, 0x7E, 
	0x2D, 0xBC, 0xD6, 0x57, 0xD3, 0x68, 0xC2, 0x91, 0xF7, 0xED, 
	0xDA, 0xBC, 0xCD, 0x55, 0x00, 0x40, 0x69, 0xFA, 0x20, 0x14, 
	0x10, 0x12, 0x4F, 0x4D, 0x58, 0x86, 0x8F, 0x5D, 0x1F, 0xD4, 
	0xF3, 0xF9, 0xFE, 0x57, 0x22, 0x34, 0x5E, 0xCC, 0x2B, 0x5D, 
	0xDD, 0x0F, 0x74, 0x05, 0xA5, 0x28, 0xEA, 0x58, 0x10, 0xA7, 
	0x24, 0xA4, 0xC5, 0x15, 0x9D, 0xA9, 0xEA, 0xEE, 0x08, 0xC7, 
	0x1D, 0x6A, 0x00, 0xEF, 0x5B, 0xEF, 0x46, 0x9B, 0x48, 0xB5, 
	0x1C, 0x11, 0x43, 0xB0, 0x6E, 0xA7, 0x47, 0x5C, 0x1B, 0x13, 
	0xC0, 0xDA, 0x0E, 0x94, 0xD6, 0x5C, 0x77, 0x87, 0xE8, 0x61, 
	0xC4, 0x33, 0x21, 0x8A, 0x34, 0x5D, 0x53, 0x1D, 0xC1, 0x21, 
	0x81, 0x43, 0xAE, 0x36, 0xCB, 0x71, 0x1F, 0x66, 0x0E, 0xAD, 
	0xA8, 0x72, 0x1D, 0x87, 0x6E, 0x25, 0x70, 0xD0, 0x88, 0x37, 
	0x61, 0x25, 0x44, 0x3B, 0x86, 0x27, 0xC3, 0xE3, 0x85, 0x0E, 
	0x8B, 0xAC, 0xC6, 0x4C, 0xE9, 0x16, 0x20, 0x4D, 0xAB, 0xED, 
	0xC6, 0xE8, 0x71, 0x39, 0x8F, 0x14, 0x8F, 0x86, 0xA5, 0x4E, 
	0xF1, 0x21, 0x99, 0xED, 0x78, 0x7C, 0x84, 0x7D, 0x0B, 0x41, 
	0x49, 0xA3, 0xE9, 0xEA, 0x15, 0x95, 0xF8, 0x05, 0x00, 0xC3, 
	0x74, 0x13, 0x40, 0x18, 0x25, 0x65, 0xBF, 0x3C, 0x0E, 0x3B, 
	0x44, 0xFF, 0x8D, 0x2D, 0x5F, 0x6A, 0x90, 0x0C, 0x6F, 0x4B, 
	0x24, 0x25, 0x25, 0x79, 0x4D, 0xD3, 0xF9, 0x57, 0xFC, 0xE3, 
	0x95, 0x00, 0x66, 0x94, 0xCD, 0x41, 0x0E, 0x6F, 0x51, 0x9B, 
	0x34, 0xE3, 0xFA, 0x20, 0x47, 0x6F, 0x21, 0xF0, 0xED, 0xDB, 
	0x5C, 0x6A, 0x76, 0xAF, 0xB8, 0xCD, 0x10, 0x8E, 0x24, 0x35, 
	0x08, 0xE0, 0x22, 0x51, 0x55, 0x01, 0x15, 0x33, 0xD4, 0xFF, 
	0xAA, 0x2E, 0x02, 0xD4, 0xC0, 0x2B
    };
    static unsigned char dhg_2048[] = {
	0x02
    };
    DH *dh = DN_new();

    if (dh == NULL)
        return NULL;
    dh->p = BN_bin2bn(dhp_2048, sizeof (dhp_2048), NULL);
    dh->g = BN_bin2bn(dhg_2048, sizeof (dhg_2048), NULL);
    if (!dh->p || !dh->g) {
        DH_free(dh);
        return NULL;
    }
    return dh;
}
#endif /* OPENSSL_NO_DH */
