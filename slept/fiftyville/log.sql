-- Keep a log of any SQL queries you execute as you solve the mystery.

--
select description from crime_scene_reports
where year=2021 and month = 7 and day = 28 and street = "Humphrey Street";

--
select name, transcript from interviews
where day = "28" and month = "7" and year = "2021";

--
select account_number, amount from atm_transactions
where year = 2021 and month =7 and day=28 and atm_location='Leggett Street' and transaction_type='withdraw';

--
select name, att.amount, att.account_number from people as p
join bank_accounts as ba on p.id = ba.person_id
join atm_transactions as att on ba.account_number = att.account_number
where att.year=2021
and att.month=7
and att.day=28
and att.atm_location='Leggett Street'
and att.transaction_type = 'withdraw';

--


--
select name, phone_calls.duration
from people
join phone_calls
on people.phone_number = phone_calls.caller
where phone_calls.year = 2021
and phone_calls.month = 7
and phone_calls.day = 28
and phone_calls.duration <= 60
order by phone_calls.duration;

--
select name, phone_calls.duration
from people
join phone_calls
on people.phone_number = phone_calls.receiver
where phone_calls.year = 2021
and phone_calls.month = 7
and phone_calls.day = 28
and phone_calls.duration <= 60
order by phone_calls.duration;

--
select name, bakery_security_logs.hour, bakery_security_logs.minute
from people
join bakery_security_logs
on people.license_plate = bakery_security_logs.license_plate
where bakery_security_logs.year = 2021
and bakery_security_logs.month = 7
and bakery_security_logs.day = 28
and bakery_security_logs.activity = 'exit'
and bakery_security_logs.minute >= 15
and bakery_security_logs.minute <= 25
order by bakery_security_logs.minute;