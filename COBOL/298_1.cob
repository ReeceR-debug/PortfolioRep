       IDENTIFICATION DIVISION.
       PROGRAM-ID. 298_1.
       ENVIRONMENT DIVISION. 
       INPUT-OUTPUT SECTION. 
       FILE-CONTROL. SELECT EMP-INFO    ASSIGN TO IN-EMP-FILE
           ORGANIZATION IS LINE SEQUENTIAL.
                     SELECT label-rec  ASSIGN TO printer.
       DATA DIVISION.
       file section.
       fd  EMP-INFO.
       01  employee-record.
           05 emp-name      pic x(15).
           05 hours         pic 9(3).
           05 rate          pic 9(1)v99.
       fd  label-rec.
       01  print-rec.
           05 emp-name-out      pic x(15).
           05 Gross         pic 9(4)v99.
           05 pic xxx.
           05 FICA          pic 9(3)v99.
           05 pic xxx.
           05 Net          pic 9(4)v99.
       WORKING-STORAGE SECTION.
       01  are-there-more-records   picture xxx value 'yes'.
       PROCEDURE DIVISION.
       100-main-module.
           open input EMP-INFO 
                output label-rec 
           
           perform until are-there-more-records = 'no '
              read EMP-INFO 
                    at end
                       move 'no ' to are-there-more-records 
                    not at end
                       perform 200-move-routine
              end-read
           END-PERFORM
           close EMP-INFO 
                 label-rec 
           stop run.
       200-move-routine.
           move spaces to print-rec.
           move emp-name to emp-name-out 
           compute Gross ROUNDED  = hours * rate
           compute FICA ROUNDED = Gross * .0765
           compute Net ROUNDED  = Gross - FICA


           write print-rec.
