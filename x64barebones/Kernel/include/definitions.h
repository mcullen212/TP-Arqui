#ifndef DEFINITIONS_H
#define DEFINITIONS_H

// Access
#define ACS_PRESENT 0x80        // Segmento presente en memoria
#define ACS_CSEG 0x18           // Code segment
#define ACS_DSEG 0x20           // Data segment
#define ACS_READ 0x02           // Read segment
#define ACS_WRITE 0x02          // Write segment
#define ACS_IDT ACS_CSEG        // Interrupt Descriptor Table
#define ACS_INT_386 0x0E	    // Interrupt GATE 32 bits
#define ACS_INT ( ACS_PRESENT | ACS_INT_386 )

#define ACS_CODE (ACS_PRESENT | ACS_CSEG | ACS_READ)
#define ACS_DATA (ACS_PRESENT | ACS_DSEG | ACS_WRITE)
#define ACS_STACK (ACS_PRESENT | ACS_DSEG | ACS_WRITE)

#endif
