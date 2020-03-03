# Write your MySQL query statement below
# SELECT MAX(Salary) as SecondHighestSalary
# From
#     (SELECT E1.Id Id, E1.Salary Salary
#      FROM Employee E1, Employee E2
#      WHERE E1.Salary < E2.Salary) Employee2

SELECT MAX(Salary) as SecondHighestSalary
FROM Employee
WHERE Salary <
    (SELECT MAX(Salary)
    FROM Employee);
