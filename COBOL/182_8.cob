       IDENTIFICATION DIVISION.
       PROGRAM-ID. 182_8.
       ENVIRONMENT DIVISION. 
       INPUT-OUTPUT SECTION. 
       FILE-CONTROL.
                     SELECT print-rec  ASSIGN TO printer.
       DATA DIVISION.
       file section.
       fd  print-rec.
       01  printer.
           05  part-no-out     PIC x(5).
           05                  pic xxx.
           05  part-desc-out   PIC x(15).
           05                  pic xxx.
           05  qty-on-hand-out PIC 9(5).
           05                  pic xxx.
           05  unit-price-out PIC 9(5)V99.

       WORKING-STORAGE SECTION. 
       01  part-no     PIC x(5).
       01  part-desc   PIC x(15).
       01  qty-on-hand PIC 9(5).
       01  unit-price  PIC 9(5)V99.
       01  MORE-DATA PIC XXX VALUE "YES".
       
       PROCEDURE DIVISION.
       100-MAIN.
           open output print-rec 
           PERFORM UNTIL MORE-DATA = "NO "
              DISPLAY "ENTER PART NUMBER: "
              ACCEPT part-no 
              DISPLAY "ENTER PART DESCRIPTION: "
              ACCEPT part-desc 
              DISPLAY "ENTER QUANTITY ON HAND "
              ACCEPT qty-on-hand 
              DISPLAY "ENTER UNIT PRICE: "
              ACCEPT unit-price 
              DISPLAY "IS THERE MORE DATA (YES/NO)?"
              ACCEPT MORE-DATA 
              perform 200-move-routine
           END-PERFORM
           close print-rec 
           STOP RUN.
       200-move-routine.
           move spaces to printer
           move part-no to part-no-out
           move part-desc to part-desc-out
           move qty-on-hand to qty-on-hand-out
           MOVE unit-price to unit-price-out
           write printer.
