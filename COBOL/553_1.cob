       IDENTIFICATION DIVISION.
       PROGRAM-ID. 553_1.
       ENVIRONMENT DIVISION. 
       INPUT-OUTPUT SECTION. 
       FILE-CONTROL. SELECT SALESPERSON-in    ASSIGN TO sales
           ORGANIZATION IS LINE SEQUENTIAL.
                     SELECT label-rec  ASSIGN TO printer.
       DATA DIVISION.
       file section.
       fd  SALESPERSON-in.
       01  employee-record.
           05 SALESPERSON-NO   pic 9(2).
           05 SALESPERSON-NAME pic x(20).
           05 AMT-OF-SALES PIC 9(5)V9(2).
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
       01  PAGE-HDR-1.
           05 pic x(31).
           05 pic x(32) value "TOTAL SALES FOR EACH SALESPERSON".
           05 pic x(4).
           05 FORMATTED-DATE         PIC X(10).
       01  PAGE-HDR-2.
           05 pic x(10).
           05 pic x(15) value "SALESPERSON NO.".
           05 pic x(4).
           05 pic x(16) value "SALESPERSON NAME".
           05 pic x(9).
           05 pic x(11) value "TOTAL SALES".
       01  PAGE-HDR-3.
           05 pic x(40).
           05 pic x(19) value "TOTAL COMPANY SALES".
           05 pic x(3).
           05 GRAND-TOTAL PIC 99999999.99.
       01  TOTAL-SALES.
           05 TOTALss   PIC 99999.99 OCCURS 20 TIMES.
       01  SALES_NAMES.
           05 NAMES   PIC X(20) OCCURS 20 TIMES.
       01  ID-NUMBERS.
           05 NUMS   PIC 9(2) OCCURS 20 TIMES.
       01  TIC PIC 99 VALUE 1.
       01  space-1 PIC x(12).
       01  space-2 PIC x(5).
       01  Formatted-total pic $ZZ,ZZZ.99.
       01  NO-moved pic 99.
       PROCEDURE DIVISION.
       100-main-module.
           open input SALESPERSON-in 
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

               PERFORM UNTIL TIC = 20
                 MOVE 0 TO TOTALss(TIC)
               END-PERFORM


           
               write print-rec from PAGE-HDR-1 
               write print-rec from BREAK
               write print-rec from PAGE-HDR-2

           perform until are-there-more-records = 'no '
              read SALESPERSON-in 
                at end
                  MOVE 0 TO TIC 
                  PERFORM UNTIL TIC = 20
                  write print-rec from NUMS(TIC) AFTER ADVANCING 0 LINES
                  write print-rec from space-1
                 write print-rec from NAMES(TIC) AFTER ADVANCING 0 LINES
                  write print-rec from space-2
                  move TOTALss(TIC) to Formatted-total 
                  write print-rec from Formatted-total 
                    END-PERFORM
                       move 'no ' to are-there-more-records 
                    not at end
                       MOVE SALESPERSON-NAME TO NAMES(SALESPERSON-NO)
                       MOVE SALESPERSON-NO  TO NUMS(SALESPERSON-NO)
                       MOVE SALESPERSON-NO TO NO-moved
                       COMPUTE TOTALss(NO-moved) 
                       = TOTALss(NO-moved) + AMT-OF-SALES
                       

                       
              end-read
           END-PERFORM
           close SALESPERSON-in 
                 label-rec 
           stop run.
       