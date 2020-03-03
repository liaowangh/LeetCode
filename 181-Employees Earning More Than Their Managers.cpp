# Write your MySQL query statement below
# SELECT E1.Name as Employee
# FROM Employee E1, Employee E2
# WHERE E1.ManagerId = E2.Id AND E1.Salary > E2.Salary;

# SELECT E1.Name as Employee
# FROM Employee E1 JOIN Employee E2 ON
#     E1.ManagerId = E2.Id AND E1.Salary > E2.Salary;

SELECT E1.Name as Employee
FROM Employee E1 INNER JOIN Employee E2 ON
    E1.ManagerId = E2.ID
WHERE E1.Salary > E2.Salary
