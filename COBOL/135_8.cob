       IDENTIFICATION DIVISION.
       PROGRAM-ID. 132_2.
       ENVIRONMENT DIVISION. 
       INPUT-OUTPUT SECTION. 
       FILE-CONTROL. SELECT student-info    ASSIGN TO stud-info
           ORGANIZATION IS LINE SEQUENTIAL.
                     SELECT stud-record  ASSIGN TO printer.
       DATA DIVISION.
       file section.
       fd  student-info.
       01  information.
           05  student-name     pic X(20).
           05  num-credits      PIC 99.

       fd  stud-record.
       01  print-rec.
           05  student-name-out     pic X(20).
           05                       pic x(20).
           05  num-credits-out      PIC 99.
           05                       pic x(20).
           05  tuition-out          pic 9(4).
       WORKING-STORAGE SECTION.
       01  are-there-more-records   picture xxx value 'yes'.
       PROCEDURE DIVISION.
       100-main-module.
           open input student-info 
                output stud-record 
           perform until are-there-more-records = 'no '
              read student-info 
                    at end
                       move 'no ' to are-there-more-records 
                    not at end
                       perform 200-move-routine
              end-read
           END-PERFORM
           close student-info 
                 stud-record 
           stop run.
       200-move-routine.
           move spaces to print-rec
           move student-name to student-name-out
           move num-credits to num-credits-out
           IF num-credits > 12 then
           compute tuition-out = 6300
           ELSE 
           MULTIPLY num-credits by 525 giving tuition-out
           END-IF 
           write print-rec.
