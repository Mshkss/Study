SELECT
	Product.Name as �����,
	Provider.Name as ���������
		from Store
			join Provider on Provider.ID = Store.ID_Provider
			join Product on Product.ID = Store.ID_Product;
SELECT
	Product.Name as �����,
	Provider.Name as ���������,
	Store.Quantity as ����������
		from Product
			LEFT join Store on Product.ID = Store.ID_Product
			LEFT join Provider on Provider.ID = Store.ID_Provider;
SELECT
	Product.Name as �����,
	isnull (Client.Name, '�� ��������') as ����������,
	isnull (CAST(Deal.Quantity as nvarchar), '��� ������') as ����������
		from Client
			right join Deal on Client.ID = ID_Client 
			RIGHT join Store on Deal.ID_Store = Store.ID    
			   join Product on ID_product = Product.ID;       --- ������??
SELECT
	Provider.Name from Provider
		join Store on Provider.ID = Store.ID_Provider

SELECT 
	E2.Name as ���������,
	isnull (E1.Name, '�� ��������') as ���������
		from Employee E2
			left join Employee E1 on E2.ID_Manager = E1.ID;