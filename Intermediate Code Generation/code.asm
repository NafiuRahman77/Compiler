.MODEL SMALL

.STACK 400H

.DATA


.CODE
	FLAG DB 0
	NL DB 13,10,"$"
	NUMBER_STRING DB "00000$" 
i DW ? ; i decl
j DW ? ; j decl

main PROC
	MOV AX, @DATA
	MOV DS, AX
PUSH BP
MOV BP, SP
PUSH AX ; k decl
PUSH AX ; ll decl
PUSH AX ; m decl
PUSH AX ; n decl
PUSH AX ; o decl
PUSH AX ; p decl
MOV AX, 0[BP]
PUSH AX ; i called
POP AX
MOV AX, 0[BP]
CALL PRINT ; argument i in AX
MOV AX, 0[BP]
PUSH AX ; j called
POP AX
MOV AX, 0[BP]
CALL PRINT ; argument j in AX
MOV AX, -2[BP]
PUSH AX ; k called
MOV AX, 0[BP]
PUSH AX ; i called
MOV AX, 0[BP]
PUSH AX ; j called
POP AX
MOV AX, -2[BP]
CALL PRINT ; argument k in AX
MOV AX, -6[BP]
PUSH AX ; m called
MOV AX, -2[BP]
PUSH AX ; k called
POP AX
MOV AX, -6[BP]
CALL PRINT ; argument m in AX
MOV AX, -8[BP]
PUSH AX ; n called
MOV AX, -6[BP]
PUSH AX ; m called
MOV AX, -4[BP]
PUSH AX ; ll called
POP AX
MOV AX, -8[BP]
CALL PRINT ; argument n in AX
MOV AX, -10[BP]
PUSH AX ; o called
MOV AX, 0[BP]
PUSH AX ; i called
MOV AX, 0[BP]
PUSH AX ; j called
POP AX
MOV AX, -10[BP]
CALL PRINT ; argument o in AX
MOV AX, -12[BP]
PUSH AX ; p called
MOV AX, -8[BP]
PUSH AX ; n called
MOV AX, -10[BP]
PUSH AX ; o called
POP AX
MOV AX, -12[BP]
CALL PRINT ; argument p in AX
MOV AX, -12[BP]
PUSH AX ; p called
MOV AX, -8[BP]
PUSH AX ; n called
MOV AX, -10[BP]
PUSH AX ; o called
POP AX
MOV AX, -12[BP]
CALL PRINT ; argument p in AX
MOV AX, -12[BP]
PUSH AX ; p called
POP AX
MOV AX, -12[BP]
CALL PRINT ; argument p in AX
MOV AX, -2[BP]
PUSH AX ; k called
MOV AX, -12[BP]
PUSH AX ; p called
POP AX
MOV AX, -2[BP]
CALL PRINT ; argument k in AX
main_EXIT:
	MOV SP, BP ; Restoring SP
	POP BP
	MOV AH, 4CH
	INT 21H
main ENDP

PRINT PROC ; PRINTS A WORD INTEGER IN AX
LEA SI, NUMBER_STRING ; IS 00000
ADD SI, 5 ; START FROM ONE'S DIGIT
CMP AX, 0
JNL PRINT_LOOP
MOV FLAG, 1
NEG AX
PRINT_LOOP:
DEC SI
MOV DX, 0 ; DX:AX = 0000:AX
MOV CX, 10
DIV CX
ADD DL, '0'
MOV [SI], DL
CMP AX, 0
JNE PRINT_LOOP
CMP FLAG, 0
JNG NOT_NEGATIVE
MOV AH, 2
MOV DL, 45
INT 21H
MOV FLAG, 0
NOT_NEGATIVE:
MOV DX, SI
MOV AH, 9
INT 21H
MOV DX, OFFSET NL ; NEWLINE
MOV AH, 9
INT 21H
RET
PRINT ENDP
END MAIN
