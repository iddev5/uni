Now using Node v20.12.0 (npm 10.5.0) ~/.local/share/nvm/v20.12.0/bin/node
Welcome to fish, the friendly interactive shell
Type help for instructions on how to use fish

ayush@fedora ~ 
❯ sudo mysql -u root -p                                                                                         09:40:34
[sudo] password for ayush: 
Enter password: 
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 8
Server version: 8.0.31 Source distribution

Copyright (c) 2000, 2022, Oracle and/or its affiliates.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> select * from client_master;
ERROR 1046 (3D000): No database selected
mysql> use university;
Reading table information for completion of table and column names
You can turn off this feature to get a quicker startup with -A

Database changed
mysql> show tables;
+----------------------+
| Tables_in_university |
+----------------------+
| challan_details      |
| challan_header       |
| client_master        |
| product_master       |
| sales_master         |
| sales_order          |
+----------------------+
6 rows in set (0.00 sec)

mysql> select * from client_master;
+-----------+---------+--------+-------------+---------+---------+--------------+
| client_no | name    | city   | state       | pincode | bal_due | phone_number |
+-----------+---------+--------+-------------+---------+---------+--------------+
| 0001      | Ivan    | Bombay | Tamil Nadu  |  768003 | 1000.00 | NULL         |
| 0003      | Pramada | Bombay | Maharashtra |  400057 | 5000.00 | NULL         |
| 0004      | Basu    | Bombay | Maharashtra |  400056 |    0.00 | NULL         |
| 0005      | Ravi    | Bombay | NULL        |  100001 | 2000.00 | NULL         |
| 0006      | Rukmini | Bombay | Maharashtra |  400050 |    0.00 | NULL         |
+-----------+---------+--------+-------------+---------+---------+--------------+
5 rows in set (0.02 sec)

mysql> select * from product_master;
+------------+---------------+----------------+--------------+------------------+---------+-----------+-----------+
| product_no | description   | profit_percent | unit_measure | quantity_on_hand | reorder | sellprice | costprice |
+------------+---------------+----------------+--------------+------------------+---------+-----------+-----------+
| p00001     | 1.44 Floppies |           5.00 | 4            |              100 | 20      |   1150.00 |    500.00 |
| p03453     | Monitors      |           6.00 | 3            |               10 | 3       |  12000.00 |  11200.00 |
| p06734     | Mouse         |           5.00 | 9            |               20 | 5       |   1015.00 |    500.00 |
| p07865     | 1.22 Floppies |           5.00 | 12           |              100 | 20      |    525.00 |    500.00 |
| p07868     | Keyboards     |           2.00 | 10           |               10 | 3       |   3150.00 |   3050.00 |
| p07885     | CD Drive      |           2.50 | 8            |               10 | 3       |   5250.00 |   5100.00 |
| p07965     | 540 HDD       |           4.00 | 7            |               10 | 3       |   8400.00 |   8000.00 |
| p07975     | 1.44 Drive    |           5.00 | 20           |               10 | 3       |   1050.00 |   1000.00 |
| p08865     | 1.22 Drive    |           5.00 | 21           |                2 | 3       |   1050.00 |   1000.00 |
+------------+---------------+----------------+--------------+------------------+---------+-----------+-----------+
9 rows in set (0.01 sec)

mysql> select * from sales_master;
+-------------+------------+------------+--------+-------------+---------+--------------+---------------+--------+---------+
| salesman_no | sales_name | address    | city   | state       | pincode | sales_amount | target_to_get | sales  | remarks |
+-------------+------------+------------+--------+-------------+---------+--------------+---------------+--------+---------+
| 500001      | Kiran      | A/14 Worli | Bombay | Maharashtra |  400002 |      3000.00 |        100.00 |  50.00 | Good    |
| 500002      | Manish     | 65, Marine | Bombay | Maharashtra |  400001 |      3000.00 |        200.00 | 100.00 | Good    |
| 500003      | Ravi       | P-7 Bandra | Bombay | Maharashtra |  400032 |      3000.00 |        200.00 | 100.00 | Good    |
| 500004      | Ashish     | A/5 Juhu   | Bombay | Maharashtra |  400044 |      3500.00 |        200.00 | 150.00 | Good    |
+-------------+------------+------------+--------+-------------+---------+--------------+---------------+--------+---------+
4 rows in set (0.02 sec)

mysql> select * from sales_order;
+----------+------------+-----------+-------------+-------------+---------------+-----------+---------------+--------------+
| order_no | order_date | client_no | dely_add    | salesman_no | delivery_type | billed_yn | delivery_date | order_status |
+----------+------------+-----------+-------------+-------------+---------------+-----------+---------------+--------------+
| 010008   | 1996-05-24 | 0005      | XYZ-Colony  | 500004      | F             | N         | 1996-05-26    | IP           |
| 016865   | 1996-02-18 | 0003      | Juhu        | 500003      | F             | Y         | 1996-02-20    | F            |
| 019001   | 1996-01-12 | 0001      | A2 Borivali | 500001      | F             | N         | 1996-01-20    | IP           |
| 019002   | 1996-01-25 | 0006      | Mud Island  | 500002      | P             | N         | 1996-01-27    | C            |
| 019003   | 1996-04-03 | 0001      | ABC Lane    | 500001      | P             | Y         | 1996-04-07    | F            |
| 046866   | 1996-05-20 | 0004      | MNO Road    | 500002      | P             | N         | 1996-05-22    | C            |
+----------+------------+-----------+-------------+-------------+---------------+-----------+---------------+--------------+
6 rows in set (0.00 sec)

mysql> select * from challan_details;
+------------+------------+----------+
| challan_no | product_no | qty_disp |
+------------+------------+----------+
| CH3965     | p00001     |     5.00 |
| CH3966     | p07975     |     2.00 |
| CH6865     | p07868     |     3.00 |
| CH6866     | p03453     |     4.00 |
| CH6867     | p00001     |    10.00 |
| CH9001     | p00001     |     4.00 |
| CH9002     | p07965     |     1.00 |
| CH9003     | p07885     |     1.00 |
+------------+------------+----------+
8 rows in set (0.02 sec)

mysql> select * from challan_header;
+------------+----------+--------------+-----------+
| challan_no | order_no | challan_date | billed_yn |
+------------+----------+--------------+-----------+
| CH3965     | 010008   | 1995-10-12   | Y         |
| CH6865     | 016865   | 1995-11-12   | Y         |
| CH9001     | 019001   | 1995-12-12   | Y         |
+------------+----------+--------------+-----------+
3 rows in set (0.02 sec)

mysql> create table sales_order_details(
    -> sale_order_no varchar(6) primary key,
    -> product_no varchar(6),
    -> qty_ord number(8),
    -> qty_disp number(8),
    -> prod_rate decimal(10, 2));
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MySQL server version for the right syntax to use near 'number(8),
qty_disp number(8),
prod_rate decimal(10, 2))' at line 4
mysql> create table sales_order_details( sale_order_no varchar(6) primary key, product_no varchar(6), qty_ord integer(8), qty_disp integer(8), prod_rate decimal(10, 2));
Query OK, 0 rows affected, 2 warnings (0.05 sec)

mysql> describe sales_order_details
    -> ;
+---------------+---------------+------+-----+---------+-------+
| Field         | Type          | Null | Key | Default | Extra |
+---------------+---------------+------+-----+---------+-------+
| sale_order_no | varchar(6)    | NO   | PRI | NULL    |       |
| product_no    | varchar(6)    | YES  |     | NULL    |       |
| qty_ord       | int           | YES  |     | NULL    |       |
| qty_disp      | int           | YES  |     | NULL    |       |
| prod_rate     | decimal(10,2) | YES  |     | NULL    |       |
+---------------+---------------+------+-----+---------+-------+
5 rows in set (0.00 sec)

mysql> drop table sales_order_details;
Query OK, 0 rows affected (0.04 sec)

mysql> create table sales_order_details( sale_order_no varchar(6) primary key, product_no varchar(6), qty_ord integer(8), qty_disp integer(8), prod_rate decimal(10, 2), foreign key sale_order_no references sales_order(order_no), foreign key product_no references product_master(product_no) );
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MySQL server version for the right syntax to use near 'references sales_order(order_no), foreign key product_no references product_mast' at line 1
mysql> create table sales_order_details( sale_order_no varchar(6) primary key, product_no varchar(6), qty_ord integer(8), qty_disp integer(8), prod_rate decimal(10, 2), foreign key (sale_order_no) references sales_order(order_no), foreign key (product_no) references product_master(product_no) );
Query OK, 0 rows affected, 2 warnings (0.05 sec)

mysql> describe sales_order_details;
+---------------+---------------+------+-----+---------+-------+
| Field         | Type          | Null | Key | Default | Extra |
+---------------+---------------+------+-----+---------+-------+
| sale_order_no | varchar(6)    | NO   | PRI | NULL    |       |
| product_no    | varchar(6)    | YES  | MUL | NULL    |       |
| qty_ord       | int           | YES  |     | NULL    |       |
| qty_disp      | int           | YES  |     | NULL    |       |
| prod_rate     | decimal(10,2) | YES  |     | NULL    |       |
+---------------+---------------+------+-----+---------+-------+
5 rows in set (0.00 sec)

mysql> insert into sales_order_details values ('019001', 'p00001', 4, 4, 525);
Query OK, 1 row affected (0.02 sec)

mysql> insert into sales_order_details values ('019002', 'p07965', 2, 1, 8400);
Query OK, 1 row affected (0.03 sec)

mysql> insert into sales_order_details values ('019003', 'p07885', 2, 1, 5250);
Query OK, 1 row affected (0.02 sec)

mysql> insert into sales_order_details values ('019004', 'p00001', 10, 0, 525);
ERROR 1452 (23000): Cannot add or update a child row: a foreign key constraint fails (`university`.`sales_order_details`, CONSTRAINT `sales_order_details_ibfk_1` FOREIGN KEY (`sale_order_no`) REFERENCES `sales_order` (`order_no`))
mysql> select * from sales_order;
+----------+------------+-----------+-------------+-------------+---------------+-----------+---------------+--------------+
| order_no | order_date | client_no | dely_add    | salesman_no | delivery_type | billed_yn | delivery_date | order_status |
+----------+------------+-----------+-------------+-------------+---------------+-----------+---------------+--------------+
| 010008   | 1996-05-24 | 0005      | XYZ-Colony  | 500004      | F             | N         | 1996-05-26    | IP           |
| 016865   | 1996-02-18 | 0003      | Juhu        | 500003      | F             | Y         | 1996-02-20    | F            |
| 019001   | 1996-01-12 | 0001      | A2 Borivali | 500001      | F             | N         | 1996-01-20    | IP           |
| 019002   | 1996-01-25 | 0006      | Mud Island  | 500002      | P             | N         | 1996-01-27    | C            |
| 019003   | 1996-04-03 | 0001      | ABC Lane    | 500001      | P             | Y         | 1996-04-07    | F            |
| 046866   | 1996-05-20 | 0004      | MNO Road    | 500002      | P             | N         | 1996-05-22    | C            |
+----------+------------+-----------+-------------+-------------+---------------+-----------+---------------+--------------+
6 rows in set (0.00 sec)

mysql>    insert into sales_order_details values ('016865', 'p07885', 10, 10, 5250);
Query OK, 1 row affected (0.02 sec)

mysql>    insert into sales_order_details values ('046866', 'p00001', 4, 4, 1050);
Query OK, 1 row affected (0.02 sec)

mysql>    insert into sales_order_details values ('010008', 'p00001', 10, 5, 525);
Query OK, 1 row affected (0.02 sec)

mysql> select * from sales_order;
+----------+------------+-----------+-------------+-------------+---------------+-----------+---------------+--------------+
| order_no | order_date | client_no | dely_add    | salesman_no | delivery_type | billed_yn | delivery_date | order_status |
+----------+------------+-----------+-------------+-------------+---------------+-----------+---------------+--------------+
| 010008   | 1996-05-24 | 0005      | XYZ-Colony  | 500004      | F             | N         | 1996-05-26    | IP           |
| 016865   | 1996-02-18 | 0003      | Juhu        | 500003      | F             | Y         | 1996-02-20    | F            |
| 019001   | 1996-01-12 | 0001      | A2 Borivali | 500001      | F             | N         | 1996-01-20    | IP           |
| 019002   | 1996-01-25 | 0006      | Mud Island  | 500002      | P             | N         | 1996-01-27    | C            |
| 019003   | 1996-04-03 | 0001      | ABC Lane    | 500001      | P             | Y         | 1996-04-07    | F            |
| 046866   | 1996-05-20 | 0004      | MNO Road    | 500002      | P             | N         | 1996-05-22    | C            |
+----------+------------+-----------+-------------+-------------+---------------+-----------+---------------+--------------+
6 rows in set (0.00 sec)

mysql> select * from sales_order;
+----------+------------+-----------+-------------+-------------+---------------+-----------+---------------+--------------+
| order_no | order_date | client_no | dely_add    | salesman_no | delivery_type | billed_yn | delivery_date | order_status |
+----------+------------+-----------+-------------+-------------+---------------+-----------+---------------+--------------+
| 010008   | 1996-05-24 | 0005      | XYZ-Colony  | 500004      | F             | N         | 1996-05-26    | IP           |
| 016865   | 1996-02-18 | 0003      | Juhu        | 500003      | F             | Y         | 1996-02-20    | F            |
| 019001   | 1996-01-12 | 0001      | A2 Borivali | 500001      | F             | N         | 1996-01-20    | IP           |
| 019002   | 1996-01-25 | 0006      | Mud Island  | 500002      | P             | N         | 1996-01-27    | C            |
| 019003   | 1996-04-03 | 0001      | ABC Lane    | 500001      | P             | Y         | 1996-04-07    | F            |
| 046866   | 1996-05-20 | 0004      | MNO Road    | 500002      | P             | N         | 1996-05-22    | C            |
+----------+------------+-----------+-------------+-------------+---------------+-----------+---------------+--------------+
6 rows in set (0.00 sec)

mysql> select product_no, description from product_master inner join challan_header on challan_header.product_no = product_master.product_no;
ERROR 1054 (42S22): Unknown column 'challan_header.product_no' in 'on clause'
mysql> select product_no, description from product_master inner join challan_details on challan_details.product_no = product_master.product_no;
ERROR 1052 (23000): Column 'product_no' in field list is ambiguous
mysql> select product_master.product_no, description from product_master inner join challan_details on challan_details.p
roduct_no = product_master.product_no;
+------------+---------------+
| product_no | description   |
+------------+---------------+
| p00001     | 1.44 Floppies |
| p00001     | 1.44 Floppies |
| p00001     | 1.44 Floppies |
| p03453     | Monitors      |
| p07868     | Keyboards     |
| p07885     | CD Drive      |
| p07965     | 540 HDD       |
| p07975     | 1.44 Drive    |
+------------+---------------+
8 rows in set (0.00 sec)
mysql> select product_master.product_no, description from product_master inner join challan_details on challan_details.product_no = product_master.product_no inner join challan_header on challan =; ;lect product_master.product_no, description from product_master inner join challan_details on challan_details.product_no = product_master.product_no inner join challan_header;
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MySQL server version for the right syntax to use near '' at line 1
ERROR: 
No query specified

mysql> select product_master.product_no, description from product_master inner join challan_details on challan_details.product_no = product_master.product_no inner join challan_header on challan_header.challan_no = challan_details.challan_no inner join sales_order on sales_order.order_no = challan_header.order_no where sales_order.order_status <> "IP";
+------------+-------------+
| product_no | description |
+------------+-------------+
| p07868     | Keyboards   |
+------------+-------------+
1 row in set (0.01 sec)

mysql> select product_master.product_no, description from product_master inner join challan_details on challan_details.product_no = product_master.product_no inner join challan_header on challan_header.challan_no = challan_details.challan_no inner join sales_order on sales_order.order_no = challan_header.order_no;
+------------+---------------+
| product_no | description   |
+------------+---------------+
| p00001     | 1.44 Floppies |
| p07868     | Keyboards     |
| p00001     | 1.44 Floppies |
+------------+---------------+
3 rows in set (0.00 sec)

mysql> select product_master.product_no, description, order_status from product_master inner join challan_details on challan_details.product_no = product_master.product_no inner join challan
_header on challan_header.challan_no = challan_details.challan_no inner join sales_order on sales_order.order_no = challan_header.order_no;
+------------+---------------+--------------+
| product_no | description   | order_status |
+------------+---------------+--------------+
| p00001     | 1.44 Floppies | IP           |
| p07868     | Keyboards     | F            |
| p00001     | 1.44 Floppies | IP           |
+------------+---------------+--------------+
3 rows in set (0.00 sec)

mysql> select product_master.product_no, description from product_master inner join challan_details on challan_details.product_no = product_master.product_no inner join challan_header on challan_header.challan_no = challan_details.challan_no inner join sales_order on sales_order.order_no = challan_header.order_no where sales_order.order_status <> "IP";
+------------+-------------+
| product_no | description |
+------------+-------------+
| p07868     | Keyboards   |
+------------+-------------+
1 row in set (0.00 sec)

mysql> select name, address, city, pincode from client_master inner join sales_order on sales_order.client_no = client_master.client_no;
ERROR 1054 (42S22): Unknown column 'address' in 'field list'
mysql> select name, city, state, pincode from client_master inner join sales_order on sales_order.client_no = client_master.client_no;
+---------+--------+-------------+---------+
| name    | city   | state       | pincode |
+---------+--------+-------------+---------+
| Ivan    | Bombay | Tamil Nadu  |  768003 |
| Ivan    | Bombay | Tamil Nadu  |  768003 |
| Pramada | Bombay | Maharashtra |  400057 |
| Basu    | Bombay | Maharashtra |  400056 |
| Ravi    | Bombay | NULL        |  100001 |
| Rukmini | Bombay | Maharashtra |  400050 |
+---------+--------+-------------+---------+
6 rows in set (0.00 sec)

mysql> select name, city, state, pincode from client_master inner join sales_order on sales_order.client_no = client_master.client_no where sales_order.order_no = '019001';
+------+--------+------------+---------+
| name | city   | state      | pincode |
+------+--------+------------+---------+
| Ivan | Bombay | Tamil Nadu |  768003 |
+------+--------+------------+---------+
1 row in set (0.00 sec)

mysql> select client_master.client_no, name from client_master inner join client_master.client_no = sales_order.client_no  inner join sales_order on sales_order.;
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MySQL server version for the right syntax to use near '= sales_order.client_no  inner join sales_order on sales_order.' at line 1
mysql> 
mysql> select product_master.product_no, description from product_master inner join challan_details on challan_details.product_no = product_master.product_no inner join challan_header on challan_header.challan_no = challan_details.challan_no inner join sales_order on sales_order.order_no = challan_header.order_no where sales_order.order_status <> "C" union ;
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MySQL server version for the right syntax to use near '' at line 1
mysql> select product_master.product_no, description from product_master inner join challan_details on challan_details.product_no = product_master.product_no inner join challan_header on challan_header.challan_no = challan_details.challan_no inner join sales_order on sales_order.order_no = challan_header.order_no where sales_order.order_status <> "IP"^C
mysql> 
mysql> select product_master.product_no, description from product_master inner join challan_details on challan_details.product_no = product_master.product_no inner join challan_header on challan_header.challan_no = challan_details.challan_no inner join sales_order on sales_order.order_no = challan_header.order_no where sales_order.order_status = "C" union select product_master.product_no, description from product_master inner join challan_details on challan_details.product_no = product_master.product_no inner join challan_header on challan_header.challan_no = challan_details.challan_no inner join sales_order on sales_order.order_no = challan_header.order_no where sales_order.order_status = "F";
+------------+-------------+
| product_no | description |
+------------+-------------+
| p07868     | Keyboards   |
+------------+-------------+
1 row in set (0.00 sec)

mysql> select client_master.client_no, name from client_master inner join sales_order on client_master.client_no = sales_order.client_no inner join sales_order on sales_order^C
mysql> select name, delivery_add, city, pincode from client_master inner join sales_order on sales_order.client_no = client_master.client_no where sales_order.order_no = '019001' 
    -> ;
ERROR 1054 (42S22): Unknown column 'delivery_add' in 'field list'
mysql> select name, dely_add, city, pincode from client_master inner join sales_order on sales_order.client_no = client_master.client_no where sales_order.order_no = '019001';
+------+-------------+--------+---------+
| name | dely_add    | city   | pincode |
+------+-------------+--------+---------+
| Ivan | A2 Borivali | Bombay |  768003 |
+------+-------------+--------+---------+
1 row in set (0.00 sec)

mysql> select name from client_master inner join sales_order on client_master.client_no = sales_order.client_no;
+---------+
| name    |
+---------+
| Ivan    |
| Ivan    |
| Pramada |
| Basu    |
| Ravi    |
| Rukmini |
+---------+
6 rows in set (0.00 sec)

mysql> select name from client_master inner join sales_order on client_master.client_no = sales_order.client_no where order_date < '1996/05;
    '> ;
    '> '
    -> ;
ERROR 1525 (HY000): Incorrect DATE value: '1996/05;
;
'
mysql> select name from client_master inner join sales_order on client_master.client_no = sales_order.client_no where order_date < '1996/05';
ERROR 1525 (HY000): Incorrect DATE value: '1996/05'
mysql> select name from client_master inner join sales_order on client_master.client_no = sales_order.client_no where order_date < '1996/05/01';
+---------+
| name    |
+---------+
| Pramada |
| Ivan    |
| Rukmini |
| Ivan    |
+---------+
4 rows in set, 1 warning (0.00 sec)

mysql> select name from client_master inner join sales_order on client_master.client_no = sales_order.client_no where order_date < '1996-05-01';
+---------+
| name    |
+---------+
| Pramada |
| Ivan    |
| Rukmini |
| Ivan    |
+---------+
4 rows in set (0.00 sec)

mysql> select name from client_master inner join sales_order on client_master.client_no = sales_order.client_no inner join challan_header on challan_header.order_no = sales_order.order_no inner join challan_details on challan_details.challan_no = challan_header.challan_no inner join product_master on product_master.product_no = challan_details.product_no;
+---------+
| name    |
+---------+
| Ravi    |
| Pramada |
| Ivan    |
+---------+
3 rows in set (0.00 sec)

mysql> select name from client_master inner join sales_order on client_master.client_no = sales_order.client_no inner join challan_header on challan_header.order_no = sales_order.order_no inner join challan_details on challan_details.challan_no = challan_header.challan_no inner join product_master on product_master.product_no = challan_details.product_no where description = "1.44 Drive";
Empty set (0.00 sec)

mysql> select client_master.client_no, name, product_no from client_master inner join sales_order on client_master.client_no = sales_order.client_no inner join challan_header on challan_head
er.order_no = sales_order.order_no inner join challan_details on challan_details.challan_no = challan_header.challan_no inner join product_master on product_master.product_no = challan_detai
ls.product_no where description = "1.44 Drive";
ERROR 1052 (23000): Column 'product_no' in field list is ambiguous
mysql> select client_master.client_no, name, description from client_master inner join sales_order on client_master.client_no = sales_order.client_no inner join challan_header on challan_header.order_no = sales_order.order_no inner join challan_details on challan_details.challan_no = challan_header.challan_no inner join product_master on product_master.product_no = challan_details.product_no where description = "1.44 Drive";
Empty set (0.00 sec)

mysql> select client_master.client_no, name, description from client_master inner join sales_order on client_master.client_no = sales_order.client_no inner join challan_header on challan_header.order_no = sales_order.order_no inner join challan_details on challan_details.challan_no = challan_header.challan_no inner join product_master on product_master.product_no = challan_details.product_no;
+-----------+---------+---------------+
| client_no | name    | description   |
+-----------+---------+---------------+
| 0005      | Ravi    | 1.44 Floppies |
| 0003      | Pramada | Keyboards     |
| 0001      | Ivan    | 1.44 Floppies |
+-----------+---------+---------------+
3 rows in set (0.00 sec)

mysql> select name from client_master inner join sales_order on client_master.client_no = sales_order.client_no inner join challan_header on challan_header.order_no = sales_order.order_no in                                                                                                                                                         ls.product_no where description = "1.44 Drive";
Empty set (0.00 sec)

mysql> select name from client_master inner join sales_order on client_master.client_no = sales_order.client_no inner join challan_header on challan_header.order_no = sales_order.order_no inner join challan_details on challan_details.challan_no = challan_header.challan_no inner join product_master on product_master.product_no = challan_details.product_no where description = "1.44 Drive";
Empty set (0.01 sec)

mysql> select name from client_master inner join sales_order on client_master.client_no = sales_order.client_no inner join sales_order_details on sales_order_details.order_no = sales_order.order_no inner join product_master on product_master.product_no = sales_order_details.product_no;
ERROR 1054 (42S22): Unknown column 'sales_order_details.order_no' in 'on clause'
mysql> select name from client_master inner join sales_order on client_master.client_no = sales_order.client_no inner join sales_order_details on sales_order_details.sale_order_no = sales_order.order_no inner join product_master on product_master.product_no = sales_order_details.product_no;
+---------+
| name    |
+---------+
| Ivan    |
| Ivan    |
| Pramada |
| Basu    |
| Ravi    |
| Rukmini |
+---------+
6 rows in set (0.00 sec)

mysql> select name from client_master inner join sales_order on client_master.client_no = sales_order.client_no inner join sales_order_details on sales_order_details.sale_order_no = sales_order.order_no inner join product_master on product_master.product_no = sales_order_details.product_no where description = "1.44 Drive";
Empty set (0.00 sec)

mysql> select name, description from client_master inner join sales_order on client_master.client_no = sales_order.client_no inner join sales_order_details on sales_order_details.sale_order_
no = sales_order.order_no inner join product_master on product_master.product_no = sales_order_details.product_no;
+---------+---------------+
| name    | description   |
+---------+---------------+
| Ivan    | 1.44 Floppies |
| Ivan    | CD Drive      |
| Pramada | CD Drive      |
| Basu    | 1.44 Floppies |
| Ravi    | 1.44 Floppies |
| Rukmini | 540 HDD       |
+---------+---------------+
6 rows in set (0.00 sec)

mysql> select name from client_master inner join sales_order on sales_order.client_no = client_master.client_no inner join sales_order_details on sales_order_details.sale_order_no = sales_order.order_no where qty_disp * prod_rate > 10000;
+---------+
| name    |
+---------+
| Pramada |
+---------+
1 row in set (0.00 sec)

mysql> select name, qty_disp * prod_rate from client_master inner join sales_order on sales_order.client_no = client_master.client_no inner join sales_order_details on sales_order_details.sa
le_order_no = sales_order.order_no;
+---------+----------------------+
| name    | qty_disp * prod_rate |
+---------+----------------------+
| Ivan    |              2100.00 |
| Ivan    |              5250.00 |
| Pramada |             52500.00 |
| Basu    |              4200.00 |
| Ravi    |              2625.00 |
| Rukmini |              8400.00 |
+---------+----------------------+
6 rows in set (0.00 sec)

mysql> select name from client_master inner join sales_order on sales_order.client_no = client_master.client_no inner join sales_order_details on sales_order_details.sale_order_no = sales_order.order_no where qty_disp * prod_rate > 10000;
+---------+
| name    |
+---------+
| Pramada |
+---------+
1 row in set (0.00 sec)

mysql> select name from client_master inner join sales_order on sales_order.client_no = client_master.client_no where name = "Rahul Desai";
Empty set (0.00 sec)

mysql> select name from client_master where city = "Bombay" union select sales_name from sales_master where city = "Bombay";
+---------+
| name    |
+---------+
| Ivan    |
| Pramada |
| Basu    |
| Ravi    |
| Rukmini |
| Kiran   |
| Manish  |
| Ashish  |
+---------+
8 rows in set (0.00 sec)

mysql> select sales_name from sales_master inner join sales_order on sales_master.salesman_no = sales_order.salesman_no inner join client_master on client_master.client_no = sales_order.client_no;
+------------+
| sales_name |
+------------+
| Kiran      |
| Kiran      |
| Manish     |
| Manish     |
| Ravi       |
| Ashish     |
+------------+
6 rows in set (0.00 sec)

mysql> select sales_name, client_master.city from sales_master inner join sales_order on sales_master.salesman_no = sales_order.salesman_no inner join client_master on client_master.client_n
o = sales_order.client_no;
+------------+--------+
| sales_name | city   |
+------------+--------+
| Kiran      | Bombay |
| Kiran      | Bombay |
| Manish     | Bombay |
| Manish     | Bombay |
| Ravi       | Bombay |
| Ashish     | Bombay |
+------------+--------+
6 rows in set (0.00 sec)

mysql> select sales_name, count(client_master.client_no) from sales_master inner join sales_order on sales_master.salesman_no = sales_order.salesman_no inner join client_master on client_mas
ter.client_no = sales_order.client_no where client_master.city = "Bombay";
ERROR 1140 (42000): In aggregated query without GROUP BY, expression #1 of SELECT list contains nonaggregated column 'university.sales_master.sales_name'; this is incompatible with sql_mode=only_full_group_by
mysql> select sales_name, count(client_master.client_no) from sales_master inner join sales_order on sales_master.salesman_no = sales_order.salesman_no inner join client_master on client_master.client_no = sales_order.client_no where client_master.city = "Bombay" group by sales_name;
+------------+--------------------------------+
| sales_name | count(client_master.client_no) |
+------------+--------------------------------+
| Kiran      |                              2 |
| Ravi       |                              1 |
| Manish     |                              2 |
| Ashish     |                              1 |
+------------+--------------------------------+
4 rows in set (0.00 sec)

mysql> select product_master.product_no, description, qty_on_hand, costprice from product_master inner join challan_details on challan_details.product_no = product_master.product_no inner jo
in challa
n select product_master.product_no, description from product_master inner join challan_details on challan_details.product_no = product_master.product_no inner join challan_header on challan_header.challa
ERROR 1054 (42S22): Unknown column 'qty_on_hand' in 'field list'
mysql> select product_master.product_no, description, quantity_on_hand, costprice from product_master inner join challan_details on challan_details.product_no = product_master.product_no inn
er join challan_header on challan_header.challan_no = challan_details.challan_no inner join sales_order on sales_order.order_no = challan_header.order_no where sales_order.order_status = "C"
 union select product_master.product_no, description from product_master inner join challan_details on challan_details.product_no = product_master.product_no inner join challan_header on challa
ERROR 1222 (21000): The used SELECT statements have a different number of columns
mysql> select product_master.product_no, description, quantity_on_hand, costprice from product_master inner join challan_details on challan_details.product_no = product_master.product_no inner join challan_header on challan_header.challan_no = challan_details.challan_no inner join sales_order on sales_order.order_no = challan_header.order_no where sales_order.order_status = "C" union select product_master.product_no, description, quantity_on_hand, costprice from product_master inner join challan_details on challan_details.product_no = product_master.product_no inn
er join challa
;
+------------+-------------+------------------+-----------+
| product_no | description | quantity_on_hand | costprice |
+------------+-------------+------------------+-----------+
| p07868     | Keyboards   |               10 |   3050.00 |
+------------+-------------+------------------+-----------+
1 row in set (0.01 sec)

mysql> select product_master.product_no, description, quantity_on_hand, costprice from product_master inner join challan_details on challan_details.product_no = product_master.product_no inner join challan_header on challan_header.challan_no = challan_details.challan_no inner join sales_order on sales_order.order_no = challan_header.order_no where sales_order.order_status = "C" union select product_master.product_no, description, quantity_on_hand, costprice from product_master inner join challan_details on challan_details.product_no = product_master.product_no inner join challan_header on challan_header.challan_no = challan_details.challan_no inner join sales_order on sales_order.order_no = challan_header.order_no where sales_order.order_status = "F";
+------------+-------------+------------------+-----------+
| product_no | description | quantity_on_hand | costprice |
+------------+-------------+------------------+-----------+
| p07868     | Keyboards   |               10 |   3050.00 |
+------------+-------------+------------------+-----------+
1 row in set (0.00 sec)

mysql> 

