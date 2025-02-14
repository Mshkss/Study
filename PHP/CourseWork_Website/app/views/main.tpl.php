<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title><?php echo $pageData['title']; ?></title>
    <link rel="stylesheet" href="/public/css/main.tpl.css">
</head>
<body>
<div class="container">
    <form id="loginForm" method="POST">
        <label for="username">Имя пользователя:</label>
        <input type="text" id="login" name="login" required>
        <br>
        <label for="password">Пароль:</label>
        <input type="password" id="password" name="password" required>
        <br>
        <button type="submit">Войти</button>
    </form>
    <footer>
        <p>&copy; 2024 Интернет-магазин "Астафьева"</p>
    </footer>
</div>
</body>
</html>