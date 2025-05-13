       IDENTIFICATION DIVISION.
       PROGRAM-ID. Evn_Id.
       ENVIRONMENT DIVISION. 
       INPUT-OUTPUT SECTION. 
       FILE-CONTROL. SELECT TRANS-FILE    ASSIGN TO TRANS.
                     SELECT SALES-FILE  ASSIGN TO printer.
      *>SELECTING FILES
       DATA DIVISION.
       file section.
       fd  TRANS-FILE.
       01  TRANS-REC.
           05  NAME-IN              picture X(20).
           05  UNIT-PRICE-IN        picture 9(3)V99.
           05  QTY-SOLD-IN          picture 9(3).
      *>SHOWS HOW THINGS ARE INPUTED
       fd  SALES-FILE.
       01  SALES-REC.
           05  NAME-OUT             picture X(20).
           05                       picture X(5).
           05  TOTAL-PRICE-OUT      picture 999.99.
      *>SHOWING HOW THINGS ARE OUTPUTED
       WORKING-STORAGE SECTION.
       01  ARE-THERE-MORE-RECORDS   picture xxx value 'yes'.
      *>VALUE FOR HOW TO STOP THE PROGRAM
       PROCEDURE DIVISION.
       100-MAIN-MODULE.
      *>MAIN MODULE
           open input TRANS-FILE 
                output SALES-FILE 
      *>OPENING INPUT AND OUTPUT FILE
           perform until ARE-THERE-MORE-RECORDS = 'no '
      *>LOOP
              read TRANS-FILE 
                    at end
                       move 'no ' to ARE-THERE-MORE-RECORDS 
      *>MOVING NO TO THE VARIABLE TO STOP THE PROGRAM
                    not at end
                       perform 200-CALC-RTN
      *>IF THERE IS MORE THEN IT WILL LOOP BACK AND KEEP PERFORMING
              end-read
           END-PERFORM
           close TRANS-FILE 
                 SALES-FILE 
      *>CLOSING FILES
           stop run.
       200-CALC-RTN.
      *>THIS IS THE FUNCTION THAT THE MAIN MODULE IS USING
           move spaces to SALES-REC
           move NAME-IN to NAME-OUT 
           MULTIPLY UNIT-PRICE-IN by QTY-SOLD-IN
                    giving TOTAL-PRICE-OUT 
           write SALES-REC.
