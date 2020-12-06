-- Keep a log of any SQL queries you execute as you solve the mystery.
-- Finding description:
SELECT description FROM crime_scene_reports WHERE year = 2020 AND month = 7 AND day = 28 AND street = 'Chamberlin Street'
-- Checking interview transcript from the day to identify the 3 withnesses: Ruth, Eugene and Raymond
SELECT name, transcript FROM interviews WHERE year = 2020 AND month= 7 AND day = 28 AND transcript LIKE '%courthouse%'

-- From Ruth's script, check car plate of those who left between 10:15 am to 10:25 am
SELECT license_plate FROM courthouse_security_logs WHERE year = 2020 AND month = 7 AND day = 28 AND hour = 10 AND activity = 'exit' AND minute BETWEEN 15 AND 25
-----  From there, check the name that matches the plate
SELECT name FROM people WHERE license_plate = '5P2BI95' OR license_plate = '94KL13X' OR license_plate = '6P58WS2'OR license_plate = '4328GD8'OR license_plate = 'G412CB7'
OR license_plate = 'L93JTIZ' OR license_plate = '322W7JE' OR license_plate = '0NTHK55'
INSTRUCTOR
| 10/30 AT 8:32 AM
instead of hard-coding those values, you could've found a way to do the query through join statements

    -- Potential suspect from here: Patrick, Amber, Elizabeth, Roger, Danielle, Rusell, Eveleyn, Ernest

-- From Eugene's script, try to narrow done suspect
SELECT bank_accounts.person_id FROM bank_accounts JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
WHERE atm_transactions.year = 2020 AND atm_transactions.month = 7 AND atm_transactions.day = 28
AND atm_transactions.atm_location = 'Fifer Street'
---- From there, select names that match the person_id:
SELECT name FROM people WHERE id = '467400' OR id = '395717' OR id = '449774' OR id = '686048' OR id = '458378' OR id = '948985' OR id = '396669' OR id = '438727' OR id = '514354'
-- Potential suspect decreased to 4: Danielle, Elizabeth, Ernest, Rusell
INSTRUCTOR
| 10/30 AT 8:33 AM
don't hard code


-- First, from Raymond's interview, let's try to find out the thief and who he called:
SELECT people.name, phone_calls.caller, phone_calls.receiver FROM people JOIN phone_calls ON people.phone_number = phone_calls.caller WHERE year = 2020 AND month  = 7 AND day = 28 AND duration <=60 
 -- From here, we know Ernest and Rusell is the caller, but we want to know who they called to know the accomplice:
SELECT  name FROM people WHERE phone_number = '(375) 555-8161'
SELECT  name FROM people WHERE phone_number='(725) 555-3243' 
-- Potential suspect decreased to 2: Ernest call Berthold, Rusell call Philips
    -- searching for the earliest flight:
    SELECT id, min(hour), minute, origin_airport_id, destination_airport_id FROM flights WHERE year = 2020 AND month = 7 AND day = 29
    -- matching it with names that board the flight:
    SELECT name FROM people JOIN passengers ON people.passport_number = passengers.passport_number JOIN flights ON passengers.flight_id = flights.id WHERE flight_id = 36
    ---- Check which city he escaped to:
        SELECT city FROM airports WHERE id = 4
        -- Thief : Ernest
        -- City escaped: London

---- The accomplice:
        -- from above, since Ernest called Berthold, hence the accomplice is Berthold.
