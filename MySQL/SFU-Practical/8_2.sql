-- 1. ���������� ����������� �� ������� ������ � �������� ������ �������.
SELECT TOP 3
	Employee.Name as ���������, 
	SUM(Deal.Quantity * Store.Price) as [����� ������],
	dense_RANK() OVER (ORDER BY SUM(Deal.Quantity * Store.Price) DESC) as [������� �����]
	FROM Employee
		JOIN Deal ON Employee.ID = Deal.ID_Employee
		JOIN Store ON Store.ID = Deal.ID_Store
		GROUP BY Employee.Name;

-- 2. ������� ����� ������ �� ������� ��� ������� ���������� � �������� ������� �
--  ���������� �������, � ������� ���� ������������� ������.

SELECT
	Employee.Name as ���������,
	YEAR(Deal.Date) as ���,
	DATENAME (MONTH, Deal.Date) as �����,
	SUM(Deal.Quantity * Store.Price) as [����� ������],
	SUM(Deal.Quantity * Store.Price)-(LAG(SUM(Deal.Quantity * Store.Price), 1, 0) OVER
	(PARTITION BY Employee.Name ORDER BY Employee.Name, YEAR(Deal.Date), DATENAME(MONTH, Deal.Date))) as [������� � ����������]
	FROM Employee 
		JOIN Deal ON Employee.ID = Deal.ID_Employee
		JOIN Store ON Deal.ID_Store = Store.ID
		GROUP BY Employee.Name, YEAR(Deal.Date), DATENAME(MONTH, Deal.Date);