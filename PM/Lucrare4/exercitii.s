dosseg //asamblorul organizeaza segmenteke
.model small //se selecteaza modelul de memorie
.stack 100h
.data 
    file_in db 'input_txt',0
    file_out db 'output_txt',0
    handle_in dw?
    handle_out dw?
    buffer db 100 dub(?)
.code 
main proc
    ;//Deschidere fisier
    MOV AX,@data// muta in AX valoarea segmentului de date
    MOV DS,AX
    MOV AL,0
    LEA DX,file_in
    INT 21h
    JC eroare
    MOV handle_in, AX
    ;//Creare fisier
    MOV AH,3Ch
    MOV CX,0
    LEA DX,file_out
    INT 21h
    JC eroare
    MOV handle_out,AX

    ;//Citire max 100 bytes in buffer
    MOV AH,3Fh ;//read from file
    MOV BX,handle_in
    MOV CX,100 ;//nr max de bytes dorit
    MOV DX,offset buffer ;//offsetul bufferului 
    INT 21h
    JC read_error
    MOV bytes_read, AX