<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title><?php echo $pageData['title']; ?></title>
    <link rel="stylesheet" href="/public/css/products.css"> <!-- Подключение CSS файла -->
</head>
<body>
<div class="container">
    <header>
        <h1>Товары по категориям</h1>
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
        <?php foreach ($pageData['categories'] as $category) { ?>
            <section class="category">
                <h2><?php echo $category['categoriesName']; ?></h2>
                <div class="products">
                    <?php if (isset($pageData['products'][$category['categoriesID']])) {
                        foreach ($pageData['products'][$category['categoriesID']] as $product) {
                            $productId = $product['productID'];
                            $quantity = isset($pageData['cart'][$productId]) ? $pageData['cart'][$productId] : 0;
                            ?>
                            <div class="product" data-product-id="<?php echo $productId; ?>">
                                <h3><?php echo $product['productName']; ?></h3>
                                <p><?php echo $product['productDescription']; ?></p>
                                <p class="price"><?php echo $product['productPrice']; ?> руб.</p>
                                <button class="buy-button" style="<?php echo $quantity > 0 ? 'display: none;' : ''; ?>">Купить</button>
                                <div class="quantity-controls" style="<?php echo $quantity > 0 ? 'display: flex;' : 'display: none;'; ?>">
                                    <button class="decrease">-</button>
                                    <span class="quantity"><?php echo $quantity > 0 ? $quantity : 1; ?> шт</span>
                                    <button class="increase">+</button>
                                </div>
                            </div>
                        <?php }
                    } ?>
                </div>
            </section>
        <?php } ?>
    </main>

    <footer>
        <p>&copy; 2024 Интернет-магазин</p>
    </footer>

</div>

<script src="/public/js/products.tpl.js"></script> <!-- Подключение JS файла -->
</body>
</html>