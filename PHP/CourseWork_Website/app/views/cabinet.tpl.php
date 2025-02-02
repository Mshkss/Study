<?php
//echo "<pre>";
//echo $pageData['ordersCount'];
//print_r($pageData);
//echo "</pre>";
//?>

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
        <h1>Добро пожаловать в личный кабинет, <?php echo $pageData['userNameCabinet']; ?>!</h1>
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
        <!-- Личная информация -->
        <section id="personal-info">
            <h2>Личная информация</h2>
            <p>Имя: <?php echo $pageData['userNameCabinet']; ?></p>
            <p>Электронная почта: [Электронная почта]</p>
            <p>Телефон: [Телефон]</p>
            <p>Адрес доставки: [Адрес доставки]</p>
            <button>Редактировать</button>
        </section>

        <!-- История заказов -->
        <section id="orders">
            <h2>История заказов</h2>
            <table>
                <thead>
                <tr>
                    <th>Номер заказа</th>
                    <th>Дата</th>
                    <th>Статус</th>
                    <th>Сумма</th>
                    <th>Действия</th>
                </tr>
                </thead>
                <tbody>
                <?php foreach ($pageData['orders'] as $key => $value){
                    echo "<tr>";
                    echo "<td>" . $value['id'] . "</td>";
                    echo "<td>" . $value['date'] . "</td>";
                    echo "<td>" . $value['status'] . "</td>";
                    echo "<td>" . $value['total_price'] . " руб</td>";
                    echo "<td><button>Просмотр</button></td>";
                    echo "</tr>";
                }
                ?>
                <!-- Другие заказы -->
                </tbody>
            </table>
        </section>
    </main>
    <footer>
        <p>&copy; 2024 Интернет-магазин</p>
    </footer>
</div>
</body>
</html>