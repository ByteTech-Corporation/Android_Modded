.org 0xAA55
.org 0xF00C
.org 0xCFF5
.org 0x1600

; packet (bootloader data packet)

.word 0x0040
.word 0x10
.word 0x14
.word 0x20
.word 0x25

; notes for packet

.word 0xFF6A
.word 0xC000
.word 0xDF
.word 0x33

int packet[0x000001F]

.word 0x000000000C
.word 0xDFFFFF8
.word 0xC98FF01
.word 0x1A000E9
.word 0x0
.word 0xC
.word 0x00
.word 0xF8

; integer data

int int_0[0x00000FF9]          ldi $C0
int int_1[0xCCC172AF]          lda $F8
int int_2[0xCFFFFF1E]          ; data packet integer 0

; interrupts

ldi $FF                int INTERRUPT_0[0x00000F, 0x500000E]  ; 00E7
ldi $A4                int INTERRUPT_1[0xC00017, 0xFFFF501]  ; 000A
ldi $C7                int INTERRUPT_2[0x00000E, 0x000002F]  ; 005F
ldi $E5                int INTERRUPT_3[0x000C6F, 0x000007E]  ; 00C2
ldi $E4                int INTERRUPT_4[0xA23FF5, 0x1244E25]  ; 01FF

locations:

dw 0xFFFF
dw .word 0xCCC7

ldi $CF17
ldi $AA55
ldi $000F
ldi $9999
ldi $FFFF
ldi $0000

int dw EOF[0x00000C88]:
EOF = int EOF[0xC77771E1354EE]
