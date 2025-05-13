       IDENTIFICATION DIVISION.
       PROGRAM-ID. 255_1.
       ENVIRONMENT DIVISION. 
       INPUT-OUTPUT SECTION. 
       FILE-CONTROL. SELECT cust-info    ASSIGN TO cust-file
           ORGANIZATION IS LINE SEQUENTIAL.
                     SELECT payroll-record  ASSIGN TO printer.
       DATA DIVISION.
       file section.
       fd  cust-info.
       01  employee-record.
           05  Initial1                 pic X(1).
           05  Initial2                 pic X(1).
           05  last-name                pic X(10).
           05  mo-of-trans              pic X(2).
           05  yr-of-trans              pic X(4).
           05  trans-amt                pic 9(6).
       fd  payroll-record.
       01  print-rec.
           05 pic x(132).
       WORKING-STORAGE SECTION.
       01  are-there-more-records   picture xxx value 'yes'.
       01  PAGE-HDR.
           05 pic x(5).
           05 pic x(4) value "Name".
           05 pic x(5).
           05 pic x(19) value "Date of Transaction".
           05 pic x(3).
           05 pic x(21) value "Amount of Transaction".
       01  Next-Line pic x.
       01  info.
           05  Initial1-out             pic X(1).
           05                           pic x value ".".
           05  Initial2-out             pic X(1).
           05                           pic x value ".".
           05  last-name-out            pic X(10).
           05                           pic x(6).
           05  mo-of-trans-out          pic X(2).
           05                           pic x value "/".
           05  yr-of-trans-out          pic X(4).
           05                           pic x(11).
           05  trans-amt-out            pic $ZZZ,ZZ9.
           
       PROCEDURE DIVISION.
       100-main-module.
           open input cust-info 
                output payroll-record 
           WRITE print-rec FROM PAGE-HDR
           WRITE print-rec FROM Next-Line
           
           perform until are-there-more-records = 'no '
              read cust-info 
                    at end
                       move 'no ' to are-there-more-records 
                    not at end
                       perform 200-move-routine
                       WRITE print-rec FROM info
              end-read
           END-PERFORM
           close cust-info 
                 payroll-record 
           stop run.
       200-move-routine.
           move spaces to print-rec
           move Initial1 to Initial1-out 
           move Initial2 to Initial2-out 
           move last-name to last-name-out 
           move mo-of-trans to mo-of-trans-out 
           move yr-of-trans to yr-of-trans-out 
           move trans-amt to trans-amt-out.
