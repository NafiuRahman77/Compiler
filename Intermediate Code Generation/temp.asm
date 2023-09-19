.MODEL SMALL

.STACK 400H

.DATA


.CODE
	FLAG DB 0
	NL DB 13,10,"$"
	NUMBER_STRING DB "00000$" 

foo PROC
	PUSH BP
	MOV BP, SP
MOV AX, 6[BP]
PUSH AX ; a called
MOV AX, 4[BP]
PUSH AX ; b called
POP AX
POP BX
ADD AX, BX
PUSH AX ; a+b pushed
PUSH 5
POP AX
POP BX ; left side value
CMP BX, AX ; evaluating a+b<=5
JNLE label_1
PUSH 1 ; if a+b<=5 is true
JMP label_0
label_1:
PUSH 0 ; if a+b<=5 is false
label_0:
POP AX ; expr in AX
CMP AX, 0 ; checking expr
JE label_else_1
PUSH 7
POP AX
	JMP foo_EXIT
label_else_1: ; end if label
MOV AX, 6[BP]
PUSH AX ; a called
PUSH 2
POP AX
POP BX
SUB BX, AX
PUSH BX ; a-2 pushed
MOV AX, 4[BP]
PUSH AX ; b called
PUSH 1
POP AX
POP BX
SUB BX, AX
PUSH BX ; b-1 pushed
CALL foo
PUSH AX ; return value of foo
PUSH 2
MOV AX, 6[BP]
PUSH AX ; a called
PUSH 1
POP AX
POP BX
SUB BX, AX
PUSH BX ; a-1 pushed
MOV AX, 4[BP]
PUSH AX ; b called
PUSH 2
POP AX
POP BX
SUB BX, AX
PUSH BX ; b-2 pushed
CALL foo
PUSH AX ; return value of foo
POP BX
POP AX
IMUL BX
PUSH AX ; result of 2*foo(a-1,b-2) is in AX, pushed
POP AX
POP BX
ADD AX, BX
PUSH AX ; foo(a-2,b-1)+2*foo(a-1,b-2) pushed
POP AX
	JMP foo_EXIT
foo_EXIT:
	MOV SP, BP ; Restoring SP
	POP BP
	RET 4
foo ENDP

main PROC
	MOV AX, @DATA
	MOV DS, AX
PUSH BP
MOV BP, SP
PUSH AX ; i decl
PUSH AX ; j decl
PUSH AX ; k decl
MOV AX, -2[BP]
PUSH AX ; i called
PUSH 7
POP AX ; r-val of assignop 7
MOV -2[BP], AX ; assigning 7 to i
POP AX
MOV AX, -4[BP]
PUSH AX ; j called
PUSH 3
POP AX ; r-val of assignop 3
MOV -4[BP], AX ; assigning 3 to j
POP AX
MOV AX, -6[BP]
PUSH AX ; k called
MOV AX, -2[BP]
PUSH AX ; i called
MOV AX, -4[BP]
PUSH AX ; j called
CALL foo
PUSH AX ; return value of foo
POP AX ; r-val of assignop foo(i,j)
MOV -6[BP], AX ; assigning foo(i,j) to k
POP AX
MOV AX, -6[BP]
CALL PRINT ; argument k in AX
PUSH 0
POP AX
	JMP main_EXIT
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
	MOV DX, OFFSET NL   ; NEWLINE
    MOV AH, 9
    INT 21H
    RET
PRINT ENDP
END MAIN
