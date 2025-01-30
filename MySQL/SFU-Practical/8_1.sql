-- 8.1

-- �������� ������ ���������� ������ �� ������ �� �������������: ����� 10 � ����,
-- �� 10 �� 100 � ����������, ����� 100 � ���������.
SELECT
	Product.Name as ������������,
	SUM(Store.Quantity) as ����������,
	CASE
		when SUM(Store.Quantity) < 10 and SUM(Store.Quantity) >= 0 then '����'
		when SUM(Store.Quantity) between  10 and 100 then '����������'
		when SUM(Store.Quantity) > 100 then '���������'
		else '�������� ������'
	end as ������
	from Product join Store on Store.ID_product = Product.ID
	GROUP BY Product.Name;

--������� ������������ �������, ���������� ������� �� ������ �� 1 �� 10(21)
SELECT
	Product.Name as ������������,
	SUM(Store.Quantity) as ����������
	from Product join Store on Store.ID_Product = Product.ID
	GROUP BY Product.Name
	HAVING SUM(Store.Quantity) BETWEEN 1 and 21;

--���������� ������ �������, ������� �� ������� ����� �������.
SELECT TOP 3
	Product.Name as ������������,
	SUM(Deal.Quantity * Store.Price) as �����
	from Store 
		join Product on Store.ID_Product = Product.ID 
		join Deal on Store.ID = Deal.ID_Store
		GROUP BY Product.Name
		ORDER BY ����� DESC

--���������� ��������� ��������� ������ ������� ������ �� �������.
-- ������������� �� �����������
SELECT 
	Product.Name as �����,
	year(Deal.Date) as ���,
	DATENAME(MONTH, Deal.Date) as �����,
	SUM(Deal.Quantity * Store.Price) as �����
	FROM product
		join Store on Product.ID = Store.ID_Product
		join Deal on Deal.ID_Store = Store.ID
		 GROUP BY Product.Name, year(Deal.date), DATENAME(MONTH, Deal.Date), DATEPART(MONTH, Deal.Date)
		ORDER BY �����,year(Deal.Date), DATEPART(MONTH, Deal.Date);

--�������� ������, � ������� ������� ������ 3,2% (��� ������ ������� ������,
--����������� �� ������ � ������� ID) ���� ���� 300 �����.
SELECT
	Product.Name AS �����,
	DATENAME(MONTH, Deal.Date) as �����,
	SUM(Deal.Quantity * Store.Price) as �����
	FROM Product
		JOIN Store ON Product.ID = Store.ID_Product
		JOIN Deal ON Deal.ID_Store = Store.ID
		WHERE Product.ID = 1
			GROUP BY Product.Name, year(Deal.Date), DATENAME(MONTH, Deal.Date)
			HAVING SUM(Deal.Quantity * Store.Price) < 300
			ORDER BY ����� DESC;