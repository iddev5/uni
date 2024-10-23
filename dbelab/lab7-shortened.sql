create table sales_order_details( 
    sale_order_no varchar(6) primary key, 
    product_no varchar(6), qty_ord integer(8), 
    qty_disp integer(8), prod_rate decimal(10, 2), 
    foreign key (sale_order_no) references sales_order(order_no), 
    foreign key (product_no) references product_master(product_no) 
);
Query OK, 0 rows affected, 2 warnings (0.05 sec)

1)

(select product_master.product_no, description from product_master 
inner join challan_details on challan_details.product_no = product_master.product_no 
inner join challan_header on challan_header.challan_no = challan_details.challan_no 
inner join sales_order on sales_order.order_no = challan_header.order_no 
where sales_order.order_status = "C") 
union 
(select product_master.product_no, description from product_master 
inner join challan_details on challan_details.product_no = product_master.product_no 
inner join challan_header on challan_header.challan_no = challan_details.challan_no 
inner join sales_order on sales_order.order_no = challan_header.order_no 
where sales_order.order_status = "F");
+------------+-------------+
| product_no | description |
+------------+-------------+
| p07868     | Keyboards   |
+------------+-------------+
1 row in set (0.00 sec)


2)

select name, dely_add, city, pincode from client_master 
inner join sales_order on sales_order.client_no = client_master.client_no 
where sales_order.order_no = '019001';

+------+-------------+--------+---------+
| name | dely_add    | city   | pincode |
+------+-------------+--------+---------+
| Ivan | A2 Borivali | Bombay |  768003 |
+------+-------------+--------+---------+
1 row in set (0.00 sec)


3)

select name from client_master 
inner join sales_order on client_master.client_no = sales_order.client_no 
where order_date < '1996/05/01';
+---------+
| name    |
+---------+
| Pramada |
| Ivan    |
| Rukmini |
| Ivan    |
+---------+
4 rows in set, 1 warning (0.00 sec)


4)

select name from client_master 
inner join sales_order on client_master.client_no = sales_order.client_no 
inner join sales_order_details on sales_order_details.sale_order_no = sales_order.order_no 
inner join product_master on product_master.product_no = sales_order_details.product_no 
where description = "1.44 Drive";
Empty set (0.00 sec)

5)

select name from client_master 
inner join sales_order on sales_order.client_no = client_master.client_no 
inner join sales_order_details on sales_order_details.sale_order_no = sales_order.order_no 
where qty_ord * prod_rate > 10000;

+---------+
| name    |
+---------+
| Ivan    |
| Pramada |
| Rukmini |
+---------+

6)

select name from client_master 
inner join sales_order on sales_order.client_no = client_master.client_no 
where name = "Rahul Desai";
Empty set (0.00 sec)

7)

Removed

8)

(select name from client_master where city = "Bombay") 
    union 
(select sales_name from sales_master where city = "Bombay");
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


9)

select sales_name, count(client_master.client_no) from sales_master 
inner join sales_order on sales_master.salesman_no = sales_order.salesman_no 
inner join client_master on client_master.client_no = sales_order.client_no 
where client_master.city = "Bombay" group by sales_name;
+------------+--------------------------------+
| sales_name | count(client_master.client_no) |
+------------+--------------------------------+
| Kiran      |                              2 |
| Ravi       |                              1 |
| Manish     |                              2 |
| Ashish     |                              1 |
+------------+--------------------------------+
4 rows in set (0.00 sec)


10)

(select product_master.product_no, description, quantity_on_hand, costprice from product_master 
inner join challan_details on challan_details.product_no = product_master.product_no 
inner join challan_header on challan_header.challan_no = challan_details.challan_no 
inner join sales_order on sales_order.order_no = challan_header.order_no 
where sales_order.order_status = "C") 
    union 
(select product_master.product_no, description, quantity_on_hand, costprice from product_master 
inner join challan_details on challan_details.product_no = product_master.product_no 
inner join challan_header on challan_header.challan_no = challan_details.challan_no 
inner join sales_order on sales_order.order_no = challan_header.order_no 
where sales_order.order_status = "F");
+------------+-------------+------------------+-----------+
| product_no | description | quantity_on_hand | costprice |
+------------+-------------+------------------+-----------+
| p07868     | Keyboards   |               10 |   3050.00 |
+------------+-------------+------------------+-----------+
1 row in set (0.00 sec)


