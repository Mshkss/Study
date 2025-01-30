--5
SELECT Name FROM Provider ORDER BY Name ASC;

SELECT TOP 1 Name FROM Provider ORDER BY LEN(Name) DESC;

SELECT Name FROM Client WHERE Name LIKE 'Ò%'

SELECT * FROM Client WHERE Name LIKE '[Ì-ß]î%'

SELECT COUNT(*) AS TotalDeals FROM Deal WHERE MONTH(Date) = MONTH(GETDATE()) and year(date) = year(getdate());

SELECT COUNT(*) AS TotalDeals FROM Deal WHERE DATEPART(dw, Date) IN (2, 3);
