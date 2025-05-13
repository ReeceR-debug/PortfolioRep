       IDENTIFICATION DIVISION.
       PROGRAM-ID. 338_1.
       ENVIRONMENT DIVISION. 
       INPUT-OUTPUT SECTION. 
       FILE-CONTROL. SELECT payroll-in    ASSIGN TO payroll
           ORGANIZATION IS LINE SEQUENTIAL.
                     SELECT label-rec  ASSIGN TO printer.
       DATA DIVISION.
       file section.
       fd  payroll-in.
       01  employee-record.
           05 emp-no         pic X(5).
           05 emp-name       pic x(20).
           05 terr-no        pic x(2).
           05 office-no      pic x(2).
           05 ann-sal        pic 9(6).
           05                pic x(29).
           05 day-month-hired pic 9(4).
           05 year-hired     pic 9(4).
           05                pic x(10).
       fd  label-rec.
       01  print-rec.
           05 pic x(6).
           05 emp-name-out   pic x(20).
           05 pic x(4).
           05 bonus-out PIC $ZZ,ZZZ.
           05 pic x(45).

       WORKING-STORAGE SECTION.
       01  are-there-more-records   picture xxx value 'yes'.
       01  CURRENT-DATE-FIELDS.
           05  CURRENT-DATE.
              10  CURRENT-YEAR    PIC  9(4).
              10  CURRENT-MONTH   PIC  9(2).
              10  CURRENT-DAY     PIC  9(2).
       01   BREAK PIC X(1) VALUE ' '.
       01  bonus-amt-10k pic 9(6) value 10000.
       01  if-nothing.
           05 pic x(6).
           05  nameZ pic x(20).
           05 pic x(9).
           05  bonus-amt-NOTHING pic x(7) value "$0".
           05 pic x(45).
       01  PAGE-HDR-1.
           05 pic x(40).
           05 pic x(13) value "BONUS REPORT".
           05 pic x(7).
           05 pic x(7) value "PAGE 01".
           05 pic x(3).
           05 FORMATTED-DATE         PIC X(10).
       01  PAGE-HDR-2.
           05 pic x(10).
           05 pic x(9) value "TERRITORY".
           05 pic x(1).
           05 val-2 pic x(2) value "--".
           05 pic x(1).
           05 terr-no-OUT         PIC X(2).
       01  PAGE-HDR-3.
           05 pic x(20).
           05 pic x(6) value "OFFICE".
           05 pic x(1).
           05 val-3 pic x(2) value "--".
           05 pic x(1).
           05 office-no-out         PIC X(2).
       01  PAGE-HDR-4.
           05 pic x(10).
           05 pic x(13) value "EMPLOYEE NAME".
           05 pic x(7).
           05 pic x(5) value "BONUS".
       01  O-2 pic 9(2) value 02.
       01  tic pic 99 value 10.
       PROCEDURE DIVISION.
       100-main-module.
           open input payroll-in 
                output label-rec 
              DISPLAY "ENTER THE MONTH (XX): "
               ACCEPT CURRENT-MONTH 
              DISPLAY "ENTER THE DAY (XX): "
               ACCEPT CURRENT-DAY 
              DISPLAY "ENTER THE YEAR (XXXX): "
               ACCEPT CURRENT-YEAR 

               MOVE CURRENT-MONTH TO FORMATTED-DATE(1:2)
               MOVE '/'              TO FORMATTED-DATE(3:1)
               MOVE CURRENT-DAY   TO FORMATTED-DATE(4:2)
               MOVE '/'              TO FORMATTED-DATE(6:1)
               MOVE CURRENT-YEAR  TO FORMATTED-DATE(7:4)
           
               write print-rec from PAGE-HDR-1 
               write print-rec from BREAK

           perform until are-there-more-records = 'no '
              read payroll-in 
                    at end
                       move 'no ' to are-there-more-records 
                    not at end
              if tic = 10
              write print-rec from BREAK
              move terr-no to val-2 IN PAGE-HDR-2 
              move office-no to val-3 IN PAGE-HDR-3 
                       write print-rec from PAGE-HDR-2 
                       write print-rec from BREAK
                       write print-rec from PAGE-HDR-3 
                       write print-rec from BREAK
                       write print-rec from BREAK
                       write print-rec from PAGE-HDR-4
                       write print-rec from BREAK
                       compute tic = 0
                 END-IF    
                       compute tic = tic + 1
                       move emp-name to emp-name-out  
                       if year-hired IS LESS THAN 2015
                       move bonus-amt-10k to bonus-out
                       write print-rec 
                       else 
                       move emp-name to nameZ
                       write print-rec from if-nothing 
                       END-IF 
                       
              end-read
           END-PERFORM
           close payroll-in 
                 label-rec 
           stop run.
       