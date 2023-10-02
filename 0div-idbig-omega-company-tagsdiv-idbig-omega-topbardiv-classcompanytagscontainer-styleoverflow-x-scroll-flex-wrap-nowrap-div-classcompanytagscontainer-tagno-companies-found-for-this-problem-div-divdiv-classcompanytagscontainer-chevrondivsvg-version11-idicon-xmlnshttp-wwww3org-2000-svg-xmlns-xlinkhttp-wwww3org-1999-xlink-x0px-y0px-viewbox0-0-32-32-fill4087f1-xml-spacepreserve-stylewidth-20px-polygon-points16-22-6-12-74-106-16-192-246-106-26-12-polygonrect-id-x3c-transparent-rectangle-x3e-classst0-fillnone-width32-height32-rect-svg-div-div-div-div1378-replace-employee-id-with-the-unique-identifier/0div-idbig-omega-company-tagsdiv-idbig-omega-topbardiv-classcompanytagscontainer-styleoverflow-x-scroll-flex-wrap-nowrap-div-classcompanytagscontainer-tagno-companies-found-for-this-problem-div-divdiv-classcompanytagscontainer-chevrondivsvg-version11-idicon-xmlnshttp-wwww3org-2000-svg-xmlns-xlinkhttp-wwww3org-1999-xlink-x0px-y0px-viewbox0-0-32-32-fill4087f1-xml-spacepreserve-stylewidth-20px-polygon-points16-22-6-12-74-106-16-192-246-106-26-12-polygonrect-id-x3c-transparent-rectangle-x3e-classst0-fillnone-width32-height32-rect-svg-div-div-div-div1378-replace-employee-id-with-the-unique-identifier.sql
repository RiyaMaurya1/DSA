# Write your MySQL query statement below
Select name, EmployeeUNI.unique_id 
From Employees 
Left Join EmployeeUNI on EmployeeUNI.id = Employees.id;