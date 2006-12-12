//
// Register Declarations for Microchip 16C620 Processor
//
//
// This header file was automatically generated by:
//
//	inc2h.pl V1.6
//
//	Copyright (c) 2002, Kevin L. Pauba, All Rights Reserved
//
//	SDCC is licensed under the GNU Public license (GPL) v2.  Note that
//	this license covers the code to the compiler and other executables,
//	but explicitly does not cover any code or objects generated by sdcc.
//	We have not yet decided on a license for the run time libraries, but
//	it will not put any requirements on code linked against it. See:
// 
//	http://www.gnu.org/copyleft/gpl/html
//
//	See http://sdcc.sourceforge.net/ for the latest information on sdcc.
//
// 
#ifndef P16C620_H
#define P16C620_H

//
// Register addresses.
//
#define INDF_ADDR	0x0000
#define TMR0_ADDR	0x0001
#define PCL_ADDR	0x0002
#define STATUS_ADDR	0x0003
#define FSR_ADDR	0x0004
#define PORTA_ADDR	0x0005
#define PORTB_ADDR	0x0006
#define PCLATH_ADDR	0x000A
#define INTCON_ADDR	0x000B
#define PIR1_ADDR	0x000C
#define CMCON_ADDR	0x001F
#define OPTION_REG_ADDR	0x0081
#define TRISA_ADDR	0x0085
#define TRISB_ADDR	0x0086
#define PIE1_ADDR	0x008C
#define PCON_ADDR	0x008E
#define VRCON_ADDR	0x009F

//
// Memory organization.
//



//         LIST
// P16C620.INC  Standard Header File, Version 1.01    Microchip Technology, Inc.
//         NOLIST

// This header file defines configurations, registers, and other useful bits of
// information for the PIC16C620 microcontroller.  These names are taken to match 
// the data sheets as closely as possible.  

// Note that the processor must be selected before this file is 
// included.  The processor may be selected the following ways:

//       1. Command line switch:
//               C:\ MPASM MYFILE.ASM /PIC16C620
//       2. LIST directive in the source file
//               LIST   P=PIC16C620
//       3. Processor Type entry in the MPASM full-screen interface

//==========================================================================
//
//       Revision History
//
//==========================================================================

//Rev:   Date:    Reason:

//1.01   11/28/95 Added NOT_BOR to match revised datasheet
//1.00   10/31/95 Initial Release

//==========================================================================
//
//       Verify Processor
//
//==========================================================================

//        IFNDEF __16C620
//            MESSG "Processor-header file mismatch.  Verify selected processor."
//         ENDIF

//==========================================================================
//
//       Register Definitions
//
//==========================================================================

#define W                    0x0000
#define F                    0x0001

//----- Register Files------------------------------------------------------

extern __data __at (INDF_ADDR) volatile char      INDF;
extern __sfr  __at (TMR0_ADDR)                    TMR0;
extern __data __at (PCL_ADDR) volatile char       PCL;
extern __sfr  __at (STATUS_ADDR)                  STATUS;
extern __sfr  __at (FSR_ADDR)                     FSR;
extern __sfr  __at (PORTA_ADDR)                   PORTA;
extern __sfr  __at (PORTB_ADDR)                   PORTB;
extern __sfr  __at (PCLATH_ADDR)                  PCLATH;
extern __sfr  __at (INTCON_ADDR)                  INTCON;
extern __sfr  __at (PIR1_ADDR)                    PIR1;
extern __sfr  __at (CMCON_ADDR)                   CMCON;

extern __sfr  __at (OPTION_REG_ADDR)              OPTION_REG;
extern __sfr  __at (TRISA_ADDR)                   TRISA;
extern __sfr  __at (TRISB_ADDR)                   TRISB;
extern __sfr  __at (PIE1_ADDR)                    PIE1;
extern __sfr  __at (PCON_ADDR)                    PCON;
extern __sfr  __at (VRCON_ADDR)                   VRCON;

//----- STATUS Bits --------------------------------------------------------


//----- INTCON Bits --------------------------------------------------------


//----- PIR1 Bits ----------------------------------------------------------


//----- CMCON Bits ---------------------------------------------------------


//----- OPTION Bits --------------------------------------------------------


//----- PIE1 Bits ----------------------------------------------------------


//----- PCON Bits ----------------------------------------------------------


//----- VRCON Bits ---------------------------------------------------------


//==========================================================================
//
//       RAM Definition
//
//==========================================================================

//         __MAXRAM H'09F'
//         __BADRAM H'07'-H'09', H'0D'-H'1E', H'70'-H'7F'
//         __BADRAM H'87'-H'89', H'8D', H'8F'-H'9E'

//==========================================================================
//
//       Configuration Bits
//
//==========================================================================

#define _BODEN_ON            0x3FFF
#define _BODEN_OFF           0x3FBF
#define _CP_ON               0x00CF
#define _CP_OFF              0x3FFF
#define _PWRTE_OFF           0x3FFF
#define _PWRTE_ON            0x3FF7
#define _WDT_ON              0x3FFF
#define _WDT_OFF             0x3FFB
#define _LP_OSC              0x3FFC
#define _XT_OSC              0x3FFD
#define _HS_OSC              0x3FFE
#define _RC_OSC              0x3FFF

//         LIST

// ----- CMCON bits --------------------
typedef union {
  struct {
    unsigned char CM0:1;
    unsigned char CM1:1;
    unsigned char CM2:1;
    unsigned char CIS:1;
    unsigned char :1;
    unsigned char :1;
    unsigned char C1OUT:1;
    unsigned char C2OUT:1;
  };
} __CMCON_bits_t;
extern volatile __CMCON_bits_t __at(CMCON_ADDR) CMCON_bits;

#define CM0                  CMCON_bits.CM0
#define CM1                  CMCON_bits.CM1
#define CM2                  CMCON_bits.CM2
#define CIS                  CMCON_bits.CIS
#define C1OUT                CMCON_bits.C1OUT
#define C2OUT                CMCON_bits.C2OUT

// ----- INTCON bits --------------------
typedef union {
  struct {
    unsigned char RBIF:1;
    unsigned char INTF:1;
    unsigned char T0IF:1;
    unsigned char RBIE:1;
    unsigned char INTE:1;
    unsigned char T0IE:1;
    unsigned char PEIE:1;
    unsigned char GIE:1;
  };
} __INTCON_bits_t;
extern volatile __INTCON_bits_t __at(INTCON_ADDR) INTCON_bits;

#define RBIF                 INTCON_bits.RBIF
#define INTF                 INTCON_bits.INTF
#define T0IF                 INTCON_bits.T0IF
#define RBIE                 INTCON_bits.RBIE
#define INTE                 INTCON_bits.INTE
#define T0IE                 INTCON_bits.T0IE
#define PEIE                 INTCON_bits.PEIE
#define GIE                  INTCON_bits.GIE

// ----- OPTION_REG bits --------------------
typedef union {
  struct {
    unsigned char PS0:1;
    unsigned char PS1:1;
    unsigned char PS2:1;
    unsigned char PSA:1;
    unsigned char T0SE:1;
    unsigned char T0CS:1;
    unsigned char INTEDG:1;
    unsigned char NOT_RBPU:1;
  };
} __OPTION_REG_bits_t;
extern volatile __OPTION_REG_bits_t __at(OPTION_REG_ADDR) OPTION_REG_bits;

#define PS0                  OPTION_REG_bits.PS0
#define PS1                  OPTION_REG_bits.PS1
#define PS2                  OPTION_REG_bits.PS2
#define PSA                  OPTION_REG_bits.PSA
#define T0SE                 OPTION_REG_bits.T0SE
#define T0CS                 OPTION_REG_bits.T0CS
#define INTEDG               OPTION_REG_bits.INTEDG
#define NOT_RBPU             OPTION_REG_bits.NOT_RBPU

// ----- PCON bits --------------------
typedef union {
  struct {
    unsigned char NOT_BO:1;
    unsigned char NOT_POR:1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
  };
  struct {
    unsigned char NOT_BOR:1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
  };
} __PCON_bits_t;
extern volatile __PCON_bits_t __at(PCON_ADDR) PCON_bits;

#define NOT_BO               PCON_bits.NOT_BO
#define NOT_BOR              PCON_bits.NOT_BOR
#define NOT_POR              PCON_bits.NOT_POR

// ----- PIE1 bits --------------------
typedef union {
  struct {
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char CMIE:1;
    unsigned char :1;
  };
} __PIE1_bits_t;
extern volatile __PIE1_bits_t __at(PIE1_ADDR) PIE1_bits;

#define CMIE                 PIE1_bits.CMIE

// ----- PIR1 bits --------------------
typedef union {
  struct {
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char CMIF:1;
    unsigned char :1;
  };
} __PIR1_bits_t;
extern volatile __PIR1_bits_t __at(PIR1_ADDR) PIR1_bits;

#define CMIF                 PIR1_bits.CMIF

// ----- STATUS bits --------------------
typedef union {
  struct {
    unsigned char C:1;
    unsigned char DC:1;
    unsigned char Z:1;
    unsigned char NOT_PD:1;
    unsigned char NOT_TO:1;
    unsigned char RP0:1;
    unsigned char RP1:1;
    unsigned char IRP:1;
  };
} __STATUS_bits_t;
extern volatile __STATUS_bits_t __at(STATUS_ADDR) STATUS_bits;

#define C                    STATUS_bits.C
#define DC                   STATUS_bits.DC
#define Z                    STATUS_bits.Z
#define NOT_PD               STATUS_bits.NOT_PD
#define NOT_TO               STATUS_bits.NOT_TO
#define RP0                  STATUS_bits.RP0
#define RP1                  STATUS_bits.RP1
#define IRP                  STATUS_bits.IRP

// ----- VRCON bits --------------------
typedef union {
  struct {
    unsigned char VR0:1;
    unsigned char VR1:1;
    unsigned char VR2:1;
    unsigned char VR3:1;
    unsigned char :1;
    unsigned char VRR:1;
    unsigned char VROE:1;
    unsigned char VREN:1;
  };
} __VRCON_bits_t;
extern volatile __VRCON_bits_t __at(VRCON_ADDR) VRCON_bits;

#define VR0                  VRCON_bits.VR0
#define VR1                  VRCON_bits.VR1
#define VR2                  VRCON_bits.VR2
#define VR3                  VRCON_bits.VR3
#define VRR                  VRCON_bits.VRR
#define VROE                 VRCON_bits.VROE
#define VREN                 VRCON_bits.VREN

#endif
