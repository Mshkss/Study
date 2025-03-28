const http = require("http"); // Подключаем модуль http
const fs = require("fs"); // Подключаем модуль fs для работы с файлами
const path = require("path"); // Подключаем модуль path для работы с путями
const url = require("url"); // Подключаем модуль url

const server = http.createServer((req, res) => {
  const parsedUrl = url.parse(req.url, true);

  // Устанавливаем заголовки по умолчанию
  //res.writeHead(200, { "Content-Type": "text/plain" });

  // Обработка разных URL
  if (parsedUrl.pathname === "/") {
    // Главная страница с текстом
    res.end("Welcome to the homepage!\n");
  } else if (parsedUrl.pathname === "/about") {
    // Страница 'О нас'
    res.end("This is the about page.\n");
  } else if (parsedUrl.pathname === "/contact") {
    // Страница с контактной информацией
    res.end("You can reach us at contact@domain.com\n");
  } else if (parsedUrl.pathname === "/greet") {
    // Приветственная страница с параметром
    const name = parsedUrl.query.name || "Guest"; // Если параметра 'name' нет, использовать 'Guest'
    res.end(`Hello, ${name}!\n`);
  } else if (parsedUrl.pathname === "/file") {
    // Выдача HTML файла
    const filePath = path.join(__dirname, "index.html"); // Путь к файлу
    fs.readFile(filePath, (err, data) => {
      if (err) {
        res.writeHead(500, { "Content-Type": "text/plain" });
        res.end("Error reading file.\n");
      } else {
        res.writeHead(200, { "Content-Type": "text/html" });
        res.end(data); // Отправляем содержимое HTML файла
      }
    });
  } else if (parsedUrl.pathname === "/image") {
    // Выдача изображения JPEG
    const imagePath = path.join(__dirname, "image.jpg"); // Путь к изображению
    fs.readFile(imagePath, (err, data) => {
      if (err) {
        res.writeHead(500, { "Content-Type": "text/plain" });
        res.end("Error reading image.\n");
      } else {
        res.writeHead(200, { "Content-Type": "image/jpeg" });
        res.end(data); // Отправляем изображение
      }
    });
  } else if (parsedUrl.pathname === "/json") {
    // Выдача данных в формате JSON
    const jsonData = {
      message: "This is a JSON response",
      success: true,
      data: {
        user: "John Doe",
        age: 30,
      },
    };
    res.writeHead(200, { "Content-Type": "application/json" });
    res.end(JSON.stringify(jsonData)); // Отправляем JSON
  } else {
    // Страница ошибки для несуществующих путей
    res.writeHead(404, { "Content-Type": "text/plain" });
    res.end("404 Not Found\n");
  }
});

const PORT = 3000;
server.listen(PORT, () => {
  console.log(`Server running at http://localhost:${PORT}/`);
});
