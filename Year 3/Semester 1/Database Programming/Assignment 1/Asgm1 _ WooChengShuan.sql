#TASK 1
#create database
CREATE DATABASE hostel_mgmt_woochengshuan;
USE hostel_mgmt_woochengshuan;

#create tables
CREATE TABLE room_types (
	type_id INT AUTO_INCREMENT,
	type_name VARCHAR(10) NOT NULL UNIQUE,
    rent DECIMAL(8,2) NOT NULL,
    deposit DECIMAL(8,2) NOT NULL,
    capacity INT NOT NULL,
    PRIMARY KEY (type_id)
);

CREATE TABLE rooms (
	room_id INT AUTO_INCREMENT,
    type_id INT,
    room_no VARCHAR(5) NOT NULL,
    floor_no VARCHAR(2) NOT NULL,
    is_occupied BOOLEAN NOT NULL DEFAULT FALSE,
    PRIMARY KEY (room_id),
    FOREIGN KEY (type_id) REFERENCES room_types(type_id)
);
    
CREATE TABLE students (
	student_id INT AUTO_INCREMENT,
    room_id INT,
    fname VARCHAR(40) NOT NULL,
    lname VARCHAR(40) NOT NULL,
    status ENUM ('ACTIVE', 'NON_ACTIVE'),
    checkin_date DATE,
    email VARCHAR(50) NOT NULL,
    PRIMARY KEY (student_id),
    FOREIGN KEY (room_id) REFERENCES rooms(room_id)
);

CREATE TABLE maintenance (
	maint_id INT AUTO_INCREMENT,
    room_id INT,
    issue_desc TEXT NOT NULL,
    severity ENUM ('LOW', 'MEDIUM', 'HIGH'),
    status ENUM ('OPEN', 'RESOLVED'),
    reported_on DATE,
    resolved_on DATE,
    PRIMARY KEY (maint_id),
    FOREIGN KEY (room_id) REFERENCES rooms(room_id)
);

CREATE TABLE payments (
	payment_id INT AUTO_INCREMENT,
    student_id INT,
    amount DECIMAL(10,2) NOT NULL,
    paid_on DATE,
    method ENUM ('CASH', 'FPX', 'CARD', 'TNG'),
    note TEXT NOT NULL,
    PRIMARY KEY (payment_id),
    FOREIGN KEY (student_id) REFERENCES students(student_id)
);

#alter table
ALTER TABLE students
MODIFY email VARCHAR(50) NOT NULL UNIQUE;

#drop table
CREATE TABLE temp_test (
	test_id INT
);
DROP TABLE temp_test;

#TASK 2
#insert data
INSERT INTO room_types (type_name, rent, deposit, capacity) 
VALUES
('Single', '350.00', '105.00', '1'),
('Double', '500.00', '150.00', '2'),
('Premium', '900.00', '270.00', '2'),
('Family', '1200.00', '360.00', '4'),
('Economy', '420.00', '126.00', '1'),
('Studio', '700.00', '210.00', '1'),
('Deluxe', '650.00', '195.00', '2'),
('Suite', '1500.00', '450.00', '3'),
('Accessible', '480.00', '144.00', '2'),
('Shared', '300.00', '90.00', '3');

INSERT INTO rooms (type_id, room_no, floor_no)
VALUES
(1, 'A101', 1),
(2, 'A102', 1),
(3, 'A103', 1),
(4, 'B101', 2),
(5, 'B102', 2),
(6, 'B103', 2),
(7, 'C101', 3),
(8, 'C102', 3),
(9, 'C103', 3),
(10, 'C104', 3);

INSERT INTO rooms (type_id, room_no, floor_no)
VALUES
(1, 'A104', 1),
(1, 'A105', 1);

INSERT INTO students (room_id, fname, lname, status, checkin_date, email)
VALUES
(1, 'Liam', 'Ong', 'ACTIVE', '2024-09-01', 'liamong@gmail.com'),
(NULL, 'Noah', 'Lee', 'NON_ACTIVE', NULL, 'noahlee@gmail.com'),
(2, 'Oliver', 'Zhang', 'ACTIVE', '2024-10-01', 'oliverzhang@gmail.com'),
(3, 'Emma', 'Low', 'ACTIVE', '2024-09-20', 'emmalow@gmail.com'),
(NULL, 'Grace', 'Chen', 'NON_ACTIVE', NULL, 'gracechen@gmail.com'),
(4, 'Amelia', 'Woo', 'ACTIVE', '2024-10-12', 'ameliawoo@gmail.com'),
(5, 'Charlotte', 'Heng', 'ACTIVE', '2024-10-18', 'charlotteheng@gmail.com'),
(NULL, 'Mia', 'Cheong', 'NON_ACTIVE', NULL, 'miacheong@gmail.com'),
(7, 'Jackson', 'Wang', 'ACTIVE', '2024-08-22', 'jacksonwang@gmail.com'),
(NULL, 'Henry', 'Chau', 'NON_ACTIVE', NULL, 'henrychau@gmail.com');

INSERT INTO students (room_id, fname, lname, status, checkin_date, email)
VALUES
(15, 'Vivian', 'Chang', 'ACTIVE', '2024-09-02', 'vivianchang@gmail.com'),
(16, 'Daniel', 'Kang', 'ACTIVE', '2024-09-03', 'danielkang@gmail.com');

INSERT INTO maintenance (room_id, issue_desc, severity, status, reported_on, resolved_on)
VALUES
(1, 'WATER LEAKAGE', 'HIGH', 'RESOLVED', '2024-08-23', '2024-08-24'),
(2, 'NO WATER', 'HIGH', 'OPEN', '2024-09-02', NULL),
(3, 'NO ELECTRIC', 'MEDIUM', 'RESOLVED', '2024-06-14', '2024-06-15'),
(4, 'BROKEN WINDOW', 'LOW', 'OPEN', '2024-09-12', NULL),
(5, 'AC NOT COOLING', 'MEDIUM', 'RESOLVED', '2024-07-26', '2024-07-28'),
(6, 'CEILING CRACK', 'LOW', 'OPEN', '2024-09-20', NULL),
(7, 'BROKEN BED FRAME', 'MEDIUM', 'OPEN', '2024-09-15', NULL),
(8, 'BAD SMELL', 'HIGH', 'RESOLVED', '2024-07-30', '2024-08-05'),
(9, 'DOOR CANNOT LOCK', 'HIGH', 'RESOLVED', '2024-06-03', '2024-06-05'),
(10, 'SUIS SPOILED', 'MEDIUM', 'RESOLVED', '2024-06-27', '2024-06-30');

INSERT INTO maintenance (room_id, issue_desc, severity, status, reported_on, resolved_on)
VALUES
(15, 'NO WATER', 'HIGH', 'OPEN', '2024-09-03', NULL),
(16, 'NO ELECTRIC', 'MEDIUM', 'OPEN', '2024-09-04', NULL);

INSERT INTO payments (student_id, amount, paid_on, method, note)
VALUES
(1, 350.00, '2024-06-01', 'TNG', 'JUNE RENT'),
(2, 500.00, '2024-06-03', 'CASH', 'JUNE RENT'),
(3, 420.00, '2024-07-01', 'TNG', 'JULY RENT'),
(4, 700.00, '2024-07-08', 'CARD', 'JULY RENT'),
(5, 900.00, '2024-08-02', 'FPX', 'AUGUST RENT'),
(6, 300.00, '2024-08-10', 'CASH', 'AUGUST RENT'),
(7, 650.00, '2024-09-05', 'TNG', 'SEPTEMBER RENT'),
(8, 300.00, '2024-09-07', 'CARD', 'SEPTEMBER RENT'),
(9, 480.00, '2024-10-02', 'FPX', 'OCTOBER RENT'),
(10, 420.00, '2024-10-09', 'TNG', 'OCTOBER RENT');

#update and delete
UPDATE rooms r
JOIN (
	SELECT room_id
    FROM students
    WHERE status = 'ACTIVE' AND room_id IS NOT NULL
    GROUP BY room_id
) s ON r.room_id = s.room_id
SET r.is_occupied = 1;

#to solve error code 1175 - turn off to run delete then turn on after run
SET SESSION sql_safe_updates = 1;

DELETE FROM maintenance
WHERE status = 'RESOLVED'
AND reported_on < DATE_SUB(curdate(), INTERVAL 60 DAY);

#data retrieval
#between
SELECT * FROM room_types
WHERE rent BETWEEN 400 AND 800;

#like
SELECT * FROM students
WHERE fname LIKE 'A%';

#in
SELECT * FROM payments
WHERE method IN ('FPX', 'CARD');

#and, or, not
SELECT * FROM maintenance
WHERE (severity = 'HIGH' AND STATUS = 'OPEN')
OR (NOT (severity IN ('LOW') AND STATUS = 'OPEN'));

#functions
#aggregate
SELECT 
	method,
    SUM(amount) AS total_amount
FROM payments
WHERE method IN ('FPX', 'CARD', 'TNG', 'CASH')
GROUP BY method;

#string
SELECT
	student_id,
    UPPER(CONCAT(fname, ' ', lname)) AS full_name,
    LENGTH(CONCAT(fname, ' ', lname)) AS full_name_length
FROM students;

#TASK 3
#create view
CREATE VIEW v_room_status AS
SELECT
	r.room_no,
    rt.type_name,
    rt.rent,
    r.floor_no,
    rt.capacity,
    
    COUNT(DISTINCT s.student_id) AS n_occupants,
    COUNT(DISTINCT m.maint_id) AS pending_issues,
	CASE 
		WHEN COUNT(DISTINCT s.student_id) = 0 THEN TRUE 
		ELSE FALSE 
	END AS is_vacant
    
FROM rooms r
JOIN room_types rt ON r.type_id = rt.type_id
LEFT JOIN students s ON s.room_id = r.room_id AND s.status = 'ACTIVE'
LEFT JOIN maintenance m ON m.room_id = r.room_id AND s.status = 'OPEN'
GROUP BY r.room_no, rt.type_name, rt.rent, r.floor_no, rt.capacity;

#summary queries
#total number of students
SELECT 
	rt.type_name,
	COUNT(s.student_id) AS total_students
FROM room_types rt
LEFT JOIN rooms r ON r.type_id = rt.type_id
LEFT JOIN students s ON s.room_id = r.room_id
GROUP BY rt.type_name;

#average rent and total deposit
SELECT
	ROUND(AVG(rt.rent), 2) AS avg_rent,
    ROUND(SUM(rt.deposit), 2) AS total_deposit
FROM room_types rt
GROUP BY rt.type_name;

#monthly payment
SELECT
	YEAR(p.paid_on) AS year,
    MONTH(p.paid_on) AS month,
    SUM(p.amount) AS total_payment
FROM payments p
GROUP BY year, month;

#count of open maintenance
SELECT
	r.floor_no,
    COUNT(m.maint_id) AS maint_issues
FROM rooms r
LEFT JOIN maintenance m ON r.room_id = m.room_id AND m.status = 'OPEN'
GROUP BY r.floor_no
HAVING COUNT(m.maint_id) > 2;

#apply sql functions
SELECT
	CONCAT('Floor ' , r.floor_no, ' - ', UPPER(rt.type_name)) AS room_label,
    ROUND(rt.rent, 2) AS rent,
    ROUND(rt.deposit, 2) AS deposit,
    COUNT(DISTINCT CASE WHEN s.status = 'ACTIVE' THEN s.student_id END) AS n_occupant,
    COUNT(DISTINCT CASE WHEN m.status = 'OPEN' THEN m.maint_id END) AS open_issues,
    CASE
		WHEN rt.rent <= 500 THEN 'LOW'
        WHEN rt.rent BETWEEN 501 AND 1000 THEN 'MEDIUM'
        ELSE 'HIGH'
	END AS rent_category
FROM rooms r
JOIN room_types rt ON r.type_id = rt.type_id
LEFT JOIN students s ON r.room_id = s.room_id
LEFT JOIN maintenance m ON r.room_id = m.room_id
GROUP BY r.room_id, r.floor_no, rt.type_id, rt.rent, rt.deposit
ORDER BY r.floor_no;
