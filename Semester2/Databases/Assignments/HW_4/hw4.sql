-- 01. Αεροσκάφη που δεν έχουν κάνει καμιά πτήση
--     [όλα τα στοιχεία του αεροσκάφους]. (1 row)
-- (*)
select *
from aircrafts
where aircraft_code not in (select aircraft_code from flights);


-- 02. Οι κρατήσεις που κόστισαν πάνω από 1 εκατομμύριο ρούβλια και αποτελούνται 
--     από 4 εισιτήρια και πάνω [book_ref, total_amount, πλήθος_εισιτηρίων]. (3 rows)
-- (**)
select bookings.book_ref, total_amount, count(*)
from bookings natural join tickets
where total_amount>1000000
group by bookings.book_ref, total_amount
having count(*) > 3;


-- 03. Το όνομα του επιβάτη ή επιβατών που έχουν κάνει την πιο πρόσφατη κράτηση 
--     [passenger_name, book_date]. (10 rows)
-- (**)
select passenger_name, book_date
from tickets join bookings using(book_ref)
where book_date=(select max(book_date) from bookings);


-- 04. Τα μοντέλα των αεροσκαφών που έχουν ακυρωμένες πτήσεις και από και προς το 
--     St. Petersburg [model]. (5 rows)
-- (**)
select model
from aircrafts ac
where aircraft_code in 
(select aircraft_code from flights_v where departure_city='St. Petersburg' and status='Cancelled') 
and aircraft_code in 
(select aircraft_code from flights_v where  arrival_city='St. Petersburg' and status='Cancelled');


-- 05. Τα ονόματα των επιβατών με εισιτήριο business που έχουν πτήσεις μόνο προς 
--     τo Kursk [passenger_name]. (5 rows)
-- (***)
select passenger_name
from (tickets join ticket_flights using (ticket_no)) join flights_v using (flight_id)
where fare_conditions='Business' and arrival_city='Kursk'
except
select passenger_name 
from (tickets join ticket_flights using (ticket_no)) join flights_v using (flight_id)
where fare_conditions='Business' and arrival_city!='Kursk';


-- 06. Το πλήθος πτήσεων ανά αεροσκάφος με ταξινόμηση από αυτό με τις λιγότερες 
--     πτήσεις προς αυτό με τις περισσότερες. Να εμφανίζονται και τα αεροσκάφη που 
--     δεν έχουν πραγματοποιήσει καμία πτήση, αν υπάρχουν τέτοια αεροσκάφη 
--     [aircraft_code, model, πλήθος]. (9 rows) 
-- (***)
select aircraft_code, model, count(*) as number
from flights join aircrafts using(aircraft_code)
group by aircraft_code, model
union
select aircraft_code, model, 0
from aircrafts 
where aircraft_code not in (select aircraft_code from flights)
order by number


-- 07. Τυπώστε τα στοιχεία όλων των εισιτηρίων της κράτησης '070133' 
--     [ticket_no, flight_id, book_ref, book_date, total_amount, passenger_id, 
--     passenger_name, contact_data, fare_conditions, amount, boarding_no, seat_no]. 
--     Τα δυο τελευταία πεδία να εμφανίζονται μόνο αν έχει πραγματοποιηθεί η πτήση 
--     στην οποία αντιστοιχεί το εισιτήριο, αλλιώς να έχουν την τιμή NULL. (10 rows)
-- (****)
select *
from bookings natural join tickets natural join ticket_flights natural left join boarding_passes
where bookings.book_ref = '070133';


-- 08. Ζευγάρια αεροδρομίων που συνδέονται με πάνω από 2 δρομολόγια (προσοχή! - 
--     όχι πτήσεις) [departure_airport, arrival_airport, departure_city, 
--     arrival_city, πλήθος]. Επειδή κάθε πτήση από το αεροδρόμιο Α στο Β έχει και 
--     την πτήση επιστροφής από το αεροδρόμιο Β στο Α, να εμφανίσετε μόνο μια φορά 
--     κάθε ζευγάρι. Επίσης, το αποτέλεσμα να είναι ταξινομημένο ως προς 
--     departure_airport. (6 rows)
-- (****)
select departure_airport, arrival_airport, departure_city, arrival_city, count(*)
from routes
where departure_airport < arrival_airport
group by departure_airport, arrival_airport, departure_city, arrival_city
having count(*) > 2
order by departure_airport;


-- 09. Τα αεροσκάφη που έχουν πετάξει προς όλα τα αεροδρόμια πόλεων που αρχίζουν 
--     από 'Υ' [aircraft_code]. (1 row)
-- (****)
select aircraft_code
from aircrafts ac
where not exists
( select * from airports ap
where city like 'Y%'  and not exists
( select * from flights_v  fv where
ac.aircraft_code=fv.aircraft_code and ap.airport_code=fv.arrival_airport));


-- 10. Το όνομα του αεροδρομίου από το οποίο έχουν προγραμματιστεί να γίνουν οι 
--     περισσότερες πτήσεις μετά από τις 31/07/2017 [departure_airport_name]. (1 row)
-- (****)
select departure_airport_name
from flights_v
where date(scheduled_departure)>'2017-07-31'
group by departure_airport, departure_airport_name
having count(*)>=all(select count(*)
from flights_v
where date(scheduled_departure)>'2017-07-31'
group by departure_airport);
