# Write your MySQL query statement below
# SELECT Name as Customers
# FROM Customers LEFT JOIN Orders ON
#     Customers.Id = Orders.CustomerId;
# WHERE Orders.CustomerId IS NULL;

SELECT Name AS Customers
FROM Customers c LEFT JOIN Orders o ON
    c.Id = o.CustomerID
WHERE o.CustomerId is NULL;
