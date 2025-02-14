<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title><?php echo $pageData['title']; ?></title>
    <link rel="stylesheet" href="/public/css/cabinet.tpl.css"> <!-- Подключение CSS файла -->
</head>
<body>
<div class="container">
    <header>
        <h1>Корзина</h1>
    </header>

    <nav>
        <ul>
            <li><a href="/products">Магазин</a></li>
            <li><a href="/cabinet">Личный кабинет</a></li>
            <li><a href="/cart">Корзина</a></li>
            <li><a href="/admin">Админ-панель</a></li>
            <li><a href="/cabinet/logout">Выйти</a></li>
        </ul>
    </nav>

    <main>
        <h2>Ваши товары</h2>
        <?php if (!empty($pageData['cart'])) { ?>
            <table>
                <thead>
                <tr>
                    <th>Название</th>
                    <th>Описание</th>
                    <th>Цена</th>
                    <th>Количество</th>
                    <th>Действия</th>
                </tr>
                </thead>
                <tbody>
                <?php foreach ($pageData['cart'] as $productId => $quantity) {
                    $product = $pageData['products'][$productId]; ?>
                    <tr>
                        <td><?php echo $product['productName']; ?></td>
                        <td><?php echo $product['productDescription']; ?></td>
                        <td><?php echo $product['productPrice']; ?> руб.</td>
                        <td><?php echo $quantity; ?> шт</td>
                        <td>
                            <button class="remove-button" data-product-id="<?php echo $productId; ?>">Удалить</button>
                        </td>
                    </tr>
                <?php } ?>
                </tbody>
            </table>
            <button id="place-order-button">Оформить заказ</button>
        <?php } else { ?>
            <p>Ваша корзина пуста.</p>
        <?php } ?>
    </main>

    <footer>
        <p>&copy; 2024 Интернет-магазин</p>
    </footer>
</div>

<script src="/public/js/cart.js"></script> <!-- Подключение JS файла -->
</body>
</html>