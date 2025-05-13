       IDENTIFICATION DIVISION.
       PROGRAM-ID. 132_2.
       ENVIRONMENT DIVISION. 
       INPUT-OUTPUT SECTION. 
       FILE-CONTROL. SELECT employee-info    ASSIGN TO emp-info
           ORGANIZATION IS LINE SEQUENTIAL.
                     SELECT payroll-record  ASSIGN TO printer.
       DATA DIVISION.
       file section.
       fd  employee-info.
       01  employee-record.
           05  employee-NO             pic X(5).
           05  employee-name           pic X(20).
           05  location-code.
              10  territory-NO         pic X(2).
              10  office-NO            pic X(2).
           05  annual-salary           pic X(6).
           05  social-security-NO      pic X(9).
           05  NO-of-dependents        pic XX.
           05  job-classification-code pic XX.
       fd  payroll-record.
       01  print-rec.
           05  employee-NO-out             pic X(5).
           05                              pic XX.
           05  employee-name-out           pic X(20).
           05                              pic X.
           05  location-code-out.
              10  territory-NO-out         pic X(2).
              10                           pic X.
              10  office-NO-out            pic X(2).
           05                              pic XX.
           05  annual-salary-out           pic X(6).
           05                              pic XX.
           05  social-security-NO-out      pic X(9).
           05                              pic XX.
           05  NO-of-dependents-out        pic XX.
           05                              pic XX.
           05  job-classification-code-out pic XX.
       WORKING-STORAGE SECTION.
       01  are-there-more-records   picture xxx value 'yes'.
       PROCEDURE DIVISION.
       100-main-module.
           open input employee-info 
                output payroll-record 
           perform until are-there-more-records = 'no '
              read employee-info 
                    at end
                       move 'no ' to are-there-more-records 
                    not at end
                       perform 200-move-routine
              end-read
           END-PERFORM
           close employee-info 
                 payroll-record 
           stop run.
       200-move-routine.
           move spaces to print-rec
           move employee-NO to employee-NO-out
           move employee-name to employee-name-out
           move territory-NO to territory-NO-out
           move office-NO to office-NO-out
           move annual-salary to annual-salary-out 
           move social-security-NO to social-security-NO-out 
           move NO-of-dependents to NO-of-dependents-out
           move job-classification-code to job-classification-code-out 
           write print-rec.
