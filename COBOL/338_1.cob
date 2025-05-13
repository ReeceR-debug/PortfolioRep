       IDENTIFICATION DIVISION.
       PROGRAM-ID. 338_1.
       ENVIRONMENT DIVISION. 
       INPUT-OUTPUT SECTION. 
       FILE-CONTROL. SELECT rental-info    ASSIGN TO rental-in
           ORGANIZATION IS LINE SEQUENTIAL.
                     SELECT label-rec  ASSIGN TO printer.
       DATA DIVISION.
       file section.
       fd  rental-info.
       01  employee-record.
           05 last-name      pic X(20).
           05 first-In       pic x(1).
           05 type-of-car    pic x(1).
           05 miles-driven   pic 9(5).
           05 days-rented    pic 9(3).
       fd  label-rec.
       01  print-rec.
           05 first-In-out pic x(1).
           05 pic x(3).
           05 last-name-out pic x(20).
           05 pic x(3).
           05 cost-out pic 9(8)v9(2).

       WORKING-STORAGE SECTION.
       01  are-there-more-records   picture xxx value 'yes'.
       01  car-name pic x(10).
       01  daily-price pic 9(2).
       01  per-mile pic 9(1)v9(2).
       01  one pic x(1) value '1'.
       01  two pic x(1) value '2'.
       01  three pic x(1) value '3'.
       PROCEDURE DIVISION.
       100-main-module.
           open input rental-info 
                output label-rec 
           
           perform until are-there-more-records = 'no '
              read rental-info 
                    at end
                       move 'no ' to are-there-more-records 
                    not at end
                       perform 200-move-routine
              end-read
           END-PERFORM
           close rental-info 
                 label-rec 
           stop run.
       200-move-routine.
           move spaces to print-rec.

           IF type-of-car equal TO one 
           move "Toyota" to car-name
           move 26 to daily-price 
           move 0.18 to per-mile 
           end-if

           IF type-of-car equal TO two 
           move "Chevrolet" to car-name
           move 32 to daily-price 
           move 0.22 to per-mile 
           end-if

           IF type-of-car equal TO three 
           move "Cadillac" to car-name
           move 43 to daily-price 
           move 0.28 to per-mile 
           end-if

           move first-In   to first-In-out   
           move last-name  to last-name-out  
           compute cost-out = (daily-price * days-rented)
           +(per-mile * miles-driven)


           write print-rec.
