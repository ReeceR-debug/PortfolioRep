       IDENTIFICATION DIVISION.
       PROGRAM-ID. Cap3-8.
       DATA DIVISION.
       WORKING-STORAGE SECTION. 
       01  CUSTOMER-NAME                  PIC X(7).
       01  AMT-OF-PURCHASE                PIC 9999V99.
       01  BALANCE-DUE                    PIC 9999V99.
       01  TEN-PERCENT-OFF                PIC V99 VALUE .90.
       01  MORE-DATA                      PIC XXX VALUE "YES".
       PROCEDURE DIVISION.
       100-MAIN.
           PERFORM UNTIL MORE-DATA = "NO "
              DISPLAY "ENTER YOUR NAME: "
              ACCEPT CUSTOMER-NAME 
              DISPLAY "ENTER THE AMOUNT OF YOUR PURCHASE: "
              ACCEPT AMT-OF-PURCHASE 

              MULTIPLY AMT-OF-PURCHASE BY TEN-PERCENT-OFF
               GIVING BALANCE-DUE 
              DISPLAY "CUSTOMER NAME: ", CUSTOMER-NAME 
              DISPLAY "BALENCE DUE: ", BALANCE-DUE
              DISPLAY "IS THERE MORE DATA (YES/NO)?"
              ACCEPT MORE-DATA 
           END-PERFORM
           STOP RUN.
