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
        <h1>Админ-панель</h1>
    </header>

    <nav>
        <ul>
            <li><a href="#users">Пользователи</a></li>
            <li><a href="#products">Товары</a></li>
            <li><a href="#categories">Категории</a></li>
            <li><a href="/cabinet">Личный кабинет</a></li>
            <li><a href="/cabinet/logout">Выйти</a></li>
        </ul>
    </nav>

    <main>
        <!-- Таблица пользователей -->
        <section id="users">
            <h2>Пользователи</h2>
            <table>
                <thead>
                <tr>
                    <th>ID</th>
                    <th>Имя пользователя</th>
                    <th>Хэш пароля</th>
                    <th>Электронная почта</th>
                    <th>Адрес доставки</th>
                    <th>Телефон</th>
                    <th>Админ</th>
                    <th>Действия</th>
                </tr>
                </thead>
                <tbody>
                <?php foreach ($pageData['userList'] as $user) {
                    echo "<tr>";
                    echo "<td>{$user['id']}</td>";
                    echo "<td>{$user['username']}</td>";
                    echo "<td>{$user['password_hash']}</td>";
                    echo "<td>{$user['email']}</td>";
                    echo "<td>{$user['shipping_address']}</td>";
                    echo "<td>{$user['phone']}</td>";
                    echo "<td>{$user['isadmin']}</td>";
                    echo "<td><button>Изменить</button> <button>Удалить</button></td>";
                    echo "</tr>";
                } ?>
                </tbody>
            </table>
            <h3>Изменение пользователя</h3>
            <form method="POST" action="/admin/updateUser">
                <input type="hidden" name="id" value="">
                <label for="username">Имя пользователя:</label>
                <input type="text" id="username" name="username" required>
                <label for="password_hash">Хэш пароля:</label>
                <input type="text" id="password_hash" name="password_hash" required>
                <label for="email">Электронная почта:</label>
                <input type="email" id="email" name="email" required>
                <label for="shipping_address">Адрес доставки:</label>
                <input type="text" id="shipping_address" name="shipping_address" required>
                <label for="phone">Телефон:</label>
                <input type="text" id="phone" name="phone" required>
                <label for="isadmin">Админ:</label>
                <input type="checkbox" id="isadmin" name="isadmin">
                <button type="submit">Сохранить</button>
            </form>
            <h3>Добавление нового пользователя</h3>
            <form method="POST" action="/admin/addUser">
                <label for="new_username">Имя пользователя:</label>
                <input type="text" id="new_username" name="username" required>
                <label for="new_password_hash">Хэш пароля:</label>
                <input type="text" id="new_password_hash" name="password_hash" required>
                <label for="new_email">Электронная почта:</label>
                <input type="email" id="new_email" name="email" required>
                <label for="new_shipping_address">Адрес доставки:</label>
                <input type="text" id="new_shipping_address" name="shipping_address" required>
                <label for="new_phone">Телефон:</label>
                <input type="text" id="new_phone" name="phone" required>
                <label for="new_isadmin">Админ:</label>
                <input type="checkbox" id="new_isadmin" name="isadmin">
                <button type="submit">Добавить</button>
            </form>
        </section>

        <!-- Таблица товаров -->
        <section id="products">
            <h2>Товары</h2>
            <table>
                <thead>
                <tr>
                    <th>ID</th>
                    <th>Название</th>
                    <th>Описание</th>
                    <th>Цена</th>
                    <th>ID категории</th>
                    <th>Ссылка на изображение</th>
                    <th>Действия</th>
                </tr>
                </thead>
                <tbody>
                <?php foreach ($pageData['productList'] as $product) {
                    echo "<tr>";
                    echo "<td>{$product['id']}</td>";
                    echo "<td>{$product['name']}</td>";
                    echo "<td>{$product['description']}</td>";
                    echo "<td>{$product['price']}</td>";
                    echo "<td>{$product['category_id']}</td>";
                    echo "<td>{$product['image_link']}</td>";
                    echo "<td><button>Изменить</button> <button>Удалить</button></td>";
                    echo "</tr>";
                } ?>
                </tbody>
            </table>
            <h3>Изменение товара</h3>
            <form method="POST" action="/admin/updateProduct">
                <input type="hidden" name="id" value="">
                <label for="product_name">Название:</label>
                <input type="text" id="product_name" name="name" required>
                <label for="description">Описание:</label>
                <input type="text" id="description" name="description" required>
                <label for="price">Цена:</label>
                <input type="number" id="price" name="price" required>
                <label for="category_id">ID категории:</label>
                <input type="number" id="category_id" name="category_id" required>
                <label for="image_link">Ссылка на изображение:</label>
                <input type="text" id="image_link" name="image_link" required>
                <button type="submit">Сохранить</button>
            </form>
            <h3>Добавление нового товара</h3>
            <form method="POST" action="/admin/addProduct">
                <label for="new_product_name">Название:</label>
                <input type="text" id="new_product_name" name="name" required>
                <label for="new_description">Описание:</label>
                <input type="text" id="new_description" name="description" required>
                <label for="new_price">Цена:</label>
                <input type="number" id="new_price" name="price" required>
                <label for="new_category_id">ID категории:</label>
                <input type="number" id="new_category_id" name="category_id" required>
                <label for="new_image_link">Ссылка на изображение:</label>
                <input type="text" id="new_image_link" name="image_link" required>
                <button type="submit">Добавить</button>
            </form>
        </section>

        <!-- Таблица категорий -->
        <section id="categories">
            <h2>Категории</h2>
            <table>
                <thead>
                <tr>
                    <th>ID</th>
                    <th>Название</th>
                    <th>Действия</th>
                </tr>
                </thead>
                <tbody>
                <?php foreach ($pageData['categoryList'] as $category) {
                    echo "<tr>";
                    echo "<td>{$category['id']}</td>";
                    echo "<td>{$category['name']}</td>";
                    echo "<td><button>Изменить</button> <button>Удалить</button></td>";
                    echo "</tr>";
                } ?>
                </tbody>
            </table>
            <h3>Изменение категории</h3>
            <form method="POST" action="/admin/updateCategory">
                <input type="hidden" name="id" value="">
                <label for="category_name">Название:</label>
                <input type="text" id="category_name" name="name" required>
                <button type="submit">Сохранить</button>
            </form>
            <h3>Добавление новой категории</h3>
            <form method="POST" action="/admin/addCategory">
                <label for="new_category_name">Название:</label>
                <input type="text" id="new_category_name" name="name" required>
                <button type="submit">Добавить</button>
            </form>
        </section>
    </main>

    <footer>
        <p>&copy; 2024 Интернет-магазин