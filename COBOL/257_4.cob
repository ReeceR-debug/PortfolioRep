       IDENTIFICATION DIVISION.
       PROGRAM-ID. 257_4.
       ENVIRONMENT DIVISION. 
       INPUT-OUTPUT SECTION. 
       FILE-CONTROL. SELECT cust-info    ASSIGN TO cust-file
           ORGANIZATION IS LINE SEQUENTIAL.
                     SELECT label-rec  ASSIGN TO printer.
       DATA DIVISION.
       file section.
       fd  cust-info.
       01  employee-record.
           05  custName                      pic X(20).
           05  StreetAdd                     pic X(20).
           05  city-state-zip                pic X(20).
           05  num-of-lables                 pic X(2).
       fd  label-rec.
       01  print-rec.
           05 pic x(132).
       WORKING-STORAGE SECTION.
       01  MyCounter PIC 9 VALUE 1.
       01  are-there-more-records   picture xxx value 'yes'.
       01  Next-Line           pic x.
       01  custName-out        pic x(20).
       01  StreetAdd-out       pic x(20).
       01  city-state-zip-out pic x(20).
       PROCEDURE DIVISION.
       100-main-module.
           open input cust-info 
                output label-rec 
           
           perform until are-there-more-records = 'no '
              read cust-info 
                    at end
                       move 'no ' to are-there-more-records 
                    not at end
                       perform 200-move-routine
                       PERFORM UNTIL MyCounter > num-of-lables 
                       WRITE print-rec FROM custName-out
                       WRITE print-rec FROM StreetAdd-out
                       WRITE print-rec FROM city-state-zip-out
                       WRITE print-rec FROM Next-Line
                       COMPUTE MyCounter = MyCounter + 1
                       END-PERFORM
                       COMPUTE MyCounter = 1
              end-read
           END-PERFORM
           close cust-info 
                 label-rec 
           stop run.
       200-move-routine.
           move spaces to print-rec
           move custName to custName-out 
           move StreetAdd to StreetAdd-out 
           move city-state-zip to city-state-zip-out.
