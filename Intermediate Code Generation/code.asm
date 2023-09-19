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
PUSH 2
POP AX ; r-val of assignop 2
MOV 0[BP], AX ; assigning 2 to i
POP AX
MOV AX, 0[BP]
CALL PRINT ; argument i in AX
MOV AX, 0[BP]
PUSH AX ; j called
PUSH 5
PUSH 8
POP AX
POP BX
ADD AX, BX
PUSH AX ; 5+8 pushed
POP AX ; r-val of assignop 5+8
MOV 0[BP], AX ; assigning 5+8 to j
POP AX
MOV AX, 0[BP]
CALL PRINT ; argument j in AX
MOV AX, -2[BP]
PUSH AX ; k called
MOV AX, 0[BP]
PUSH AX ; i called
MOV AX, 0[BP]
PUSH AX ; j called
PUSH 2
POP BX
POP AX
IMUL BX
PUSH AX ; result of (j)*2 is in AX, pushed
POP AX
POP BX
ADD AX, BX
PUSH AX ; (i)+(j)*2 pushed
POP AX ; r-val of assignop (i)+(j)*2
MOV -2[BP], AX ; assigning (i)+(j)*2 to k
POP AX
MOV AX, -2[BP]
CALL PRINT ; argument k in AX
MOV AX, -6[BP]
PUSH AX ; m called
MOV AX, -2[BP]
PUSH AX ; k called
PUSH 9
MOV DX, 0 ; DX:AX = 0000:AX
POP BX
POP AX
IDIV BX
PUSH DX ; remainder of (k)%9 is in DX
POP AX ; r-val of assignop (k)%9
MOV -6[BP], AX ; assigning (k)%9 to m
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
POP BX ; left side value
CMP BX, AX ; evaluating (m)<=(ll)
JNLE label_1
PUSH 1 ; if (m)<=(ll) is true
JMP label_0
label_1:
PUSH 0 ; if (m)<=(ll) is false
label_0:
POP AX ; r-val of assignop (m)<=(ll)
MOV -8[BP], AX ; assigning (m)<=(ll) to n
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
POP BX ; left side value
CMP BX, AX ; evaluating (i)!=(j)
JE label_3
PUSH 1 ; if (i)!=(j) is true
JMP label_2
label_3:
PUSH 0 ; if (i)!=(j) is false
label_2:
POP AX ; r-val of assignop (i)!=(j)
MOV -10[BP], AX ; assigning (i)!=(j) to o
POP AX
MOV AX, -10[BP]
CALL PRINT ; argument o in AX
MOV AX, -12[BP]
PUSH AX ; p called
MOV AX, -8[BP]
PUSH AX ; n called
MOV AX, -10[BP]
PUSH AX ; o called
POP BX
POP AX ; left side value
CMP AX, 0
JNE label_5
CMP BX, 0
JNE label_5
PUSH 0
JMP label_4
label_5:
PUSH 1 ; total false
label_4:
POP AX ; r-val of assignop (n)||(o)
MOV -12[BP], AX ; assigning (n)||(o) to p
POP AX
MOV AX, -12[BP]
CALL PRINT ; argument p in AX
MOV AX, -12[BP]
PUSH AX ; p called
MOV AX, -8[BP]
PUSH AX ; n called
MOV AX, -10[BP]
PUSH AX ; o called
POP BX
POP AX ; left side value
CMP AX, 0
JE label_7
CMP BX, 0
JE label_7
PUSH 1
JMP label_6
label_7:
PUSH 0 ; total false
label_6:
POP AX ; r-val of assignop (n)&&(o)
MOV -12[BP], AX ; assigning (n)&&(o) to p
POP AX
MOV AX, -12[BP]
CALL PRINT ; argument p in AX
MOV AX, -12[BP]
PUSH AX ; p called
INC AX
MOV -12[BP], AX
POP AX
MOV AX, -12[BP]
CALL PRINT ; argument p in AX
MOV AX, -2[BP]
PUSH AX ; k called
MOV AX, -12[BP]
PUSH AX ; p called
POP AX
NEG AX ; -ÐG‚Nÿ
PUSH AX
POP AX ; r-val of assignop -(p)
MOV -2[BP], AX ; assigning -(p) to k
POP AX
MOV AX, -2[BP]
CALL PRINT ; argument k in AX
PUSH 0
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
