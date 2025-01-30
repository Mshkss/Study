--6


-- 1. ������� ������������ �������, ���������� ������� �� ������ ����������� (�� ������ ������ ���� ��� ������� ��� ������, ���������� ������� ��������� � ����� �������������):
SELECT p.NAME
FROM product p
JOIN store s ON p.ID = s.ID_PRODUCT
WHERE s.QUANTITY = (
    SELECT MAX(QUANTITY)
    FROM store
    WHERE ID_PRODUCT = s.ID_PRODUCT
    GROUP BY ID_PRODUCT
    HAVING COUNT(*) >= 2
);


/*
-- 2. ������� � �������, �������� �����������, ������������ �������, ���������� ������� �� ������ ��������� � �������� ���������:
SELECT product_name
FROM products
WHERE quantity BETWEEN 5 AND 10
ORDER BY product_name DESC;

-- 3. ������� �����������, ������� ���� �� ��� ����������� ��������, � ���������� �������:
SELECT supplier_name
FROM suppliers
WHERE supplier_id IN (
    SELECT DISTINCT supplier_id
    FROM purchases
);
ORDER BY supplier_name;

-- 4. 30 ���� � ���� ��������� ������� ��������� �������������� ������ �� ��� ������. ������� ������ �����������, ������� ����������� ��������������� ��������� �������:
SELECT customer_name
FROM customers
WHERE DATEDIFF(NOW(), (SELECT MAX(purchase_date) FROM purchases WHERE customer_id = customers.customer_id)) <= 30;

-- 5. ������� ������ �������, �������� ������� ���������� � ���� �� � ��, ��������� ������� �� ����� 20% �� ������������:
SELECT product_name
FROM products
WHERE (product_name LIKE '�%' OR product_name LIKE '�%') AND price <= 0.2 * (SELECT MAX(price) FROM products);

-- 6. ������� �����������, ������� �� ���������� ������, �������� ������� ���������� � ���� �� � ��:
SELECT supplier_name
FROM suppliers
WHERE supplier_id NOT IN (
    SELECT DISTINCT supplier_id
    FROM products
    WHERE product_name LIKE '�%' OR product_name LIKE '�%'
);

-- 7. �������� ������ �������� � ��������� �� ���� (�������� ��� ��������):
SELECT customer_name, 
       CASE 
           WHEN gender = 'M' THEN '�������'
           WHEN gender = 'F' THEN '�������'
           ELSE '�� ������'
       END AS gender_description
FROM customers;
*/