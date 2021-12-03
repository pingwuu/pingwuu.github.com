---
layout: post
title:  "The 8051 Microcontroller and Embedded System"
date:   2021-08-11 10:30:00 +0800
categories: mcu 8051
comments: true
---



[TOC]

# 0. CHAPTER 0 - INTRODUCTION TO COMPUTING

**OBJECTIVES**

Upon completion of this chapter, you will be able to:

* Convert any number from base 2, base 10 or base 16 to either of the other two bases

* Add and substract hex numbers

* Add binary numbers

* Represent any binary number in 2's complement

* Represent an alphanumeric string in ASCII code

* Describe logical operations AND, OR, NOT, XOR, NAND, NOR

* Use logic gates to diagram simple circuits

* Explain the difference between a bit, a nibble, a byte and a word

* Give precise mathematical definitions of the terms kilobyte, megabyte, gigabyte and terabyte

* Explain the difference between RAM and ROM and describe their use

* Describe the purpose of the major components of a computer system

* List the three types of buses found in computers and describe the purpose of each type of bus

* Describe the role of the CPU in computer system

* List the major components of the CPU and describe the purpose of each

  

​		To understand the software and hardware of a microcontroller-based system, one must first master some very basic concepts underlying computer design. In this chapter(which in the tradition of digital computers can be called Chapter 0), the fundamentals of numbering and coding system are presented. After an introduction to logic gates, an overview of the workings inside the computer is given. Finally, in the last section we give a brief history of CPU architecture. Although some readers may have an adequate background in many of the topics of this chapter, it is recommended that the material be scanned, however briefly.

## SECTION 0.1: NUMBER AND CODING SYSTEMS

​		Whereas human beings use base 10(decimal) arithmetic, computers use the base 2(binary) system. In this section we explain how to convert from the decimal system to the binary system, and vice versa. The convenient representation of binary numbers in base 16, called hexadecimal, also is covered. Finally, the binary format of the alphanumeric code, called ASCII, is explored.

### Decimal and binary number systems

​		Although there has been speculation that the origin of the base 10 system is the fact that human beings have 10 fingers, there is absolutely no speculation about the reason behind the use of the binary system in computers. The binary system is used in computers because 1 and 0 represent the two voltage levels of on and off. Whereas is base 10 distinct symbols 0, 1, 2, ..., 9, in base 2 there are only two 0 and 1, with which to generate numbers. Base 10 contains digits 0 through 9; binary contains digits 0 and 1 only. These two binary digits 0 and 1 are commonly referred to as bits.

### Converting from decimal to binary

​		One method of converting from decimal to binary is to divide the decimal number by 2 repeatedly, keeping track of the remainders. This process continues until the quotient becomes zero. The remainders are then written in reverse order to obtain the binary number. This demonstrated in Examples 0-1.

**Example 0-1**

Convert 25~10~ to binary.

Solution:

```
			Quotient	Remainder	
25/2 =		12			1			LSB(Least significant bit)
12/2 =		6			0
6/2  =		3			0
3/2  =		1			1
1/2  = 		0			1			MSB (Most significant bit)
```

Therefore, 25~10~ = 11001~2~

### Converting from binary to decimal

​		To convert from binary to decimal, it is important to understand the concept of weight associated with each digit position. First, as an analogy, recall the weight of numbers in the base 10 system, as shown in the diagram. By the same token, each digit position in a number in base 2 has a weight associated with it:

| 740683~10~           =                     |
| ------------------------------------------ |
| 3 x 10^0^               =                3 |
| 8 x 10^1^               =              80  |
| 6 x 10^2^               =            600   |
| 0 x 10^3^               =          0000    |
| 4 x 10^4^               =        40000     |
| 7 x 10^5^               =      700000      |
| 740683                                     |

| 110101~2~            =      Decimal        Binary            |
| ------------------------------------------------------------ |
| 1 x 2^0^ = 1 x 1    =       1                                1 |
| 0 x 2^1^ = 0 x 2    =       0                              00 |
| 1 x 2^2^ = 1 x 4    =       4                            100 |
| 0 x 2^3^ = 0 x 8    =       0                          0000  |
| 1 x 2^4^ = 1 x 16    =   16                       10000      |
| 1 x 2^5^ = 1 x 32    =   32                     100000       |
| 110101                                                       |

​		Knowing the weight of each bit in a binary number makes it simple to add them together to get its decimal equivalent, as shown in Example 0-2.

**Example 0-2**

Convert 1101~2~ to decimal.

| Solution:                                                    |
| ------------------------------------------------------------ |
| Weight:            16       8        4        2        1     |
| Digits:               1         1        0        0        1 |
| Sum:                 16+     8+      0+     0+      1 = 25~10~ |

​		Knowing the weight associated with each binary bit position allows one to convert a decimal number to binary directly instead of going through the process of repeated division. This is shown in Example 0-3.

**Example 0-3**

Using the concept of weight to convert 39~10~ to binary.

| Solution:                                                    |
| ------------------------------------------------------------ |
| Weight:            32       16       8        4        2        1 |
| 1          0         0        1        1        1            |
| 32+     0+       0+      4+      2+      1 = 39~10~          |
| Therefore, 39~10~  = 100111~2~                               |

### Hexadecimal system

​		Base 16, or the hexadecimal system as it is called in computer literature, is used as convenient representation of binary numbers. For example, it is much easier for  a human being to represent a string of 0s and 1s such as 100010010110 as its hexadecimal equivalent of 896H. The binary system has 2 digits, 0 and 1. The base 10 system has 10 digits, 0 through 9. The hexadecimal (base 16) system has 16 digits. In base 16, the first 10 digits, 0 to 9, are the same as in decimal, and for the remaining six digits, the letters A, B, C, D, E, and F are used. Table 0-1 show the equivalent binary, decimal, and hexadecimal representations for 0 to 15.

**Table 0-1: Base 16 Number Systems**

**Decimal        Binary        Hex**

```c
 0        0000      0
 1        0001      1
 2        0010      2
 3        0011      3
 4        0100      4
 5        0101      5
 6        0110      6
 7        0111      7
 8        1000      8
 9        1001      9
10        1010      A
11        1011      B
12        1100      C
13        1101      D
14        1110      E
15        1111      F
```







# 1. CHAPTER 1 - THE 8051 MICROCONTROLLERS

# 2. CHAPTER 2 - 8051 ASSEMBLY LANGUAGE PROGRAMMING

# 3. CHAPTER 3 - JUMP, LOOP, AND CALL INSTRUCTIONS

# 4. CHAPTER 4 - I/O PORT PROGRAMMING

# 5. CHAPTER 5 - ADDRESSING MODELS

# 6. CHAPTER 6 - ARITHMETIC, LOGIC INSTRUCTIONS, AND PROGRAMS

# 7. CHAPTER 7 - 8051 PROGRAMMING IN C

# 8. CHAPTER 8 - 8051 HARDWARE CONNECTION AND INTEL HEX FILE

# 9. CHAPTER 9 - 8051 TIMER PROGRAMMING IN ASSEMBLY AND C

# 10. CHAPTER 10 - 8051 SERIAL PORT PROGRAMMING IN ASSEMBLY AND C

# 11. CHAPTER 11 - INTERRUPTS PROGRAMMING IN ASSEMBLY AND C

# 12. CHAPTER 12 - LCD AND KEYBOARD INTERFACING

# 13. CHAPTER 13 - ADC, DAC AND SENSOR INTERFACING

# 14. CHAPTER 14 - 8051 INTERFACING TO EXTERNAL MEMORY

# 15. CHAPTER 15 - 8051 INTERFACING WITH THE 8255

# 16. CHAPTER 16 - DS12887 RTC INTERFACING AND PROGRAMMING

# 17. CHAPTER 17 - MOTOR CONTROL: RELAY, PWM, DC AND STEPPER MOTORS

# APPENDIX A - 8051 INSTRUCTIONS, TIMING AND REGISTERS

# APPENDIX B - BASICS OF WIRE WRAPPING

# APPENDIX C - IC TECHNOLOGY AND SYSTEM DESING  ISSUES

# APPENDIX D - FLOWCHARTS AND PSEUDOCODE

# APPENDIX E - 8051 PRIMER FOR X86 PROGRAMMERS

# APPENDIX F - ASSII CODES

# APPENDIX G - ASSERMBERS, DEVELOPMENT RESOURCES AND SUPPLIERS

# APPENDIX H - DATA SHEETS





# 99. Reference URL

* 
