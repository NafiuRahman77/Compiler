.MODEL SMALL

.STACK 400H

.DATA


.CODE
	FLAG DB 0
	NL DB 13,10,"$"
	NUMBER_STRING DB "00000$" 

f PROC
	PUSH BP
	MOV BP, SP
PUSH AX ; k decl
MOV AX, -2[BP]
PUSH AX ; k called
PUSH 5
POP AX ; r-val of assignop 5
MOV -2[BP], AX ; assigning 5 to k
POP AX
label_while_start_1: ; while loop begin
MOV AX, -2[BP]
PUSH AX ; k called
PUSH 0
POP AX
POP BX ; left side value
CMP BX, AX ; evaluating (k)>0
JNG label_1
PUSH 1 ; if (k)>0 is true
JMP label_0
label_1:
PUSH 0 ; if (k)>0 is false
label_0:
POP CX
CMP CX, 0
JE label_while_end_1
MOV AX, 4[BP]
PUSH AX ; a called
INC AX
MOV 4[BP], AX
POP AX
MOV AX, -2[BP]
PUSH AX ; k called
DEC AX
MOV -2[BP], AX
POP AX
JMP label_while_start_1 ; back to top of loop
label_while_end_1:
PUSH 3
MOV AX, 4[BP]
PUSH AX ; a called
POP BX
POP AX
IMUL BX
PUSH AX ; result of 3*(a) is in AX, pushed
PUSH 7
POP AX
POP BX
SUB BX, AX
PUSH BX ; 3*(a)-7 pushed
POP AX
	JMP f_EXIT
MOV AX, 4[BP]
PUSH AX ; a called
PUSH 9
POP AX ; r-val of assignop 9
MOV 4[BP], AX ; assigning 9 to a
POP AX
f_EXIT:
	MOV SP, BP ; Restoring SP
	POP BP
	RET 2
f ENDP

g PROC
	PUSH BP
	MOV BP, SP
PUSH AX ; x decl
PUSH AX ; i decl
MOV AX, -2[BP]
PUSH AX ; x called
MOV AX, 6[BP]
PUSH AX ; a called
CALL f
PUSH AX ; return value of f
MOV AX, 6[BP]
PUSH AX ; a called
POP AX
POP BX
ADD AX, BX
PUSH AX ; f((a))+(a) pushed
MOV AX, 4[BP]
PUSH AX ; b called
POP AX
POP BX
ADD AX, BX
PUSH AX ; f((a))+(a)+(b) pushed
POP AX ; r-val of assignop f((a))+(a)+(b)
MOV -2[BP], AX ; assigning f((a))+(a)+(b) to x
POP AX
MOV AX, -4[BP]
PUSH AX ; i called
PUSH 0
POP AX ; r-val of assignop 0
MOV -4[BP], AX ; assigning 0 to i
POP AX
label_for_start_1: ; for loop starting label
MOV AX, -4[BP]
PUSH AX ; i called
PUSH 7
POP AX
POP BX ; left side value
CMP BX, AX ; evaluating (i)<7
JNL label_3
PUSH 1 ; if (i)<7 is true
JMP label_2
label_3:
PUSH 0 ; if (i)<7 is false
label_2:
POP AX
CMP AX, 0
JE label_for_end_1 ; loop ending condn
JMP label_for_stmt_1 ; loop code label
label_for_ite_1: ; loop iterator inc/dec
MOV AX, -4[BP]
PUSH AX ; i called
INC AX
MOV -4[BP], AX
JMP label_for_start_1 ; restart loop
label_for_stmt_1: ; loop code
MOV AX, -4[BP]
PUSH AX ; i called
PUSH 3
MOV DX, 0 ; DX:AX = 0000:AX
POP BX
POP AX
IDIV BX
PUSH DX ; remainder of (i)%3 is in DX
PUSH 0
POP AX
POP BX ; left side value
CMP BX, AX ; evaluating (i)%3==0
JNE label_5
PUSH 1 ; if (i)%3==0 is true
JMP label_4
label_5:
PUSH 0 ; if (i)%3==0 is false
label_4:
POP AX ; expr in AX
CMP AX, 0 ; checking expr
JE label_else_1
MOV AX, -2[BP]
PUSH AX ; x called
MOV AX, -2[BP]
PUSH AX ; x called
PUSH 5
POP AX
POP BX
ADD AX, BX
PUSH AX ; (x)+5 pushed
POP AX ; r-val of assignop (x)+5
MOV -2[BP], AX ; assigning (x)+5 to x
POP AX
JMP label_endif_1
label_else_1: ; else label
MOV AX, -2[BP]
PUSH AX ; x called
MOV AX, -2[BP]
PUSH AX ; x called
PUSH 1
POP AX
POP BX
SUB BX, AX
PUSH BX ; (x)-1 pushed
POP AX ; r-val of assignop (x)-1
MOV -2[BP], AX ; assigning (x)-1 to x
POP AX
label_endif_1: ; end if label
JMP label_for_ite_1 ; update iterator after stmt
label_for_end_1: ; end of for loop
MOV AX, -2[BP]
PUSH AX ; x called
POP AX
	JMP g_EXIT
g_EXIT:
	MOV SP, BP ; Restoring SP
	POP BP
	RET 4
g ENDP

main PROC
	MOV AX, @DATA
	MOV DS, AX
PUSH BP
MOV BP, SP
PUSH AX ; a decl
PUSH AX ; b decl
PUSH AX ; i decl
MOV AX, -2[BP]
PUSH AX ; a called
PUSH 1
POP AX ; r-val of assignop 1
MOV -2[BP], AX ; assigning 1 to a
POP AX
MOV AX, -4[BP]
PUSH AX ; b called
PUSH 2
POP AX ; r-val of assignop 2
MOV -4[BP], AX ; assigning 2 to b
POP AX
MOV AX, -2[BP]
PUSH AX ; a called
MOV AX, -2[BP]
PUSH AX ; a called
MOV AX, -4[BP]
PUSH AX ; b called
CALL g
PUSH AX ; return value of g
POP AX ; r-val of assignop g((a),(b))
MOV -2[BP], AX ; assigning g((a),(b)) to a
POP AX
MOV AX, -2[BP]
CALL PRINT ; argument a in AX
MOV AX, -6[BP]
PUSH AX ; i called
PUSH 0
POP AX ; r-val of assignop 0
MOV -6[BP], AX ; assigning 0 to i
POP AX
label_for_start_2: ; for loop starting label
MOV AX, -6[BP]
PUSH AX ; i called
PUSH 4
POP AX
POP BX ; left side value
CMP BX, AX ; evaluating (i)<4
JNL label_7
PUSH 1 ; if (i)<4 is true
JMP label_6
label_7:
PUSH 0 ; if (i)<4 is false
label_6:
POP AX
CMP AX, 0
JE label_for_end_2 ; loop ending condn
JMP label_for_stmt_2 ; loop code label
label_for_ite_2: ; loop iterator inc/dec
MOV AX, -6[BP]
PUSH AX ; i called
INC AX
MOV -6[BP], AX
JMP label_for_start_2 ; restart loop
label_for_stmt_2: ; loop code
MOV AX, -2[BP]
PUSH AX ; a called
PUSH 3
POP AX ; r-val of assignop 3
MOV -2[BP], AX ; assigning 3 to a
POP AX
label_while_start_2: ; while loop begin
MOV AX, -2[BP]
PUSH AX ; a called
PUSH 0
POP AX
POP BX ; left side value
CMP BX, AX ; evaluating (a)>0
JNG label_9
PUSH 1 ; if (a)>0 is true
JMP label_8
label_9:
PUSH 0 ; if (a)>0 is false
label_8:
POP CX
CMP CX, 0
JE label_while_end_2
MOV AX, -4[BP]
PUSH AX ; b called
INC AX
MOV -4[BP], AX
POP AX
MOV AX, -2[BP]
PUSH AX ; a called
DEC AX
MOV -2[BP], AX
POP AX
JMP label_while_start_2 ; back to top of loop
label_while_end_2:
JMP label_for_ite_2 ; update iterator after stmt
label_for_end_2: ; end of for loop
MOV AX, -2[BP]
CALL PRINT ; argument a in AX
MOV AX, -4[BP]
CALL PRINT ; argument b in AX
MOV AX, -6[BP]
CALL PRINT ; argument i in AX
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
MOV DX, OFFSET NL ; NEWLINE
MOV AH, 9
INT 21H
RET
PRINT ENDP
END MAIN
