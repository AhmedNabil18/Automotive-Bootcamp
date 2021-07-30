 /******************************************************************************
 *
 * File Name: Platform_Types.h
 *
 * Description: Platform types
 *
 * Author: Ahmed Nabil
 *
 *******************************************************************************/

#ifndef _PLATFORM_TYPES_H_
#define _PLATFORM_TYPES_H_

/*
 * CPU register type width
 */
#define CPU_TYPE_8                                  (8U)
#define CPU_TYPE_16                                 (16U)
#define CPU_TYPE_32                                 (32U)

/*
 * Bit order definition
 */
#define MSB_FIRST                   (0u)        /* Big Endian bit ordering        */
#define LSB_FIRST                   (1u)        /* Little Endian bit ordering     */

/*
 * Byte order definition
 */
#define HIGH_BYTE_FIRST             (0u)        /* Big Endian byte ordering       */
#define LOW_BYTE_FIRST              (1u)        /* Little Endian byte ordering    */

/*
 * Platform type and Endianess definitions
 */
#define CPU_TYPE            CPU_TYPE_32

#define CPU_BIT_ORDER       LSB_FIRST
#define CPU_BYTE_ORDER      LOW_BYTE_FIRST

/*
 * Boolean Values
 */
#ifndef FALSE
#define FALSE       (0u)
#endif
#ifndef TRUE
#define TRUE        (1u)
#endif

/* This is used to define the void pointer to zero definition */
#ifndef NULL_PTR
#define NULL_PTR          ((void *)0)
#endif

#ifndef NULL
#define NULL                0
#endif

typedef unsigned char         boolean;

typedef unsigned char         uint8_t;          /*           0 .. 255             */
typedef signed char           sint8_t;          /*        -128 .. +127            */
typedef unsigned short        uint16_t;         /*           0 .. 65535           */
typedef signed short          sint16_t;         /*      -32768 .. +32767          */
typedef unsigned long         uint32_t;         /*           0 .. 4294967295      */
typedef signed long           sint32_t;         /* -2147483648 .. +2147483647     */
typedef unsigned long long    uint64_t;         /*       0..18446744073709551615  */
typedef signed long long      sint64_t;
typedef float                 float32_t;
typedef double                float64_t;

#endif /* PLATFORM_TYPES_H */
