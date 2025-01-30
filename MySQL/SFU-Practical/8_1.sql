-- 8.1

-- Провести оценку количества товара на складе по наименованиям: менее 10 – мало,
-- от 10 до 100 – достаточно, более 100 – избыточно.
SELECT
	Product.Name as Наименование,
	SUM(Store.Quantity) as Количество,
	CASE
		when SUM(Store.Quantity) < 10 and SUM(Store.Quantity) >= 0 then 'Мало'
		when SUM(Store.Quantity) between  10 and 100 then 'Достаточно'
		when SUM(Store.Quantity) > 100 then 'Избыточно'
		else 'Неверные данные'
	end as Оценка
	from Product join Store on Store.ID_product = Product.ID
	GROUP BY Product.Name;

--Вывести наименования товаров, количество которых на складе от 1 до 10(21)
SELECT
	Product.Name as Наименование,
	SUM(Store.Quantity) as Количество
	from Product join Store on Store.ID_Product = Product.ID
	GROUP BY Product.Name
	HAVING SUM(Store.Quantity) BETWEEN 1 and 21;

--Определить тройку товаров, выручка за которые самая большая.
SELECT TOP 3
	Product.Name as Наименование,
	SUM(Deal.Quantity * Store.Price) as Сумма
	from Store 
		join Product on Store.ID_Product = Product.ID 
		join Deal on Store.ID = Deal.ID_Store
		GROUP BY Product.Name
		ORDER BY Сумма DESC

--Определить суммарную стоимость продаж каждого товара по месяцам.
-- отсортировать по нормальному
SELECT 
	Product.Name as Товар,
	year(Deal.Date) as Год,
	DATENAME(MONTH, Deal.Date) as Месяц,
	SUM(Deal.Quantity * Store.Price) as Сумма
	FROM product
		join Store on Product.ID = Store.ID_Product
		join Deal on Deal.ID_Store = Store.ID
		 GROUP BY Product.Name, year(Deal.date), DATENAME(MONTH, Deal.Date), DATEPART(MONTH, Deal.Date)
		ORDER BY Товар,year(Deal.Date), DATEPART(MONTH, Deal.Date);

--Показать месяца, в которых продажи Молока 3,2% (или любого другого товара,
--хранящегося на складе с разными ID) были ниже 300 денег.
SELECT
	Product.Name AS Товар,
	DATENAME(MONTH, Deal.Date) as Месяц,
	SUM(Deal.Quantity * Store.Price) as Сумма
	FROM Product
		JOIN Store ON Product.ID = Store.ID_Product
		JOIN Deal ON Deal.ID_Store = Store.ID
		WHERE Product.ID = 1
			GROUP BY Product.Name, year(Deal.Date), DATENAME(MONTH, Deal.Date)
			HAVING SUM(Deal.Quantity * Store.Price) < 300
			ORDER BY Сумма DESC;