SELECT
	Product.Name as Товар,
	Provider.Name as Поставщик
		from Store
			join Provider on Provider.ID = Store.ID_Provider
			join Product on Product.ID = Store.ID_Product;
SELECT
	Product.Name as Товар,
	Provider.Name as Поставщик,
	Store.Quantity as Количество
		from Product
			LEFT join Store on Product.ID = Store.ID_Product
			LEFT join Provider on Provider.ID = Store.ID_Provider;
SELECT
	Product.Name as Товар,
	isnull (Client.Name, 'Не определён') as Покупатель,
	isnull (CAST(Deal.Quantity as nvarchar), 'Нет продаж') as Количество
		from Client
			right join Deal on Client.ID = ID_Client 
			RIGHT join Store on Deal.ID_Store = Store.ID    
			   join Product on ID_product = Product.ID;       --- почему??
SELECT
	Provider.Name from Provider
		join Store on Provider.ID = Store.ID_Provider

SELECT 
	E2.Name as Сотрудник,
	isnull (E1.Name, 'Не определён') as Начальник
		from Employee E2
			left join Employee E1 on E2.ID_Manager = E1.ID;