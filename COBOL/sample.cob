       IDENTIFICATION DIVISION.
       PROGRAM-ID. sample.
       ENVIRONMENT DIVISION. 
       INPUT-OUTPUT SECTION. 
       FILE-CONTROL. SELECT employee-data    ASSIGN TO emp-dat.
                     SELECT payroll-listing  ASSIGN TO printer.
       DATA DIVISION.
       file section.
       fd  employee-data.
       01  employee-record.
           05  employee-name-in     picture X(20).
           05  hours-worked-in      picture 9(2).
           05  hourly-rate-in       picture 9v99.
       fd  payroll-listing.
       01  print-rec.
           05  name-out             picture X(20).
           05                       picture X(10).
           05  hours-out            picture 9(2).
           05                       picture X(8).
           05  rate-out             picture 9.99.
           05                       picture X(6).
           05  weekly-wages-out     picture 999.99.
       WORKING-STORAGE SECTION.
       01  are-there-more-records   picture xxx value 'yes'.
       PROCEDURE DIVISION.
       100-main-module.
           open input employee-data 
                output payroll-listing 
           perform until are-there-more-records = 'no '
              read employee-data 
                    at end
                       move 'no ' to are-there-more-records 
                    not at end
                       perform 200-wage-routine
              end-read
           END-PERFORM
           close employee-data 
                 payroll-listing 
           stop run.
       200-wage-routine.
           move spaces to print-rec
           move employee-name-in to name-out 
           move hours-worked-in to hours-out 
           move hourly-rate-in to rate-out 
           MULTIPLY hours-worked-in by hourly-rate-in 
                    giving weekly-wages-out
           write print-rec.
