/*
Given an employee table, find all managers with at least 5 direct reports.

+------+----------+-----------+----------+
|Id    |Name 	  |Department |ManagerId |
+------+----------+-----------+----------+
|101   |John 	  |A 	      |null      |
|102   |Dan 	  |A 	      |101       |
|103   |James 	  |A 	      |101       |
|104   |Amy 	  |A 	      |101       |
|105   |Anne 	  |A 	      |101       |
|106   |Ron 	  |B 	      |101       |
+------+----------+-----------+----------+
Given the Employee table, write a SQL query that finds out employees who are reported directly by at least 5 employees, for the above table, your SQL query should return
+-------+
| Name  |
+-------+
| John  |
+-------+
No one would report to himself.
*/

# Write your MySQL query statement below
