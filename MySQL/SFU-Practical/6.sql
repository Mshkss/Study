--6


-- 1. Вывести наименования товаров, количество которых на складе максимально (на складе должно быть как минимум два товара, количество которых одинаково и равно максимальному):
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
-- 2. Вывести в порядке, обратном алфавитному, наименования товаров, количество которых на складе находится в заданном диапазоне:
SELECT product_name
FROM products
WHERE quantity BETWEEN 5 AND 10
ORDER BY product_name DESC;

-- 3. Вывести поставщиков, которые хотя бы раз осуществили поставку, в алфавитном порядке:
SELECT supplier_name
FROM suppliers
WHERE supplier_id IN (
    SELECT DISTINCT supplier_id
    FROM purchases
);
ORDER BY supplier_name;

-- 4. 30 дней с даты последней покупки действует дополнительная скидка на все товары. Вывести список покупателей, имеющих возможность воспользоваться указанной скидкой:
SELECT customer_name
FROM customers
WHERE DATEDIFF(NOW(), (SELECT MAX(purchase_date) FROM purchases WHERE customer_id = customers.customer_id)) <= 30;

-- 5. Вывести список товаров, названия которых начинаются с букв «д» и «л», стоимость которых не более 20% от максимальной:
SELECT product_name
FROM products
WHERE (product_name LIKE 'Д%' OR product_name LIKE 'Л%') AND price <= 0.2 * (SELECT MAX(price) FROM products);

-- 6. Вывести поставщиков, которые не поставляют товары, названия которых начинаются с букв «д» и «л»:
SELECT supplier_name
FROM suppliers
WHERE supplier_id NOT IN (
    SELECT DISTINCT supplier_id
    FROM products
    WHERE product_name LIKE 'Д%' OR product_name LIKE 'Л%'
);

-- 7. Показать список клиентов с указанием их пола («мужчина» или «женщина»):
SELECT customer_name, 
       CASE 
           WHEN gender = 'M' THEN 'мужчина'
           WHEN gender = 'F' THEN 'женщина'
           ELSE 'не указан'
       END AS gender_description
FROM customers;
*/