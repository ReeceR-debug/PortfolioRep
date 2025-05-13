       IDENTIFICATION DIVISION.
       PROGRAM-ID. 299_5.
       ENVIRONMENT DIVISION. 
       INPUT-OUTPUT SECTION. 
       FILE-CONTROL. SELECT Taxi-INFO    ASSIGN TO Taxi-in
           ORGANIZATION IS LINE SEQUENTIAL.
                     SELECT label-rec  ASSIGN TO printer.
       DATA DIVISION.
       file section.
       fd  Taxi-INFO.
       01  employee-record.
           05 VIN      pic X(10).
           05 desc     pic x(10).
           05 miles    pic 9(4).
           05 gal      pic 99v99.
       fd  label-rec.
       01  print-rec.
           05 VIN-out pic x(10).
           05 pic x(3).
           05 MPG-out pic 99v99.
       WORKING-STORAGE SECTION.
       01  are-there-more-records   picture xxx value 'yes'.
       01  running-gal pic 9(10)v99 value 0.
       01  running-miles pic 9(10) value 0.
       01  tot-MPG-out pic 99v99 value 0.
       PROCEDURE DIVISION.
       100-main-module.
           open input Taxi-INFO 
                output label-rec 
           
           perform until are-there-more-records = 'no '
              read Taxi-INFO 
                    at end
                       move 'no ' to are-there-more-records 
                    not at end
                       perform 200-move-routine
              end-read
           END-PERFORM
           compute tot-MPG-out = running-miles / running-gal 
           write print-rec from tot-MPG-out 
           close Taxi-INFO 
                 label-rec 
           stop run.
       200-move-routine.
           move spaces to print-rec.
           move VIN to VIN-out 
           compute MPG-out = miles / gal
           compute running-gal = running-gal + gal
           compute running-miles = running-miles + miles

           write print-rec.
