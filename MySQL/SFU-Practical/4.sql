--4
-- -5а  5b
-- *(b-a)+a 
SELECT COUNT(*) AS TotalDeals FROM Deal;
SELECT AVG(Quantity) AS AverageQuantity FROM Store;
SELECT SUM(Quantity) AS TotalQuantity FROM Store;
SELECT MAX(Quantity) AS MaxQuantity FROM Store;
SELECT COS(RADIANS(60.0)) AS Косинус;
SELECT FLOOR(RAND() * (0.25 + 0.5) - 7) AS интервал;
SELECT DATEPART(dw, GETDATE()) AS "текущий день";


-- select 3.0/4
select ROUND(RAND()*0.5-100.5, 2)
-- -100.5 .. -100

