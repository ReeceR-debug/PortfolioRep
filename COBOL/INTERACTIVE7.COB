       IDENTIFICATION DIVISION.
       PROGRAM-ID. INTERACTIVE7.
       DATA DIVISION.
       WORKING-STORAGE SECTION. 
       01  TOTAL     PIC 999V99.
       01  TAX      PIC 9V99 VALUE 1.08.
       01  TOTAL_WITH_TAX PIC 999V99.
       01  MORE-DATA PIC XXX VALUE "YES".
       PROCEDURE DIVISION.
       100-MAIN.
           PERFORM UNTIL MORE-DATA = "NO "
              DISPLAY "ENTER TOTAL BEFORE TAX: "
              ACCEPT TOTAL 
              MULTIPLY TOTAL BY TAX GIVING TOTAL_WITH_TAX 
              DISPLAY "TOTAL WITH TAX IS: ", TOTAL_WITH_TAX 
              DISPLAY "IS THERE MORE DATA (YES/NO)?"
              ACCEPT MORE-DATA 
           END-PERFORM
           STOP RUN.
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