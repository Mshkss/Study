-- 1. Ранжируйте сотрудников по объемам продаж и выведите тройку лидеров.
SELECT TOP 3
	Employee.Name as Сотрудник, 
	SUM(Deal.Quantity * Store.Price) as [Сумма сделок],
	dense_RANK() OVER (ORDER BY SUM(Deal.Quantity * Store.Price) DESC) as [Занятое место]
	FROM Employee
		JOIN Deal ON Employee.ID = Deal.ID_Employee
		JOIN Store ON Store.ID = Deal.ID_Store
		GROUP BY Employee.Name;

-- 2. Вывести суммы сделок по месяцам для каждого сотрудника и показать разницу с
--  предыдущим месяцем, в котором были зафиксированы сделки.

SELECT
	Employee.Name as Сотрудник,
	YEAR(Deal.Date) as Год,
	DATENAME (MONTH, Deal.Date) as Месяц,
	SUM(Deal.Quantity * Store.Price) as [Сумма сделок],
	SUM(Deal.Quantity * Store.Price)-(LAG(SUM(Deal.Quantity * Store.Price), 1, 0) OVER
	(PARTITION BY Employee.Name ORDER BY Employee.Name, YEAR(Deal.Date), DATENAME(MONTH, Deal.Date))) as [Разница с предыдущим]
	FROM Employee 
		JOIN Deal ON Employee.ID = Deal.ID_Employee
		JOIN Store ON Deal.ID_Store = Store.ID
		GROUP BY Employee.Name, YEAR(Deal.Date), DATENAME(MONTH, Deal.Date);